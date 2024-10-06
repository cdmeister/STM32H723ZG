#include "task_management.h"

extern void Default_Handler(void);

struct task_block TASKS[MAX_TASKS];
int n_tasks = 1;
int running_task_id = 0;

static void task_stack_init(struct task_block *t) {
  struct stack_frame *tf;
  t->sp -= sizeof(struct stack_frame);
  tf = (struct stack_frame *)(t->sp);
  tf->r0 = (uint32_t) t->arg;
  tf->pc = (uint32_t) t->start;
  tf->lr = (uint32_t) Default_Handler;
  tf->xpsr = (1 << 24);
  t->sp -= sizeof(struct extra_frame);
}

/* This higher level function creates the task for the function,
 * allocates stack space, sets to ready
 */
struct task_block *task_create(char *name, void (*start)(void *arg), void *arg)
{
  struct task_block *t;
  int i;
  if (n_tasks >= MAX_TASKS)
    return NULL;

  /* Grab address of the next available task */
  t = &TASKS[n_tasks];

  /* Set the id of the task */
  t->id = n_tasks++;

  /* set the name */
  for (i = 0; i < TASK_NAME_MAXLEN; i++) {
    t->name[i] = name[i];
    if (name[i] == 0) break;
  }

  t->state = TASK_READY;
  t->start = start;
  t->arg = arg;
  t->sp = (uint8_t*)((&_os_stack_start) + n_tasks * STACK_SIZE);
  task_stack_init(t);

  return t;
}


