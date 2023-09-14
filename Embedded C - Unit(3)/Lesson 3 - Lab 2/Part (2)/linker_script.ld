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
	SRAM(RWX) : ORIGIN = 0x20000000, LENGTH = 20K
}
/*we can add the ALIGN command to a certain section to ensure memory alignemnt*/
SECTIONS
{
	.text : {
		*(.vectors*)
		*(.text*)
		*(.rodata)
		. = ALIGN(4);
		_E_text = . ;
		} > FLASH
	.data : {
		_S_data = . ;
		*(.data)
		. = ALIGN(4);
		_E_data = . ;
		}> SRAM AT> FLASH
	.bss : {
		_S_bss = . ;
		*(.bss*)
		. = ALIGN(4);
		_E_bss = . ;
		
		. = ALIGN(4);
		. = . + 0x1000;
		stack_top = .;

		} > SRAM
}