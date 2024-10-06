#include "scheduler.h"
#include "task_management.h"

extern int running_task_id;
extern struct task_block TASKS[MAX_TASKS];
extern int n_tasks;

/* The following two functions are used to push and pop the extra stack frame in the stack*/
void __attribute__((naked)) store_context(void) {
  __asm__ volatile("mrs r0, msp"); /* Move main stack ptr to r0 */
  __asm__ volatile("stmdb r0!, {r4-r11}"); /* store r4-r11 to address in r0, r0 is modified with final address*/
  __asm__ volatile("msr msp, r0"); /* write the contents of r0 to main stack ptr*/
  __asm__ volatile("bx lr"); /* branch to link-return*/
}

void __attribute__((naked)) restore_context(void) {
  __asm__ volatile("mrs r0, msp"); /* Move main stack ptr to r0 */
  __asm__ volatile("ldmfd r0!, {r4-r11}"); /* Load r4-r11 pointed at r0, r0 is modified with new address*/
  __asm__ volatile("msr msp, r0"); /*Move r0 into main stack ptr */
  __asm__ volatile("bx lr"); /* branch to link-return*/
}

void __attribute__((naked)) PendSV_Handler (void) {

  /* store the current cpus registers r4-r11 */
  store_context();

  /* store the curent main stack ptr to the current task running */
  __asm__ volatile("mrs %0, msp" : "=r"(TASKS[running_task_id].sp));

  /* Change the current running task back to ready */
  TASKS[running_task_id].state = TASK_READY;

  /* Select the next task */
  running_task_id++;
  if (running_task_id >= n_tasks)
    running_task_id = 0;

  /* Change state of the new task selected to running */
  TASKS[running_task_id].state = TASK_RUNNING;

  /* Load the main stack ptr with the value stored in the task block*/
  __asm__ volatile("msr msp, %0"::"r"(TASKS[running_task_id].sp));

  /* restore registers r4-r11 for this task from stack */
  restore_context();

  /* special return value */
  __asm__ volatile("mov lr, %0" ::"r"(0xFFFFFFF9));
  __asm__ volatile("bx lr");

}

void UsageFault_Handler(void){
  while(1);
}

void HardFault_Handler(void){
  while(1);
}
