#include "task_management.h"

extern void Default_Handler(void);

struct task_block TASKS[MAX_TASKS];
int n_tasks = 1;
int running_task_id = 0;

struct task_block * tasklist_active = NULL;
struct task_block * tasklist_waiting = NULL;
struct task_block *t_cur = &TASKS[0];

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
  tasklist_add(&tasklist_active, t);

  return t;
}

/* Insert a new node to beginning of the list */
void tasklist_add(struct task_block **list, struct task_block *addme){

  addme->next = *list;
  *list = addme;
}

/* delete a node from the list */
int tasklist_del(struct task_block **list, struct task_block *delme){

  struct task_block * prev = NULL;
  struct task_block * current = *list;

  while (current){
    if (current == delme) {
      if(prev == NULL){
        *list = current->next;
      }
      else {
        prev->next = current->next;
      }
      return 0;
    }

    prev = current;
    current = current->next;
  }

  return -1;
}

void task_waiting(struct task_block *t)
{
  if (tasklist_del(&tasklist_active, t) == 0) {
    tasklist_add(&tasklist_waiting, t);
    t->state = TASK_WAITING;
  }
}

void task_ready(struct task_block *t)
{
  if (tasklist_del(&tasklist_waiting, t) == 0) {
    tasklist_add(&tasklist_active, t);
    t->state = TASK_READY;
  }
}

struct task_block *tasklist_next_ready(struct task_block *t)
{
  if ((t->next == NULL) || (t->next->state != TASK_READY))
    return tasklist_active;
  return t->next;
}


