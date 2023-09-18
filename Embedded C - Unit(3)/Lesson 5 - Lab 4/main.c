/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Rawan Sleem
 * @brief          : Main program body
 */

#include <stdint.h>
#include <stdlib.h>

#define RCC  0x40021000                                           // base address of RCC
#define GPIO 0x40010800
#define RCC_APB2ENR (*(volatile uint32_t*)(RCC + 0x18))    // address of APB2ENR register
#define GPIO_CRH (*(volatile uint32_t*)(GPIO + 0x04))      // base address of CRH register
#define GPIO_ODR (*(volatile uint32_t*)(GPIO + 0x0C))      // base address of the ODR register

extern uint32_t _E_data;
extern uint32_t* heap_end;

typedef union {
    uint32_t all_bits;
    struct {
    volatile uint32_t reserved:13;
    volatile uint32_t pin13:1;
    } pin;
} REG;

volatile REG* R_ODR = (volatile REG*)(GPIO + 0x0C);  // pointer to the base address of the ODR register
unsigned char g_variables[3] = {1, 2, 3};            // to check the data section
unsigned char const c_variables[3] = {1, 2 ,3};      // to check the rodata section
   
/**
 * @brief Increment the heap pointer to allocate memory dynamically.
 *
 * This function is used to dynamically allocate memory from the heap by incrementing
 * the heap pointer. It ensures that the requested memory allocation does not exceed
 * the heap's available space. The previous heap pointer is returned before the
 * increment for memory management purposes.
 *
 * @param incr The amount by which to increment the heap pointer.
 * @return A pointer to the previous heap position, or NULL if the allocation fails.
 */


void* _sbrk (int incr) {

    static unsigned char* heap_ptr = NULL;         // Static pointer to keep track of the heap's current position
    unsigned char* prev_heap_ptr = NULL;           // Pointer to store the previous heap pointer
	if (heap_ptr == NULL)
        heap_ptr = (unsigned char*)&_E_data;       // If heap_ptr is NULL, initialize it to the end of the data section
	
    prev_heap_ptr = heap_ptr;                      // Store the current heap pointer as the previous one

    

    if ((heap_ptr + incr) > (unsigned char*)&heap_end)
        return (void*) NULL;                       // Check if the requested increment exceeds the heap's end, return NULL if so

    heap_ptr += incr;                              // Increment the heap pointer by the requested increment

    return (void*)prev_heap_ptr;                   // Return the previous heap pointer (before incrementing)
}



int main(void) {
	
	RCC_APB2ENR |= 1 << 2;                             // set the second bit to one
    GPIO_CRH &= 0xFF0FFFFF;                            // clear bits 20-24
    GPIO_CRH |= 0x00200000; 		// set 2 on 20-24 bits
	int *p = (int*) malloc(4);
	
	
    while (1) {
        R_ODR->pin.pin13 = 0;
        for (int i = 0; i < 5000; i++);
        R_ODR->pin.pin13 = 1;
        for (int i = 0; i < 5000; i++);
    }
	free(p);
}
