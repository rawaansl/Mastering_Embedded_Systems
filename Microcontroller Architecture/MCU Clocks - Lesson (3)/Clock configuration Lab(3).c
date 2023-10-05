/**
 ******************************************************************************
 * @file           : main.c
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

#include <stdint.h>

#define RCC  0x40021000 // Base address of RCC

// RCC Registers
#define RCC_CR      (*(volatile uint32_t*)(RCC + 0x00)) // Address of the CR register
#define RCC_CFGR    (*(volatile uint32_t*)(RCC + 0x04)) // Address of the CFGR register

void clock_init() {
   // Enable HSI (bit 0 in RCC_CR) and set HCLK to be divided by 4 (bits 13:11 in RCC_CFGR)

    RCC_CR |= (1 << 0);					 // HSI on
    RCC_CR |= (0b1 << 24);          	// PLL on
    RCC_CFGR &= ~(0b1111 << 18);        // clear
    RCC_CFGR |= (0b0110 << 18);         // PLL input clock x8
    RCC_CFGR &= ~(1 << 16);             // HSI oscillator clock / 2 selected as PLL input clock
    RCC_CFGR &= ~(0b111 << 11);
    RCC_CFGR |= (0b101 << 11);			// HCLK divided by 4

    // Set HCLK to be divided by 2 (bits 10:8 in RCC_CFGR)
    RCC_CFGR |= (0b100 << 8);

    // Select HSI clock (bits 1:0 in RCC_CFGR) and SYSCLK not divided (AHB prescaler)
    RCC_CFGR &= ~(0b11 << 0);
    RCC_CFGR |= (0b10 << 0);
    RCC_CFGR |= (0b10 << 2);
    RCC_CFGR &= ~(0b1 << 7);
}

int main(void) {
    // Initialize clock configuration
    clock_init();
    while(1){

    }
}
