#include "clocks.h"


void turnOnHSICLK(uint8_t div){
  /* Enable the Internal High Speed oscillator (HSI, HSIDIV2, HSIDIV4, or HSIDIV8) */
  RCC->CR |= (RCC_CR_HSION | div);

   /* Wait till the divider is set to new value */
   while ((RCC->CR & RCC_CR_HSIDIVF) != RCC_CR_HSIDIVF);

   /* Wait till HSI is ready */
   while ((RCC->CR & RCC_CR_HSIRDY) != RCC_CR_HSIRDY);
}

void turnOffHSICLK() {
  RCC->CR &= ~(RCC_CR_HSION);

   /* Wait till HSI is ready */
   while ((RCC->CR & RCC_CR_HSIRDY) != RCC_CR_HSIRDY);
}

void setHSICLK(uint8_t state, uint8_t div){

  const uint32_t tempSysClkSrc = RCC->CFGR & RCC_CFGR_SWS;
  const uint32_t tempPllckselr = RCC->PLLCKSELR;

  /* Special case:  When the HSI is used as system clock it will not be disabled */
  if ((tempSysClkSrc == RCC_CFGR_SWS_HSI) || ((tempSysClkSrc == RCC_CFGR_SWS_PLL1) && ((tempPllckselr & RCC_PLLCKSELR_PLLSRC) == RCC_PLLCKSELR_PLLSRC_HSI)))
  {
    /* When HSI is used as system clock it will not be disabled */
    if ((RCC->CR & RCC_CR_HSIRDY) && (state == OFF)) {
      stop_cpu;
    }
    /* Otherwise, only HSI division and calibration are allowed */
    else {
      turnOnHSICLK(div);
    }
  }
  else {
    if (state == ON) {
      /* Turn on HSI Clock */
      turnOnHSICLK(div);

      /* Set as main system clock after its ready*/
      RCC->CFGR |= RCC_CFGR_SW_HSI;

    }
    else {
      turnOffHSICLK();
    }

  }
}
