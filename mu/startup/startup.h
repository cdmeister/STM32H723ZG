#ifndef STARTUP_H
#define STARTUP_H

#include "stm32h7xx.h"

extern uint32_t SystemCoreClock;

/**
  * @brief  Setup the microcontroller system
  *         Initialize the FPU setting, vector table location and External memory
  *         configuration.
  * @param  None
  * @retval None
  */

void _initialize_data(uint32_t * flash_begin, uint32_t * data_begin,
                      uint32_t * data_end);

/**
  * @brief  Setup the microcontroller system
  *         Initialize the FPU setting, vector table location and External memory
  *         configuration.
  * @param  None
  * @retval None
  */

void _initialize_bss(uint32_t * bss_begin, uint32_t * bss_end);

/**
  * @brief  Setup the microcontroller system
  *         Initialize the FPU setting and  vector table location
  *         configuration.
  * @param  None
  * @retval None
  */
void SystemInit (void);

#endif
