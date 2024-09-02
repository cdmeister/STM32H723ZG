#include "stm32h7xx.h"
#include "startup.h"
#include "systick.h"

void delay(uint32_t count);

int main() {

	/* Enable clock on GPIOE peripheral */
	RCC->AHB4ENR = 0x10;

	/* Configure the PA5 as output pull-up */
	GPIOE->MODER &= 0x4; // Sets MODER[11:10] = 0x1

	systick_config(SystemCoreClock/1000);

	while(1) {
		GPIOE->ODR = 0x2;
		Delay(100);
		GPIOE->ODR = 0x0;
		Delay(100);
	}

}

