#ifndef SYSTICK_H
#define SYSTICK_H

extern volatile uint32_t TimeDelay;
extern volatile uint32_t milliseconds;

void Delay(uint32_t nTime);
uint32_t millis();
void SysTick_Handler(void);
void systick_config(uint32_t reload);


#endif
