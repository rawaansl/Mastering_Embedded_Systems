
/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


#include <stdint.h>

#define RCC  0x40021000 // Base address of RCC
#define GPIOA 0x40010800 // Base address of GPIO A
#define GPIOB 0x40010C00 // Base address of GPIO B


// RCC Registers
#define RCC_CR      (*(volatile uint32_t*)(RCC + 0x00)) // Address of the CR register
#define RCC_APB2ENR (*(volatile uint32_t*)(RCC + 0x18)) // Address of APB2ENR register
#define RCC_CFGR    (*(volatile uint32_t*)(RCC + 0x04)) // Address of the CFGR register

// GPIO Registers
// Port A
#define GPIOA_CRH (*(volatile uint32_t*)(GPIOA + 0x04))
#define GPIOA_CRL (*(volatile uint32_t*)(GPIOA + 0x00))
#define GPIOA_ODR (*(volatile uint32_t*)(GPIOA + 0x0C))
#define GPIOA_IDR (*(volatile uint32_t*)(GPIOA + 0x08))

// Port B
#define GPIOB_CRH (*(volatile uint32_t*)(GPIOB + 0x04))
#define GPIOB_CRL (*(volatile uint32_t*)(GPIOB + 0x00))
#define GPIOB_ODR (*(volatile uint32_t*)(GPIOB + 0x0C))
#define GPIOB_IDR (*(volatile uint32_t*)(GPIOB + 0x08))


void clock_init() {
    // Enable clock for port A (bit 2 in RCC_APB2ENR)
    RCC_APB2ENR |= (1 << 2);
    // Enable clock for port B (bit 3 in RCC_APB2ENR)
    RCC_APB2ENR |= (1 << 3);
}

void GPIO_init(){
	// used pins : B1, A1, A13, B13
	// A1 and A13 floating inputs connected to external PUR and PDR respectively
	// B1 and B13 output
	GPIOA_CRL = 0x0;
	GPIOA_CRH = 0x0;
	GPIOA_ODR = 0x0;

	// pin A1 configuration
	GPIOA_CRL &= ~(0b11 << 4);      // MODE of input
	GPIOA_CRL |= (0b01 << 6);       // CNF bits configuration for floating inputs (HIGH Z)

	// pin A13 configuration
	GPIOA_CRH &= ~(0b11 << 20);     // MODE of input
	GPIOA_CRH |= (0b01 << 22);      // CNF bits configuration for floating inputs (HIGH Z)

	// pin B1 configuration
	GPIOB_CRL &= ~(0b11 << 6);      // push-pull output pin
	GPIOB_CRL |= (0b01 << 4);       // Maximum output speed 10 MHz

	// pin B13 configuration
	GPIOB_CRH &= ~(0b11 << 22);     // push-pull output pin
	GPIOB_CRH |= (0b01 << 20);      // Maximum output speed 10 MHz
}

#include <stdint.h>

void delay(uint32_t milliseconds) {
    // Assuming a 1ms delay for each iteration
    volatile uint32_t count = 0;
    while (count < (milliseconds * 1000)) {
        count++;
    }
}


int main(void) {
    // Initialize clock configuration
    clock_init();
    GPIO_init();


    while (1){
    	if (((GPIOA_IDR & (0b1 << 1)) >> 1) == 0) {  // pushed button (PUR)
    		GPIOB_ODR ^= (0b1 << 1);           // Pin B1 grounded to allow flow of current then toggles
    		while ((((GPIOA_IDR & (0b1 << 1)) >> 1) == 0));   // wait till the button is released
    	}
    	if (((GPIOA_IDR & (0b1 << 13)) >> 13) == 1){  // pushed button (PDR)
    		GPIOB_ODR ^= (0b1 << 13);           // Pin B13 grounded to allow flow of current then toggles
    	}
    	delay(100);
    }
}




