/********************************************
 * Linker Script - Cortex-M3 Processor
 * Author: Rawan Sleem
 *
 * Description:
 * This linker script defines the memory layout
 * for the Cortex-M3 microcontroller. It specifies
 * the memory regions for code, data, and other
 * segments, as well as their respective sizes
 * and addresses.
 *
 * Please refer to the specific microcontroller's
 * documentation for memory map details.
 ********************************************/
MEMORY
{
    FLASH (RX) : ORIGIN = 0x08000000, LENGTH = 128K
	SRAM(RWX) : ORIGIN = 0x2000000, LENGTH = 29K
}

SECTIONS
{
	.text : {
		*(.vectors*)
		*(.text*)
		*(.rodata)
		} > FLASH
	.data : {
		*(.data*)
		} > FLASH
	.bss : {
		*(.bss*)
		} > SRAM
}