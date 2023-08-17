#include "uart.h"

#define UART0_DR *((volatile unsigned int*)((unsigned int*)0x101f1000))      //define the location for the DR register 
//deifne the function that recieves a string from the pointer p_string
void uart_tx(unsigned char* p_string){
	while(*p_string != 0){
		UART0_DR = *p_string;
		p_string++;
	}
}