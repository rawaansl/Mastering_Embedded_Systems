/******************************************************************************
 * Startup File - Cortex-M3 Processor
 * Author: Rawan Sleem
 *
 * Description:
 * This is the startup code for the Cortex-M3 processor. It initializes the
 * microcontrollers core and sets up the initial stack pointer before
 * branching to the main application code.
 *
 * Please refer to the specific microcontrollers datasheet and reference manual
 * for detailed information about the memory layout, vector table, and
 * initialization procedures.
 *****************************************************************************/
 
 .section .vectors
	.word   0x20001000          /* Initial stack pointer value */
	.word   _reset      /* Reset */
	.word   vector_handler      /* Non-Maskable Interrupt (NMI) */
	.word   vector_handler      /* Hard Fault */
	.word   vector_handler      /* Memory Management Fault */
	.word   vector_handler      /* Bus Fault */
	.word   vector_handler      /* Usage Fault */
	.word   0                   /* Reserved */
	.word   0                   /* Reserved */
	.word   0                   /* Reserved */
	.word   0                   /* Reserved */
	.word   vector_handler      /* Supervisor Call (SVCall) */
	.word   vector_handler      /* Debug Monitor */
	.word   0                   /* Reserved */
	.word   vector_handler      /* Pendable Service (PendSV) */
	.word   vector_handler      /* SysTick */
	.word   vector_handler      /* External Interrupt 1 */
	.word   vector_handler      /* External Interrupt 2 */
	.word   vector_handler      /* External Interrupt 3 */
	.word   vector_handler      /* External Interrupt 4 */
	.word   vector_handler      /* External Interrupt 5 */
	.word   vector_handler      /* External Interrupt 6 */
	.word   vector_handler      /* External Interrupt 7 */
	.word   vector_handler      /* External Interrupt 8 */
	.word   vector_handler      /* External Interrupt 9 */
	/* untill external interrupt 67 */


 .section .text
 _reset:
	 bl main
	 b .
 
 .thumb_func
 
 /* Vector_handler is marked as an ISR entry point, and it simply branches back to the _reset label, 
 * which can be used to restart the program. 
 * This is a simplified example and doesnt
 * handle any real interrupt processing;
 * it just demonstrates the concept of an ISR returning to the program entry point. */
 
 vector_handler:
	b _reset
	