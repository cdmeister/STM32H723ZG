#include "os_tasks.h"

// Stack for each task (8kb each - 1024 x 8 bytes)
long long task0_stack[1024], task1_stack[1024], task2_stack[1024];

uint32_t curr_task = 0; // Current Task
uint32_t next_task = 1; // Next task
uint32_t PSP_array[3]; // Process Stack Pointer for each task
uint32_t svc_exc_return; /* EXC_RETURN used by SVC */
volatile mutex mutex_led;

void LED_Initializer(void) {
	initMutex(&mutex_led);
	setupGreenLed();
	setupYellowLed();
	setupRedLed();
	return;
}

void task0 (void){
	while(1){
		if (systick_count & 0x200){
			onGreenLed();
		}
		else {
			offGreenLed();
		}

	}
}

void task1 (void) {
	while(1){
		if (systick_count & 0x400){
			onYellowLed();
		}
		else {
			offYellowLed();
		}
	}
}

void task2 (void) {
	while(1){
		if (systick_count & 0x600){
			onRedLed();
		}
		else {
			offRedLed();
		}

	}
}

void __attribute__((naked)) SVC_Handler(void) {

	/* Extract stack frame location */
	__asm__ volatile("TST LR, #4");
	__asm__ volatile("ITE EQ");
	__asm__ volatile("MRSEQ R0, MSP");
	__asm__ volatile("MRSNE R0, PSP");

	/*Save current EXE_RETURN */
	__asm__ volatile("LDR R1,=svc_exc_return");
	__asm__ volatile("STR LR,[R1]");

	/* Run C part of SVC_Handler */
	__asm__ volatile("BL SVC_Handler_C");

	/* Load new EXE_RETURN */
	__asm__ volatile("LDR R1,=svc_exc_return");
	__asm__ volatile("LDR LR,[R1]");
	__asm__ volatile("BX LR");
}

void SVC_Handler_C(unsigned int * svc_args){
	uint8_t svc_number;
	svc_number = ((char *) svc_args[6])[-2];

	switch(svc_number) {
		case (0): /* OS Init */
			/* Starting the task scheduler */
			/* Create stack frame for Task 0 */
			PSP_array[0] = ((unsigned int) task0_stack) + sizeof(task0_stack) - 18*4;
			*((volatile unsigned long *)(PSP_array[0] + (16<<2))) = (unsigned long) task0;
			/* Initial Program counter */
			*((volatile unsigned long *)(PSP_array[0] + (17<<2))) = 0x01000000; // initial xPSR
			*((volatile unsigned long *)(PSP_array[0]          )) = 0xFFFFFFFDUL; // initial EXE_RETURN
			*((volatile unsigned long *)(PSP_array[0] + (1 << 2))) = 0x3; // initial CONTROL: unpriviledge, PSP, No FP

			/* Create stack frame for Task 1 */
			PSP_array[1] = ((unsigned int) task1_stack) + sizeof(task1_stack) - 18*4;
			*((volatile unsigned long *)(PSP_array[1] + (16<<2))) = (unsigned long) task1;
			/* Initial Program counter */
			*((volatile unsigned long *)(PSP_array[1] + (17<<2))) = 0x01000000; // initial xPSR
			*((volatile unsigned long *)(PSP_array[1]          )) = 0xFFFFFFFDUL; // initial EXE_RETURN
			*((volatile unsigned long *)(PSP_array[1] + (1 << 2))) = 0x3; // initial CONTROL: unpriviledge, PSP, No FP

			/* Create stack frame for Task 1 */
			PSP_array[2] = ((unsigned int) task2_stack) + sizeof(task2_stack) - 18*4;
			*((volatile unsigned long *)(PSP_array[2] + (16<<2))) = (unsigned long) task2;
			/* Initial Program counter */
			*((volatile unsigned long *)(PSP_array[2] + (17<<2))) = 0x01000000; // initial xPSR
			*((volatile unsigned long *)(PSP_array[2]          )) = 0xFFFFFFFDUL; // initial EXE_RETURN
			*((volatile unsigned long *)(PSP_array[2] + (1 << 2))) = 0x3; // initial CONTROL: unpriviledge, PSP, No FP


			/* Siwtch to task #0 (current task) */
			curr_task = 0;
			svc_exc_return = *((volatile unsigned long *)(PSP_array[curr_task]));

			/* Return to thread with PSP */
			/* Set PSP to @R0 in task 0 stack frame */
			__set_PSP((PSP_array[curr_task]+10*4));

			/* Set PendSV to lowest possible priority */
			NVIC_SetPriority(PendSV_IRQn, 0xFF);

			/* 1000 Hz SysTick Interupt */
			systick_config(SystemCoreClock/1000);

			/* Switch to use Process Stack, unprivileged state */
			__set_CONTROL(0x3);

			break;

		default:
			stop_cpu;
			break;
	}
}

/* Context Switching code */
void __attribute__((naked)) PendSV_Handler(void) {
	/*----Save Current Context-------*/
	/* Get Current Process stack pointer value*/
	__asm__ volatile("MRS 		R0, PSP\n");

	/* Test bit 4, If zero, need to stack floating point regs */
	__asm__ volatile("TST LR, 0x10\n");
	__asm__ volatile("IT	EQ\n");
	/* Save the floating point regs */
	__asm__ volatile("VSTMDBEQ R0!, {S16-S31}\n");

	__asm__ volatile("MOV	R2, LR");
	__asm__ volatile("MRS	R3, CONTROL");
	/* Save LR, CONTROL and R2 to R11 in task stack (10 regs) */
	__asm__ volatile("STMDB R0!, {R2-R11}");

	/* Get current task */
	__asm__ volatile("LDR		R1,=curr_task\n");
	__asm__ volatile("LDR		R2,[R1]\n");

	/* Save PSP Value into PSP_array */
	__asm__ volatile("LDR		R3,=PSP_array\n");
	__asm__ volatile("STR 	R0,[R3, R2, LSL #2]");

	/*----Load Current Context-------*/
	/* Get next task ID */
	__asm__ volatile("LDR		R4,=next_task\n");
	__asm__ volatile("LDR		R4,[R4]\n");

	/* Set curr_task = next_task */
	__asm__ volatile("STR 	R4,[R1]\n");

	/* Load PSP value from PSP_array */
	__asm__ volatile("LDR 	R0,[R3, R4, LSL #2]");

	/* Load LR, CONTROl and R2 to R11 ffrom task stack (10 registers) */
	__asm__ volatile("LDMIA	R0!, {R2-R11}") ;

	__asm__ volatile("MOV LR, R2");
	__asm__ volatile("MSR CONTROL, R3");
	__asm__ volatile("ISB");

	/* Test bit 4, If zero, need to unstack floating point regs */
	__asm__ volatile("TST LR, #0x10");
	__asm__ volatile("IT EQ");

	/* Load Floating Point Registers */
	__asm__ volatile("VLDMIAEQ R0!, {S16-S31}\n");

	/* Set PSP to next task */
	__asm__ volatile("MSR PSP, R0");

	/* Return */
	__asm__ volatile("BX	LR");
}
