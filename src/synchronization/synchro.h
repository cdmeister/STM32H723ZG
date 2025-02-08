#ifndef SYNCHRO_H
#define SYNCHRO_H

#include "stm32h7xx.h"
#include "cmsis_gcc.h"

#define LOCKED    1
#define UNLOCKED  0

#define EX_INSTR_FAILED 1
#define EX_INSTR_PASSED 0

typedef struct mutex {
  uint32_t lock;
} mutex;

typedef struct semaphore {
  uint32_t lock;
  uint32_t listeners;
} semaphore;

void initMutex(volatile mutex * lock);
void getMutex(volatile mutex * lock);
void freeMutex(volatile mutex * lock);



#endif /* SYNCHRO_H */
