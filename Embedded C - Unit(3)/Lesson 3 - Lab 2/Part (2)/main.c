/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Rawan Sleem
 * @brief          : Main program body
 */

#include <stdint.h>

#define RCC  0x40021000                                           // base address of RCC
#define GPIO 0x40010800
#define RCC_APB2ENR (*(volatile uint32_t*)(RCC + 0x18))    // address of APB2ENR register
#define GPIO_CRH (*(volatile uint32_t*)(GPIO + 0x04))      // base address of CRH register
#define GPIO_ODR (*(volatile uint32_t*)(GPIO + 0x0C))      // base address of the ODR register

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
                    

int main(void) {
	
	RCC_APB2ENR |= 1 << 2;                             // set the second bit to one
    GPIO_CRH &= 0xFF0FFFFF;                            // clear bits 20-24
    GPIO_CRH |= 0x00200000; 						   // set 2 on 20-24 bits
	
    while (1) {
        R_ODR->pin.pin13 = 0;
        for (int i = 0; i < 5000; i++);
        R_ODR->pin.pin13 = 1;
        for (int i = 0; i < 5000; i++);
    }
}
