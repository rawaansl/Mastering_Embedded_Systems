#include "uart.h"

unsigned char string[50] = "Learn-In-Depth: Rawan";   //the string to be recieved then sent by the DR register
void main(void){
	
	uart_tx(string);
	
}