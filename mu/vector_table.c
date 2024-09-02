#include "linker_defines.h"

/* This file contains the vector table, weak definitions for ISR and
 * Defautl_Handler definition
 */

/* https://stackoverflow.com/questions/58716887/arm-gcc-weak-alias-redefinition*/

/*******************************************************************************
*
* Provide weak aliases for each Exception handler to the Default_Handler.
* As they are weak aliases, any function with the same name will override
* this definition.
*
*******************************************************************************/
void Default_Handler (void)__attribute__((noreturn));

void Reset_Handler(void) __attribute__((weak,noreturn,alias("Default_Handler")));
void NMI_Handler (void)__attribute__((weak,alias("Default_Handler")));
void HardFault_Handler (void)__attribute__((weak,alias("Default_Handler")));
void MemManage_Handler (void)__attribute__((weak,alias("Default_Handler")));
void BusFault_Handler (void)__attribute__((weak,alias("Default_Handler")));
void UsageFault_Handler (void)__attribute__((weak,alias("Default_Handler")));
void SVC_Handler (void)__attribute__((weak,alias("Default_Handler")));
void DebugMon_Handler (void)__attribute__((weak,alias("Default_Handler")));
void PendSV_Handler (void)__attribute__((weak,alias("Default_Handler")));
void SysTick_Handler (void)__attribute__((weak,alias("Default_Handler")));

