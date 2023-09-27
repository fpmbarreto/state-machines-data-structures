/*Entry Point*/
ENTRY(Reset_Handler)

/*Memory Layout*/
MEMORY
{
    FLASH(rx):ORIGIN =0x08000000,LENGTH =512K
    SRAM(rwx):ORIGIN =0x20000000,LENGTH =128K
}

_estack = ORIGIN(SRAM)+LENGTH(SRAM)

/*Indicate required heap and stack size*/
__max_heap_size = 0x200
__max_stack_size = 0x400 /*(1024 bytes)*/

/*Sections*/
Sections
{
    .text :
    {
        *(.isr_vector_table)
        *(.text)
        *(.rodata)
    }>FLASH

    .data :
    {
        *(.data)
    }>SRAM AT >FLASH /*>(VMA) AT >(LMA)*/
}