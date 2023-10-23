/*
 * STM32F103x8.h
 *
 *  Created on: Oct 22, 2023
 *      Author: Rawan Sleem
 */

#ifndef STM32F103X8_H_
#define STM32F103X8_H_
//-------------------------------------
// Includes

#include <stdint.h>

//-------------------------------------

//-------------------------------------
// Base addresses for Memories
//-------------------------------------

#define flashMemory_Base 				0x08000000UL
#define SRAM_Base  						0x20000000UL
#define systemMemory_Base				0x1FFFF000UL
#define Peripherals_Base 				0x40000000UL
#define CPUInternalPeripherals_Base 	0xE0000000UL

//-------------------------------------
// Base addresses for BUS Peripherals
//-------------------------------------

// AHB bus peripherals
// RCC

#define RCC_Base   						(Peripherals_Base + 0x00021000UL)

// APB2 bus peripherals
// NB: If you are using the LQFP48 pachage, ports E, F and G are not included,
// and ports C and C are partially included


// GPIO peripherals
#define GPIOA_Base						(Peripherals_Base + 0x00010800UL)
#define GPIOB_Base						(Peripherals_Base + 0x00010C00UL)

#define GPIOC_Base						(Peripherals_Base + 0x00011000UL)
#define GPIOD_Base						(Peripherals_Base + 0x00011400UL)

#define GPIOE_Base						(Peripherals_Base + 0x00011800UL)
#define GPIOF_Base						(Peripherals_Base + 0x00011C00UL)
#define GPIOG_Base						(Peripherals_Base + 0x00012000UL)

// AFIO periphral
#define AFIO_Base 						(Peripherals_Base + 0x00010000UL)


// EXTI peripheral
#define EXTI_Base 						(Peripherals_Base + 0x00010400UL)


// APB1 bus peripherals






//-------------------------------------
// Peripheral registers
//-------------------------------------

// GPIO registers
//-------------------------------------
// from Table 59. GPIO register map

typedef struct{
	volatile uint32_t GPIO_CRL;
	volatile uint32_t GPIO_CRH;
	volatile uint32_t GPIO_IDR;
	volatile uint32_t GPIO_ODR;
	volatile uint32_t GPIO_BSRR;
	volatile uint32_t GPIO_BRR;
	volatile uint32_t GPIO_LCKR;
}GPIO_TypeDef;

// AFIO registers
//-------------------------------------
// from Table 60. AFIO register map

typedef struct{
	volatile uint32_t AFIO_EVCR;
	volatile uint32_t AFIO_MAPR;
	volatile uint32_t AFIO_EXTICR1;
	volatile uint32_t AFIO_EXTICR2;
	volatile uint32_t AFIO_EXTICR3;
	volatile uint32_t AFIO_EXTICR4;
	volatile uint32_t reserved;
	volatile uint32_t AFIO_MAPR2;
}AFIO_TypeDef;


// EXTI registers
//-------------------------------------
// from Table 64. External interrupt/event controller register map

typedef struct{
	volatile uint32_t EXTI_IMR;
	volatile uint32_t EXTI_EMR;
	volatile uint32_t EXTI_RTSR;
	volatile uint32_t EXTI_FTSR;
	volatile uint32_t EXTI_SWIER;
	volatile uint32_t EXTI_PR;;
}EXTI_TypeDef;


// RCC registers
//-------------------------------------
// from Table 19. RCC register map

typedef struct{
	volatile uint32_t RCC_CR;
	volatile uint32_t RCC_CFGR;
	volatile uint32_t RCC_CIR;
	volatile uint32_t RCC_APB2RSTR;
	volatile uint32_t RCC_APB1RSTR;
	volatile uint32_t RCC_AHBENR;
	volatile uint32_t RCC_APB2ENR;
	volatile uint32_t RCC_APB1ENRFGR;
	volatile uint32_t RCC_BDCR;
	volatile uint32_t RCC_CSR;
	volatile uint32_t RCC_AHBSTR;
	volatile uint32_t RCC_CFGR2;
}RCC_TypeDef;

//-------------------------------------
// Peripheral Instants:
//-------------------------------------

// GPIO instants

#define GPIOA							((GPIO_TypeDef *) GPIOA_Base)
#define GPIOB							((GPIO_TypeDef *) GPIOB_Base)
#define GPIOC							((GPIO_TypeDef *) GPIOC_Base)
#define GPIOD							((GPIO_TypeDef *) GPIOD_Base)
#define GPIOE							((GPIO_TypeDef *) GPIOE_Base)
#define GPIOF							((GPIO_TypeDef *) GPIOF_Base)
#define GPIOG							((GPIO_TypeDef *) GPIOG_Base)

// RCC instants
#define RCC								((RCC_TypeDef * ) RCC_Base)

//AFIO instants
#define AFIO							((AFIO_TypeDef * ) AFIO_Base)

// EXTI instants
#define EXTI							((EXTI_TypeDef * ) EXTI_Base)

//-------------------------------------
// Clock Enable Macros:
//-------------------------------------

// GPIO ports clock enable
#define RCC_GPIOA_clock_enable()		((RCC->RCC_APB2ENR |= (1 << 2)))
#define RCC_GPIOB_clock_enable()		((RCC->RCC_APB2ENR |= (1 << 3)))
#define RCC_GPIOC_clock_enable()		((RCC->RCC_APB2ENR |= (1 << 4)))
#define RCC_GPIOD_clock_enable()		((RCC->RCC_APB2ENR |= (1 << 5)))
#define RCC_GPIOE_clock_enable()		((RCC->RCC_APB2ENR |= (1 << 6)))
#define RCC_GPIOF_clock_enable()		((RCC->RCC_APB2ENR |= (1 << 7)))
#define RCC_GPIOG_clock_enable()		((RCC->RCC_APB2ENR |= (1 << 8)))
#define RCC_AFIO_clock_enable()			((RCC->RCC_APB2ENR |= (1 << 0)))




//-------------------------------------
// Generic Macros:
//-------------------------------------







#endif /* STM32F103X8_H_ */