/* External Interrupts */
void WWDG_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));                  /* Window WatchDog              */
void PVD_AVD_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));               /* PVD/AVD through EXTI Line detection */
void TAMP_STAMP_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));            /* Tamper and TimeStamps through the EXTI line */
void RTC_WKUP_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));              /* RTC Wakeup through the EXTI line */
void FLASH_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));                 /* FLASH                        */
void RCC_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));                   /* RCC                          */
void EXTI0_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));                 /* EXTI Line0                   */
void EXTI1_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));                 /* EXTI Line1                   */
void EXTI2_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));                 /* EXTI Line2                   */
void EXTI3_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));                 /* EXTI Line3                   */
void EXTI4_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));                 /* EXTI Line4                   */
void DMA1_Stream0_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));          /* DMA1 Stream 0                */
void DMA1_Stream1_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));          /* DMA1 Stream 1                */
void DMA1_Stream2_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));          /* DMA1 Stream 2                */
void DMA1_Stream3_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));          /* DMA1 Stream 3                */
void DMA1_Stream4_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));          /* DMA1 Stream 4                */
void DMA1_Stream5_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));          /* DMA1 Stream 5                */
void DMA1_Stream6_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));          /* DMA1 Stream 6                */
void ADC_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));                   /* ADC1, ADC2 and ADC3s         */
void FDCAN1_IT0_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));            /* FDCAN1 interrupt line 0      */
void FDCAN2_IT0_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));            /* FDCAN2 interrupt line 0      */
void FDCAN1_IT1_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));            /* FDCAN1 interrupt line 1      */
void FDCAN2_IT1_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));            /* FDCAN2 interrupt line 1      */
void EXTI9_5_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));               /* External Line[9:5]s          */
void TIM1_BRK_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));              /* TIM1 Break interrupt         */
void TIM1_UP_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));               /* TIM1 Update interrupt        */
void TIM1_TRG_COM_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));          /* TIM1 Trigger and Commutation interrupt */
void TIM1_CC_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));               /* TIM1 Capture Compare         */
void TIM2_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));                  /* TIM2                         */
void TIM3_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));                  /* TIM3                         */
void TIM4_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));                  /* TIM4                         */
void I2C1_EV_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));               /* I2C1 Event                   */
void I2C1_ER_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));               /* I2C1 Error                   */
void I2C2_EV_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));               /* I2C2 Event                   */
void I2C2_ER_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));               /* I2C2 Error                   */
void SPI1_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));                  /* SPI1                         */
void SPI2_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));                  /* SPI2                         */
void USART1_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));                /* USART1                       */
void USART2_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));                /* USART2                       */
void USART3_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));                /* USART3                       */
void EXTI15_10_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));             /* External Line[15:10]s        */
void RTC_Alarm_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));             /* RTC Alarm (A and B) through EXTI Line */
void TIM8_BRK_TIM12_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));        /* TIM8 Break and TIM12         */
void TIM8_UP_TIM13_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));         /* TIM8 Update and TIM13        */
void TIM8_TRG_COM_TIM14_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));    /* TIM8 Trigger and Commutation and TIM14 */
void TIM8_CC_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));               /* TIM8 Capture Compare         */
void DMA1_Stream7_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));          /* DMA1 Stream7                 */
void FMC_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));                   /* FMC                          */
void SDMMC1_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));                /* SDMMC1                       */
void TIM5_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));                  /* TIM5                         */
void SPI3_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));                  /* SPI3                         */
void UART4_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));                 /* UART4                        */
void UART5_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));                 /* UART5                        */
void TIM6_DAC_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));              /* TIM6 and DAC1&2 underrun errors */
void TIM7_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));                  /* TIM7                         */
void DMA2_Stream0_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));          /* DMA2 Stream 0                */
void DMA2_Stream1_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));          /* DMA2 Stream 1                */
void DMA2_Stream2_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));          /* DMA2 Stream 2                */
void DMA2_Stream3_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));          /* DMA2 Stream 3                */
void DMA2_Stream4_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));          /* DMA2 Stream 4                */
void ETH_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));                   /* Ethernet                     */
void ETH_WKUP_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));              /* Ethernet Wakeup through EXTI line */
void FDCAN_CAL_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));             /* FDCAN calibration unit interrupt*/
void DMA2_Stream5_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));          /* DMA2 Stream 5                */
void DMA2_Stream6_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));          /* DMA2 Stream 6                */
void DMA2_Stream7_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));          /* DMA2 Stream 7                */
void USART6_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));                /* USART6                       */
void I2C3_EV_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));               /* I2C3 event                   */
void I2C3_ER_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));               /* I2C3 error                   */
void OTG_HS_EP1_OUT_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));        /* USB OTG HS End Point 1 Out   */
void OTG_HS_EP1_IN_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));         /* USB OTG HS End Point 1 In    */
void OTG_HS_WKUP_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));           /* USB OTG HS Wakeup through EXTI */
void OTG_HS_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));                /* USB OTG HS                   */
void DCMI_PSSI_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));             /* DCMI, PSSI                   */
void RNG_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));                   /* Rng                          */
void FPU_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));                   /* FPU                          */
void UART7_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));                 /* UART7                        */
void UART8_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));                 /* UART8                        */
void SPI4_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));                  /* SPI4                         */
void SPI5_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));                  /* SPI5                         */
void SPI6_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));                  /* SPI6                         */
void SAI1_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));                  /* SAI1                         */
void LTDC_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));                  /* LTDC                         */
void LTDC_ER_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));               /* LTDC error                   */
void DMA2D_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));                 /* DMA2D                        */
void OCTOSPI1_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));              /* OCTOSPI1                     */
void LPTIM1_IRQHandler(void)__attribute__((weak,alias("Default_Handler")));                 /* LPTIM1                       */
void CEC_IRQHandler(void)__attribute__((weak,alias("Default_Handler")));                    /* HDMI_CEC                     */
void I2C4_EV_IRQHandler(void)__attribute__((weak,alias("Default_Handler")));                /* I2C4 Event                   */
void I2C4_ER_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));               /* I2C4 Error                   */
void SPDIF_RX_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));              /* SPDIF_RX                     */
void DMAMUX1_OVR_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));           /* DMAMUX1 Overrun interrupt    */
void DFSDM1_FLT0_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));           /* DFSDM Filter0 Interrupt      */
void DFSDM1_FLT1_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));           /* DFSDM Filter1 Interrupt      */
void DFSDM1_FLT2_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));           /* DFSDM Filter2 Interrupt      */
void DFSDM1_FLT3_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));           /* DFSDM Filter3 Interrupt      */
void SWPMI1_IRQHandler(void)__attribute__((weak,alias("Default_Handler")));                 /* Serial Wire Interface 1 global interrupt */
void TIM15_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));                 /* TIM15 global Interrupt          */
void TIM16_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));                 /* TIM16 global Interrupt          */
void TIM17_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));                 /* TIM17 global Interrupt          */
void MDIOS_WKUP_IRQHandler(void)__attribute__((weak,alias("Default_Handler")));             /* MDIOS Wakeup  Interrupt         */
void MDIOS_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));                 /* MDIOS global Interrupt          */
void MDMA_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));                  /* MDMA global Interrupt           */
void SDMMC2_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));                /* SDMMC2 global Interrupt         */
void HSEM1_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));                 /* HSEM1 global Interrupt          */
void ADC3_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));                  /* ADC3 global Interrupt           */
void DMAMUX2_OVR_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));           /* DMAMUX Overrun interrupt        */
void BDMA_Channel0_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));         /* BDMA Channel 0 global Interrupt */
void BDMA_Channel1_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));         /* BDMA Channel 1 global Interrupt */
void BDMA_Channel2_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));         /* BDMA Channel 2 global Interrupt */
void BDMA_Channel3_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));         /* BDMA Channel 3 global Interrupt */
void BDMA_Channel4_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));         /* BDMA Channel 4 global Interrupt */
void BDMA_Channel5_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));         /* BDMA Channel 5 global Interrupt */
void BDMA_Channel6_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));         /* BDMA Channel 6 global Interrupt */
void BDMA_Channel7_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));         /* BDMA Channel 7 global Interrupt */
void COMP1_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));                 /* COMP1 global Interrupt          */
void LPTIM2_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));                /* LP TIM2 global interrupt        */
void LPTIM3_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));                /* LP TIM3 global interrupt        */
void LPTIM4_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));                /* LP TIM4 global interrupt        */
void LPTIM5_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));                /* LP TIM5 global interrupt        */
void LPUART1_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));               /* LP UART1 interrupt              */
void CRS_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));                   /* Clock Recovery Global Interrupt */
void ECC_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));                   /* ECC diagnostic Global Interrupt */
void SAI4_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));                  /* SAI4 global interrupt           */
void DTS_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));                   /* Digital Temperature Sensor  interrupt */
void WAKEUP_PIN_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));            /* Interrupt for all 6 wake-up pins      */
void OCTOSPI2_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));              /* OCTOSPI2 Interrupt       */
void FMAC_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));                  /* FMAC Interrupt           */
void CORDIC_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));                /* CORDIC Interrupt         */
void UART9_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));                 /* UART9 Interrupt          */
void USART10_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));               /* UART10 Interrupt         */
void I2C5_EV_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));               /* I2C5 Event Interrupt     */
void I2C5_ER_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));               /* I2C5 Error Interrupt     */
void FDCAN3_IT0_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));            /* FDCAN3 interrupt line 0  */
void FDCAN3_IT1_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));            /* FDCAN3 interrupt line 1  */
void TIM23_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));                 /* TIM23 global interrupt   */
void TIM24_IRQHandler (void)__attribute__((weak,alias("Default_Handler")));                 /* TIM24 global interrupt   */




