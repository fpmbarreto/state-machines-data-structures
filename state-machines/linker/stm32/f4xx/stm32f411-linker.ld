/*Entry Point*/
ENTRY(Reset_Handler)

/*Memory Layout*/
MEMORY
{
    FLASH(rx):ORIGIN =0x08000000,LENGTH =512K
    SRAM(rwx):ORIGIN =0x20000000,LENGTH =128K
}

_stackptr = ORIGIN(SRAM)+LENGTH(SRAM);

/*Indicate required heap and stack size*/
__max_heap_size = 0x200;
__max_stack_size = 0x400; /*(1024 bytes)*/

/*Sections*/
SECTIONS
{
    .text :
    {
        . = ALIGN(4);
        *(.isr_vector_table)
        *(.text*)
        *(.rodata*)
        . = ALIGN(4);
        _etext = .;
    }>FLASH

    .data :
    {
        . = ALIGN(4);
        _sdata = .;
        *(.data*)
        . = ALIGN(4);
        _edata = .;
    }>SRAM AT >FLASH /*>(VMA) AT >(LMA)*/

    .bss :
    {
        . = ALIGN(4);
        __bss_start__ = .;
        *(.bss*)
        . = ALIGN(4);
        __bss_end__ = .;
    }
    __end__ = .;
    end = __end__;
}