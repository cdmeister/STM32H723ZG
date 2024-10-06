#include "stm32h7xx.h"
#include "startup.h"
#include "systick.h"
#include "scheduler.h"
#include "task_management.h"



extern struct task_block TASKS[MAX_TASKS];
#define kernel TASKS[0]

void delay(uint32_t count);


void task_test0(void *arg) {
  uint32_t now = millis();
  GPIOB->ODR = 0x400;
  while(1) {
    if ((millis() - now) > 1000) {
      GPIOB->ODR = 0x000;
      schedule();
      now = millis();
      GPIOB->ODR = 0x400;
    }
  }
}

void task_test1(void *arg) {
  uint32_t now = milliseconds;
	GPIOE->ODR = 0x2;
  while(1) {
    if ((milliseconds - now) > 100) {
	    GPIOE->ODR = 0x0;
      schedule();
      now = milliseconds;
	    GPIOE->ODR = 0x2;
    }
  }
}

int main() {

   RCC->AHB2ENR |= (RCC_AHB2ENR_D2SRAM1EN | RCC_AHB2ENR_D2SRAM2EN);
	/* Enable clock on GPIOB GPIOE peripheral */
	RCC->AHB4ENR = 0x12;

	/* Configure the PA5 as output pull-up */
	GPIOE->MODER &= 0x4; // Sets MODER[11:10] = 0x1
  GPIOB->MODER &= 0x4;

	systick_config(SystemCoreClock/1000);

	kernel.name[0] = 0;
  kernel.id = 0;
  kernel.state = TASK_RUNNING;
  //task_create("test0",task_test0, NULL);
  task_create("test1",task_test1, NULL);
  while(1) {
    schedule();
  }
}

