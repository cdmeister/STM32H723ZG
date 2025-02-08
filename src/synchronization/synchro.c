#include "synchro.h"

void initMutex(volatile mutex * lock){
  lock->lock = UNLOCKED;
  return;
}

void getMutex(volatile mutex * lock){
  int status;
  do {
    while (__LDREXW(&lock->lock) != UNLOCKED);
    status = __STREXW(LOCKED, &lock->lock);
  } while (status != EX_INSTR_PASSED);
  __DMB();
  return;
}

void freeMutex(volatile mutex * lock) {
  __DMB();
  lock->lock = UNLOCKED;
  return;
}