void (* const vector_table[])(void) __attribute__((section(".isr_vector"))) = {
  /* Initial Stack Location */
  (void (*)(void))SRAM_END,
  /* System Exceptions */
  Reset_Handler,
  NMI_Handler,
  HardFault_Handler,
  MemManage_Handler,
  BusFault_Handler,
  UsageFault_Handler,
  0,
  0,
  0,
  0,
  SVC_Handler,
  DebugMon_Handler,
  0,
  PendSV_Handler,
  SysTick_Handler,

  /* External Interrupts */
  WWDG_IRQHandler,                   /* Window WatchDog              */
  PVD_AVD_IRQHandler,                /* PVD/AVD through EXTI Line detection */
  TAMP_STAMP_IRQHandler,             /* Tamper and TimeStamps through the EXTI line */
  RTC_WKUP_IRQHandler,               /* RTC Wakeup through the EXTI line */
  FLASH_IRQHandler,                  /* FLASH                        */
  RCC_IRQHandler,                    /* RCC                          */
  EXTI0_IRQHandler,                  /* EXTI Line0                   */
  EXTI1_IRQHandler,                  /* EXTI Line1                   */
  EXTI2_IRQHandler,                  /* EXTI Line2                   */
  EXTI3_IRQHandler,                  /* EXTI Line3                   */
  EXTI4_IRQHandler,                  /* EXTI Line4                   */
  DMA1_Stream0_IRQHandler,           /* DMA1 Stream 0                */
  DMA1_Stream1_IRQHandler,           /* DMA1 Stream 1                */
  DMA1_Stream2_IRQHandler,           /* DMA1 Stream 2                */
  DMA1_Stream3_IRQHandler,           /* DMA1 Stream 3                */
  DMA1_Stream4_IRQHandler,           /* DMA1 Stream 4                */
  DMA1_Stream5_IRQHandler,           /* DMA1 Stream 5                */
  DMA1_Stream6_IRQHandler,           /* DMA1 Stream 6                */
  ADC_IRQHandler,                    /* ADC1, ADC2 and ADC3s         */
  FDCAN1_IT0_IRQHandler,             /* FDCAN1 interrupt line 0      */
  FDCAN2_IT0_IRQHandler,             /* FDCAN2 interrupt line 0      */
  FDCAN1_IT1_IRQHandler,             /* FDCAN1 interrupt line 1      */
  FDCAN2_IT1_IRQHandler,             /* FDCAN2 interrupt line 1      */
  EXTI9_5_IRQHandler,                /* External Line[9:5]s          */
  TIM1_BRK_IRQHandler,               /* TIM1 Break interrupt         */
  TIM1_UP_IRQHandler,                /* TIM1 Update interrupt        */
  TIM1_TRG_COM_IRQHandler,           /* TIM1 Trigger and Commutation interrupt */
  TIM1_CC_IRQHandler,                /* TIM1 Capture Compare         */
  TIM2_IRQHandler,                   /* TIM2                         */
  TIM3_IRQHandler,                   /* TIM3                         */
  TIM4_IRQHandler,                   /* TIM4                         */
  I2C1_EV_IRQHandler,                /* I2C1 Event                   */
  I2C1_ER_IRQHandler,                /* I2C1 Error                   */
  I2C2_EV_IRQHandler,                /* I2C2 Event                   */
  I2C2_ER_IRQHandler,                /* I2C2 Error                   */
  SPI1_IRQHandler,                   /* SPI1                         */
  SPI2_IRQHandler,                   /* SPI2                         */
  USART1_IRQHandler,                 /* USART1                       */
  USART2_IRQHandler,                 /* USART2                       */
  USART3_IRQHandler,                 /* USART3                       */
  EXTI15_10_IRQHandler,              /* External Line[15:10]s        */
  RTC_Alarm_IRQHandler,              /* RTC Alarm (A and B) through EXTI Line */
  0,                                 /* Reserved                     */
  TIM8_BRK_TIM12_IRQHandler,         /* TIM8 Break and TIM12         */
  TIM8_UP_TIM13_IRQHandler,          /* TIM8 Update and TIM13        */
  TIM8_TRG_COM_TIM14_IRQHandler,     /* TIM8 Trigger and Commutation and TIM14 */
  TIM8_CC_IRQHandler,                /* TIM8 Capture Compare         */
  DMA1_Stream7_IRQHandler,           /* DMA1 Stream7                 */
  FMC_IRQHandler,                    /* FMC                          */
  SDMMC1_IRQHandler,                 /* SDMMC1                       */
  TIM5_IRQHandler,                   /* TIM5                         */
  SPI3_IRQHandler,                   /* SPI3                         */
  UART4_IRQHandler,                  /* UART4                        */
  UART5_IRQHandler,                  /* UART5                        */
  TIM6_DAC_IRQHandler,               /* TIM6 and DAC1&2 underrun errors */
  TIM7_IRQHandler,                   /* TIM7                         */
  DMA2_Stream0_IRQHandler,           /* DMA2 Stream 0                */
  DMA2_Stream1_IRQHandler,           /* DMA2 Stream 1                */
  DMA2_Stream2_IRQHandler,           /* DMA2 Stream 2                */
  DMA2_Stream3_IRQHandler,           /* DMA2 Stream 3                */
  DMA2_Stream4_IRQHandler,           /* DMA2 Stream 4                */
  ETH_IRQHandler,                    /* Ethernet                     */
  ETH_WKUP_IRQHandler,               /* Ethernet Wakeup through EXTI line */
  FDCAN_CAL_IRQHandler,              /* FDCAN calibration unit interrupt*/
  0,                                 /* Reserved                     */
  0,                                 /* Reserved                     */
  0,                                 /* Reserved                     */
  0,                                 /* Reserved                     */
  DMA2_Stream5_IRQHandler,           /* DMA2 Stream 5                */
  DMA2_Stream6_IRQHandler,           /* DMA2 Stream 6                */
  DMA2_Stream7_IRQHandler,           /* DMA2 Stream 7                */
  USART6_IRQHandler,                 /* USART6                       */
  I2C3_EV_IRQHandler,                /* I2C3 event                   */
  I2C3_ER_IRQHandler,                /* I2C3 error                   */
  OTG_HS_EP1_OUT_IRQHandler,         /* USB OTG HS End Point 1 Out   */
  OTG_HS_EP1_IN_IRQHandler,          /* USB OTG HS End Point 1 In    */
  OTG_HS_WKUP_IRQHandler,            /* USB OTG HS Wakeup through EXTI */
  OTG_HS_IRQHandler,                 /* USB OTG HS                   */
  DCMI_PSSI_IRQHandler,              /* DCMI, PSSI                   */
  0,                                 /* Reserved                     */
  RNG_IRQHandler,                    /* Rng                          */
  FPU_IRQHandler,                    /* FPU                          */
  UART7_IRQHandler,                  /* UART7                        */
  UART8_IRQHandler,                  /* UART8                        */
  SPI4_IRQHandler,                   /* SPI4                         */
  SPI5_IRQHandler,                   /* SPI5                         */
  SPI6_IRQHandler,                   /* SPI6                         */
  SAI1_IRQHandler,                   /* SAI1                         */
  LTDC_IRQHandler,                   /* LTDC                         */
  LTDC_ER_IRQHandler,                /* LTDC error                   */
  DMA2D_IRQHandler,                  /* DMA2D                        */
  0,                                 /* Reserved                     */
  OCTOSPI1_IRQHandler,               /* OCTOSPI1                     */
  LPTIM1_IRQHandler,                 /* LPTIM1                       */
  CEC_IRQHandler,                    /* HDMI_CEC                     */
  I2C4_EV_IRQHandler,                /* I2C4 Event                   */
  I2C4_ER_IRQHandler,                /* I2C4 Error                   */
  SPDIF_RX_IRQHandler,               /* SPDIF_RX                     */
  0,                                 /* Reserved                     */
  0,                                 /* Reserved                     */
  0,                                 /* Reserved                     */
  0,                                 /* Reserved                     */
  DMAMUX1_OVR_IRQHandler,            /* DMAMUX1 Overrun interrupt    */
  0,                                 /* Reserved                     */
  0,                                 /* Reserved                     */
  0,                                 /* Reserved                     */
  0,                                 /* Reserved                     */
  0,                                 /* Reserved                     */
  0,                                 /* Reserved                     */
  0,                                 /* Reserved                     */
  DFSDM1_FLT0_IRQHandler,            /* DFSDM Filter0 Interrupt      */
  DFSDM1_FLT1_IRQHandler,            /* DFSDM Filter1 Interrupt      */
  DFSDM1_FLT2_IRQHandler,            /* DFSDM Filter2 Interrupt      */
  DFSDM1_FLT3_IRQHandler,            /* DFSDM Filter3 Interrupt      */
  0,                                 /* Reserved                     */
  SWPMI1_IRQHandler,                 /* Serial Wire Interface 1 global interrupt */
  TIM15_IRQHandler,                  /* TIM15 global Interrupt          */
  TIM16_IRQHandler,                  /* TIM16 global Interrupt          */
  TIM17_IRQHandler,                  /* TIM17 global Interrupt          */
  MDIOS_WKUP_IRQHandler,             /* MDIOS Wakeup  Interrupt         */
  MDIOS_IRQHandler,                  /* MDIOS global Interrupt          */
  0,                                 /* Reserved                        */
  MDMA_IRQHandler,                   /* MDMA global Interrupt           */
  0,                                 /* Reserved                        */
  SDMMC2_IRQHandler,                 /* SDMMC2 global Interrupt         */
  HSEM1_IRQHandler,                  /* HSEM1 global Interrupt          */
  0,                                 /* Reserved                        */
  ADC3_IRQHandler,                   /* ADC3 global Interrupt           */
  DMAMUX2_OVR_IRQHandler,            /* DMAMUX Overrun interrupt        */
  BDMA_Channel0_IRQHandler,          /* BDMA Channel 0 global Interrupt */
  BDMA_Channel1_IRQHandler,          /* BDMA Channel 1 global Interrupt */
  BDMA_Channel2_IRQHandler,          /* BDMA Channel 2 global Interrupt */
  BDMA_Channel3_IRQHandler,          /* BDMA Channel 3 global Interrupt */
  BDMA_Channel4_IRQHandler,          /* BDMA Channel 4 global Interrupt */
  BDMA_Channel5_IRQHandler,          /* BDMA Channel 5 global Interrupt */
  BDMA_Channel6_IRQHandler,          /* BDMA Channel 6 global Interrupt */
  BDMA_Channel7_IRQHandler,          /* BDMA Channel 7 global Interrupt */
  COMP1_IRQHandler,                  /* COMP1 global Interrupt          */
  LPTIM2_IRQHandler,                 /* LP TIM2 global interrupt        */
  LPTIM3_IRQHandler,                 /* LP TIM3 global interrupt        */
  LPTIM4_IRQHandler,                 /* LP TIM4 global interrupt        */
  LPTIM5_IRQHandler,                 /* LP TIM5 global interrupt        */
  LPUART1_IRQHandler,                /* LP UART1 interrupt              */
  0,                                 /* Reserved                        */
  CRS_IRQHandler,                    /* Clock Recovery Global Interrupt */
  ECC_IRQHandler,                    /* ECC diagnostic Global Interrupt */
  SAI4_IRQHandler,                   /* SAI4 global interrupt           */
  DTS_IRQHandler,                    /* Digital Temperature Sensor  interrupt */
  0,                                 /* Reserved                              */
  WAKEUP_PIN_IRQHandler,             /* Interrupt for all 6 wake-up pins      */
  OCTOSPI2_IRQHandler,               /* OCTOSPI2 Interrupt       */
  0,                                 /* Reserved                 */
  0,                                 /*, Reserved                 */
  FMAC_IRQHandler,                   /* FMAC Interrupt           */
  CORDIC_IRQHandler,                 /* CORDIC Interrupt         */
  UART9_IRQHandler,                  /* UART9 Interrupt          */
  USART10_IRQHandler,                /* UART10 Interrupt         */
  I2C5_EV_IRQHandler,                /* I2C5 Event Interrupt     */
  I2C5_ER_IRQHandler,                /* I2C5 Error Interrupt     */
  FDCAN3_IT0_IRQHandler,             /* FDCAN3 interrupt line 0  */
  FDCAN3_IT1_IRQHandler,             /* FDCAN3 interrupt line 1  */
  TIM23_IRQHandler,                  /* TIM23 global interrupt   */
  TIM24_IRQHandler                   /* TIM24 global interrupt   */
};


/*----------------------------------------------------------------------------
  Default Handler for Exceptions / Interrupts
 *----------------------------------------------------------------------------*/
void Default_Handler(void)
{
  while(1);
}
