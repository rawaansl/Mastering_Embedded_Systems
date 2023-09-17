// Startup File - Cortex-M3 Processor
// Author: Rawan Sleem

// Dealing with Cortex-M4 architecture, we are able to write the startup file in C-Code instead of assembly 

// Please refer to the specific microcontroller's datasheet and reference manual
// for detailed information about the memory layout, vector table, and
// initialization procedures.

// In this startup code modified version, the location of the 
// stack_top will be automatically defined in the .bss section,

// We will define the vector table as an array of const pointers to functions that
// take no arguments and return void. This table contains the addresses of
// various interrupt service routines.

#include <stdint.h>


void Reset_handler();
void Default_handler();


// Weak alias functions for various exceptions, allowing them to be overridden
// by the application if needed
void NMI_handler() __attribute__((weak, alias("Default_handler")));
void H_Fault_handler() __attribute__((weak, alias("Default_handler")));
void MM_handler() __attribute__((weak, alias("Default_handler")));
void BF_handler() __attribute__((weak, alias("Default_handler")));
void UF_handler() __attribute__((weak, alias("Default_handler")));

extern int main(void);

static uint32_t bss_stack[256];       //size of the stack required to be 1024 bytes


void (*const interrupt_handlers[])() __attribute__((section(".vectors"))) = {
	
	(void (*)()) ((uint32_t)bss_stack + sizeof(bss_stack)),       // Initial stack pointer location
     &Reset_handler,  // Reset handler
     &NMI_handler,    // Non-Maskable Interrupt (NMI) handler
     &H_Fault_handler,// Hard Fault handler
     &MM_handler,     // Memory Management Fault handler
     &BF_handler,     // Bus Fault handler
     &UF_handler,     // Usage Fault handler
	
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