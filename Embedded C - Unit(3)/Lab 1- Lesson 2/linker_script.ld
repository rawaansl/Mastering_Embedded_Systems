ENTRY(reset)
MEMORY
{
	Mem (rwx): ORIGIN = 0X00000000  ,LENGTH = 64M
}
	

SECTIONS
{
    . = 0x10000;
    .startup . :
    { 
        startup.o(.text)
    } > Mem

    .text :
    {
        *(.text) *(.rodata)
    } > Mem

    .data :
    {
        *(.data)
    } > Mem

    .bss :
    {
        *(.bss)
    } > Mem

    . = . + 0x1000; /* Move the location counter by 0x1000 bytes */

    /* Define stack_top as the current address */
    PROVIDE(stack_top = .);
}
