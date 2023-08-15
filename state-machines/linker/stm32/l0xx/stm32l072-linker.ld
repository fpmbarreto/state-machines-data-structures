/*1. Entry Point*/
ENTRY(Reset_Handler)

/*2. Memory definition*/
MEMORY{
    FLASH(rx):ORIGIN = 0x08000000, LENGTH = 192K
    SRAM(wrx):ORIGIN = 0X20000000, LENGTH = 20K
}

/*Linker scipt attributing address*/
_estack = ORIGIN(SRAM) + LENGTH(SRAM);       /*In C would be &_estack = ORIGIN(SRAM) + LENGTH(SRAM)*/ 

/*3. Indicate required heap and stack size (in KB)*/
__max_heap_size = 0xC0; /*FLASH size -- 192 in decimal*/
__max_stack_size = 0x14; /*SRAM size -- 20 in decimal*/

/*Sections*/
SECTIONS{
    /*First section of output file*/
    .text :
    {
        . = ALIGN(4);
        *(.isr_vector_tbl)          /*Merge all (*) .isr_vector_tbl sections of input files*/
        *(.text)                    /*Merge all (*) .text sections of input files*/
        *(.text.*)                  /*Merge all (*) .text. sections*/
        *(.init)
        *(.fini)
        *(.rodata)                  /*Merge all (*) .rodata sections of input files*/
        *(.rodata.*)                /*Merge all (*) .rodata. sections of input files*/
        _etext = .;                 /*Global symbol to hold the address of text section's end*/
        . = ALIGN(4);
    }>FLASH

    _ldata = LOADADDR(.data);
    
    /*Second section of output file*/
    .data :
    {
        . = ALIGN(4);
        _sdata = .;                 /*Global symbol to hold the address of data section's start*/
        *(.data)                    /*Merge all (*) .data sections of input files*/
        *(.data.*)
        _edata = .;                 /*Global symbol to hold the address of data section's end*/
        . = ALIGN(4);
    }>SRAM AT >FLASH /*>(vma) AT >(lma)*/

    /*Third section of output file*/
    .bss :
    {
        . = ALIGN(4);
        _sbss = .;                  /*Global symbol to hold the address of bss section's start*/
        __bss_start__ = _sbss;      /*For package rdimon*/
        *(.bss)                     /*Merge all (*) .bss sections of input files*/
        *(.bss.*)
        . = ALIGN(4);
        _ebss = .;                  /*Global symbol to hold the address of bss section's end*/
        __bss_end__ = _ebss;        /*For package rdimon*/
        __end__ = .;
        end = .;
        _exit = .;
    }>SRAM
}
