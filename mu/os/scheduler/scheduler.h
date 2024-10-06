/*
* Scheduler Internal Mechanisms
*
*
*/

#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "linker_defines.h"

#define SCB_ICSR (*((volatile uint32_t *)0xE000ED04))
#define schedule() SCB_ICSR |= (1 << 28)

#endif
