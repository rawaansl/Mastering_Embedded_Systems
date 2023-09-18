// Startup File - Cortex-M3 Processor
// Author: Rawan Sleem
//
// Description:
// This is the startup code for the Cortex-M3 processor. It initializes the
// microcontroller's core and sets up the initial stack pointer before
// branching to the main application code.

// Dealing with Cortex-M3 architecture, we are able to write the startup file in C-Code instead of assembly 

// Please refer to the specific microcontroller's datasheet and reference manual
// for detailed information about the memory layout, vector table, and
// initialization procedures.

#include <stdint.h>


void Reset_handler();
void Default_handler();
extern unsigned char stack_top;
// Weak alias functions for various exceptions, allowing them to be overridden
// by the application if needed
void NMI_handler() __attribute__((weak, alias("Default_handler")));
void H_Fault_handler() __attribute__((weak, alias("Default_handler")));
void MM_handler() __attribute__((weak, alias("Default_handler")));
void BF_handler() __attribute__((weak, alias("Default_handler")));
void UF_handler() __attribute__((weak, alias("Default_handler")));

extern int main(void);


// Vector table, specifying the initial stack pointer and function pointers
uint32_t vectors[] __attribute__((section(".vectors"))) = {
    (uint32_t) &stack_top,       // Initial stack pointer
    (uint32_t) &Reset_handler,  // Reset handler
    (uint32_t) &NMI_handler,    // Non-Maskable Interrupt (NMI) handler
    (uint32_t) &H_Fault_handler,// Hard Fault handler
    (uint32_t) &MM_handler,     // Memory Management Fault handler
    (uint32_t) &BF_handler,     // Bus Fault handler
    (uint32_t) &UF_handler,     // Usage Fault handler
};

// Reset handler, responsible for starting the main application, and copying the data section from flash memory to SRAM
void Reset_handler(){
	
	extern uint32_t _E_text;
	extern uint32_t _S_data;
	extern uint32_t _E_data;
	extern uint32_t _S_bss;
	extern uint32_t _E_bss;
	unsigned char *P_SRC = (unsigned char*) &_E_text;
	unsigned char *P_DST = (unsigned char*) &_S_data;
	unsigned int data_size = (unsigned char*)&_E_data - (unsigned char*)&_S_data ;     
	
	// Copy the data from flash to ram
	for( int i = 0; i < data_size; i++){
		*((unsigned char*)P_DST++) = *((unsigned char*)P_SRC++) ;
	}
	
	//initialize the .bss section in the SRAM to zero
	uint32_t bss_size = &_S_bss - &_E_bss ;
	P_DST = (unsigned char*) &_S_bss;
	
	for( int i = 0; i < bss_size; i++){
		*((unsigned char*)P_DST++) = (unsigned char) 0 ;
	}
		
	// Call the main application
    main(); 
}

// Default interrupt handler, used for any unhandled interrupt
void Default_handler(){
	Reset_handler();
}