/*
******************************************************************************
**
**   Linker script for STM32H723 series
**   Flash 1024K, multiple SRAM
**
******************************************************************************
*/

/* Entry Point */
ENTRY(Reset_Handler)

/* Memory Areas */
MEMORY
{
  ITCMRAM (xrw)    : ORIGIN = 0x00000000,   LENGTH = 64K
  DTCMRAM (xrw)    : ORIGIN = 0x20000000,   LENGTH = 128K
  FLASH    (rx)    : ORIGIN = 0x08000000,   LENGTH = 1024K
  RAM_D1  (xrw)    : ORIGIN = 0x24000000,   LENGTH = 320K
  RAM_D2  (xrw)    : ORIGIN = 0x30000000,   LENGTH = 32K
  RAM_D3  (xrw)    : ORIGIN = 0x38000000,   LENGTH = 16K
}

/* Highest address of the user mode stack */
_estack = ORIGIN(RAM_D1) + LENGTH(RAM_D1);    /* end of RAM */

/* output sections */
SECTIONS
{
  /* Vector table */
  .isr_vector :
  {
    . = ALIGN(4);
    KEEP(*(.isr_vector))
    . = ALIGN(4);
  } >FLASH

  .text :
  {
    . = ALIGN(4);
    *(.text)           /* .text sections (code) */
    *(.text*)          /* .text* sections (code) */
    . = ALIGN(4);
    _etext = .;
  } >FLASH

  /* Constant data goes into FLASH */
  .rodata :
  {
    . = ALIGN(4);
    *(.rodata)         /* .rodata sections (constants, strings, etc.) */
    *(.rodata*)        /* .rodata* sections (constants, strings, etc.) */
    . = ALIGN(4);
  } >FLASH

  /* Initialized global and static variables (which
  we don't have any in this example) into SRAM */
  /* Used by the startup to initialize data */
  /* this contains the LMA of the data section */
  _sidata = LOADADDR(.data);

  .data : ALIGN(4) {
    . = ALIGN(4);
    _sdata = .; /* create a global symbol at data start */

    *(.data)
    *(.data*)

    . = ALIGN(4);
    _edata = .;
  } > RAM_D1 AT>FLASH

  /* Uninitialized data section */
  . = ALIGN(4);
  .bss (NOLOAD) :
  {
    /* This is used by the startup in order to initialize the .bss section */
    _sbss = .;         /* define a global symbol at bss start */
    _bss_start = _sbss;
    *(.bss*)
    . = ALIGN(4);
    _ebss = .;         /* define a global symbol at bss end */
    _bss_end = _ebss;
  } >RAM_D1

  /DISCARD/ :
  {
    libc.a ( * )
    libm.a ( * )
    libgcc.a ( * )
  }
}

