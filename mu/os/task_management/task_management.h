/*
* Task managements
*
*
*/

#ifndef TASK_MANAGEMENT
#define TASK_MANAGEMENT

#include "linker_defines.h"
#include "systick.h"

/* Stack size for each tas in four-byte words */
#define STACK_SIZE (256)

/* MAX tasks executing in a system */
#define MAX_TASKS     8

/* Task States */
#define TASK_WAITING  0
#define TASK_READY    1
#define TASK_RUNNING  2
#define TASK_NAME_MAXLEN  16

/* Task Block Struct */
/* Structure that represents the state of a task*/
struct task_block {
  char name[TASK_NAME_MAXLEN];
  int id;
  int state;
  void (*start) (void *arg);
  void *arg;
  uint8_t *sp;
  uint32_t wakeup_time;
  struct task_block *next;
};

/* CPU Registers that would be pushed onto the stack by hardware */
struct stack_frame {
  uint32_t r0, r1, r2, r3, r12, lr, pc, xpsr;
};

/* CPU Registers that would be pushed onto the stack via extra software */
struct extra_frame {
  uint32_t r4, r5, r6, r7, r8, r9, r10, r11;
};

/* This higher level function creates the task for the function,
 * allocates stack space, sets to ready
 */
struct task_block *task_create(char *name, void (*start)(void *arg), void *arg);
struct task_block *tasklist_next_ready(struct task_block *t);
void tasklist_add(struct task_block **list, struct task_block *addme);
int tasklist_del(struct task_block **list, struct task_block *delme);
void task_waiting(struct task_block *t);
void task_ready(struct task_block *t);


#endif
