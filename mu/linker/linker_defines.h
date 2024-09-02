#ifndef LINKER_DEFINES
#define LINKER_DEFINES

#include "stm32h7xx.h"

/* Begin address for the initialization values of the .data section
 * defined in the linker script
 * https://stackoverflow.com/questions/8398755/access-symbols-defined-in-the-linker-script-by-application
*/

extern uint32_t _etext;
extern uint32_t _estack;

extern uint32_t _sidata;
extern uint32_t _sdata;
extern uint32_t _edata;

extern uint32_t _sbss;
extern uint32_t _ebss;

/* Work out end of RAM address as initial stack pointer
* (specific of a given STM32 MCU */
#define SRAM_SIZE 		320*1024 /* STM32H72x has 320 */
#define SRAM_END 			(D1_AXISRAM_BASE + SRAM_SIZE)

#endif
