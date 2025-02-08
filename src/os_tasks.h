#ifndef OS_TASKS
#define OS_TASKS

#include "led.h"
#include "systick.h"
#include "startup.h"
#include "synchro.h"

/* Stringify */
#define STR1(x) #x
#define STR(x) STR1(x)

#define stop_cpu __asm__ __volatile__ ("bkpt #0");
#define SVC(x) __asm__ volatile("svc #" STR1(x))


// Stack for each task (8kb each - 1024 x 8 bytes)
extern long long task0_stack[1024], task1_stack[1024], task2_stack[1024];

extern uint32_t curr_task; // Current Task
extern uint32_t next_task; // Next task
extern uint32_t PSP_array[3]; // Process Stack Pointer for each task
extern uint32_t svc_exc_return; /* EXC_RETURN used by SVC */
extern volatile mutex  mutex_led;

void LED_Initializer(void);
void task0 (void);
void task1 (void);
void task2 (void);

/* OS Initialization */
#define os_start(void) SVC(0);
void SVC_Handler_C(unsigned int * svc_args);

#endif /* OS_TASKS */
