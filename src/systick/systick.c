#include "stm32h7xx.h"
#include "systick.h"

volatile uint32_t TimeDelay;
volatile uint32_t milliseconds;

void systick_config(uint32_t reload) {

	/*Disable SysTick IRQ and SysTick counter*/
  SysTick->CTRL = 0;

  /* Set reload register */
  SysTick->LOAD = reload - 1;

  /* Set interrupt priority of SysTick*/
  /* Make SysTick Least urgent(i.ie., highest priority number) */
  /* __NVIC_PRIO_BITS: number of bits for priority levels, defined in CMSIS */
  NVIC_SetPriority(SysTick_IRQn, (1<<__NVIC_PRIO_BITS) -1);

  /* Reset the SysTick counter value*/
  SysTick->VAL = 0;

  /* Select Processor Cycle */
  /* 1 = processor clock; 0 = external clock */
  SysTick->CTRL |= SysTick_CTRL_CLKSOURCE_Msk;

  /*  Enables SysTick exception request */
  /*  1 = counting down to zero asserts the SysTick exception request */
  /*  0 = counting down to zero does not assert the SysTick exception request*/
  SysTick->CTRL |= SysTick_CTRL_TICKINT_Msk;

  /* Enable SysTick Timer */
  SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
}


void Delay(uint32_t nTime) {
  TimeDelay = nTime;
  while(TimeDelay !=0);
}
uint32_t millis() {
  return milliseconds;
}
void SysTick_Handler(void){
  milliseconds++;
  if (TimeDelay > 0)
    TimeDelay--;
}

