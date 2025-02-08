#include "led.h"

/* LED functions for the NUCLEO-H723ZG */

/* Green LED PB0 */
void setupGreenLed() {
	/* GPIO B */
	RCC->AHB4ENR |= RCC_AHB4ENR_GPIOBEN;

	/* MODER */
	GPIOB->MODER &= ~(GPIO_MODER_MODE0);
	GPIOB->MODER |= (GPIO_MODER_MODE0_0);
	GPIOB->ODR &= ~(GPIO_ODR_OD0);
}

void toggleGreenLed() {
	GPIOB->ODR ^= GPIO_ODR_OD0;
}
void onGreenLed() {
	GPIOB->BSRR = GPIO_BSRR_BS0;
}
void offGreenLed() {
	GPIOB->BSRR = GPIO_BSRR_BR0;
}

/* Yellow LED PE1 */
void setupYellowLed() {
	/* GPIO E */
	RCC->AHB4ENR |= RCC_AHB4ENR_GPIOEEN;

	/* MODER */
	GPIOE->MODER &= ~(GPIO_MODER_MODE1);
	GPIOE->MODER |= (GPIO_MODER_MODE1_0);
}

void toggleYellowLed() {
	GPIOE->ODR ^= GPIO_ODR_OD1;
}

void onYellowLed() {
	GPIOE->BSRR = GPIO_BSRR_BS1;
}

void offYellowLed() {
	GPIOE->BSRR = GPIO_BSRR_BR1;
}

/* Red LED PB14 */
void setupRedLed() {
	/* GPIO B */
	RCC->AHB4ENR |= RCC_AHB4ENR_GPIOBEN;

	/* MODER */
	GPIOB->MODER &= ~(GPIO_MODER_MODE14);
	GPIOB->MODER |= (GPIO_MODER_MODE14_0);
	GPIOB->ODR &= ~(GPIO_ODR_OD14);
}

void toggleRedLed() {
	GPIOB->ODR ^= GPIO_ODR_OD14;
}

void onRedLed() {
	GPIOB->BSRR = GPIO_BSRR_BS14;
}

void offRedLed() {
	GPIOB->BSRR = GPIO_BSRR_BR14;
}


