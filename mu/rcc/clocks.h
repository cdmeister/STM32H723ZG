#ifndef CLOCKS_H
#define CLOCKS_H

#include "stm32h723xx.h"
#include "os_tasks.h"

#define OFF 0
#define ON 1

void setHSICLK(uint8_t state, uint8_t div);
void turnOnHSICLK(uint8_t div);
void turnOffHSICLK();




#endif /*CLOCKS_H*/
