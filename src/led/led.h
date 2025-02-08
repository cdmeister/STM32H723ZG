#ifndef LED_H
#define LED_H

#include "stm32h7xx.h"


/* LED functions for the NUCLEO-H723ZG */

/* Green LED */
void setupGreenLed();
void toggleGreenLed();
void onGreenLed();
void offGreenLed();

/* Yellow LED */
void setupYellowLed();
void toggleYellowLed();
void onYellowLed();
void offYellowLed();

/* Red LED */
void setupRedLed();
void toggleRedLed();
void onRedLed();
void offRedLed();


#endif /*LED_H*/
