/*
 * stm32f103x8_gpio_driver.h
 *
 *  Created on: Oct 22, 2023
 *      Author: Rawan Sleem
 */

#ifndef STM32F103X8_GPIO_DRIVER_H_
#define STM32F103X8_GPIO_DRIVER_H_

//-----------------------------
//Includes
//-----------------------------
#include "STM32F103x8.h"
#include <stddef.h>
//-----------------------------




//User type definitions (structures)
//-----------------------------

// to represent specific configurations for GPIO pins

typedef struct {
    uint16_t GPIO_pinNumber;
    uint8_t GPIO_Mode;  // Field for mode configuration (e.g., Input, Output, etc.)
    uint8_t GPIO_Speed; // Field for speed configuration (e.g., 10MHz, 2MHz, 50MHz)
} GPIO_Config_TypeDef;





//-----------------------------
//Macros Configuration References
//-----------------------------


/*@ref GPIO_PINx_MASK_define*/
#define GPIO_PIN0_MASK  				((uint16_t)0x0001)
#define GPIO_PIN1_MASK  				((uint16_t)0x0002)
#define GPIO_PIN2_MASK 				    ((uint16_t)0x0004)
#define GPIO_PIN3_MASK  				((uint16_t)0x0008)
#define GPIO_PIN4_MASK  				((uint16_t)0x0010)
#define GPIO_PIN5_MASK  				((uint16_t)0x0020)
#define GPIO_PIN6_MASK 				    ((uint16_t)0x0040)
#define GPIO_PIN7_MASK  				((uint16_t)0x0080)
#define GPIO_PIN8_MASK  				((uint16_t)0x0100)
#define GPIO_PIN9_MASK  			 	((uint16_t)0x0200)
#define GPIO_PIN10_MASK 				((uint16_t)0x0400)
#define GPIO_PIN11_MASK 				((uint16_t)0x0800)
#define GPIO_PIN12_MASK 				((uint16_t)0x1000)
#define GPIO_PIN13_MASK 				((uint16_t)0x2000)
#define GPIO_PIN14_MASK 				((uint16_t)0x4000)
#define GPIO_PIN15_MASK 				((uint16_t)0x8000)
#define GPIO_ALL						((uint16_t)0xFFFF)

/*@ref GPIO_MODES_define*/

//0: Analog mode
//1: Floating input (reset state)
//2: Input with pull-up
//3: Input with pull-down
//4: General purpose output push-pull
//5: General purpose output Open-drain
//6: Alternate function output Push-pull
//7: Alternate function output Open-drain

#define GPIO_MODE_ANALOG            	 0x00000000u  // Analog mode
#define GPIO_MODE_FLOATING          	 0x00000001u  // Floating input (reset state)
#define GPIO_MODE_INPUT_PULLUP      	 0x00000002u  // Input with pull-up
#define GPIO_MODE_INPUT_PULLDOWN    	 0x00000003u  // Input with pull-down
#define GPIO_MODE_OUTPUT_PP        		 0x00000004u  // General purpose output push-pull
#define GPIO_MODE_OUTPUT_OD        		 0x00000005u  // General purpose output Open-drain
#define GPIO_MODE_ALTERNATE_PP       	 0x00000006u  // Alternate function output Push-pull
#define GPIO_MODE_ALTERNATE_OD       	 0x00000007u  // Alternate function output Open-drain


/*@ref GPIO_Speed_define*/

//0: Output mode, max speed 10 MHz.
//1: Output mode, max speed 2 MHz.
//2: Output mode, max speed 50 MHz

#define GPIO_Speed_10 					0x00000001u    // Output mode with a maximum speed of 10 MHz
#define GPIO_Speed_2					0x00000002u	   // Output mode with a maximum speed of 2 MHz
#define GPIO_Speed_50					0x00000003u    // Output mode with a maximum speed of 50 MHz


/*@ref GPIO_PIN_STATE*/
#define GPIO_PIN_SET					1
#define GPIO_PIN_RESET					0

/*@ref GPIO_LOCK_RETURN*/
#define GPIO_LOCK_RETURN_ENABLED		1
#define GPIO_LOCK_RETURN_ERROR			0

//------------------------------------
// APIs Supported by "MCAL GPIO DRIVER"
//------------------------------------



/**
 * @brief Initializes a specific GPIO pin with the given configuration.
 *
 * @param[in] GPIOx Pointer to the GPIO port (e.g., GPIOA, GPIOB, etc.).
 * @param[in] pinConfig Pointer to a structure containing the pin configuration settings.
 */
void MCAL_GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_Config_TypeDef* pinConfig);


/**
 * @brief Deinitializes a specific GPIO port, resetting all the pin configurations to their default state.
 *
 * @param[in] GPIOx Pointer to the GPIO port (e.g., GPIOA, GPIOB, etc.).
 */
void MCAL_GPIO_DeInit(GPIO_TypeDef* GPIOx);


/**
 * @brief Writes a digital value to a specific GPIO pin.
 *
 * @param[in] GPIOx Pointer to the GPIO port (e.g., GPIOA, GPIOB, etc.).
 * @param[in] pinNumber The pin number of the GPIO pin to write to.
 * @param[in] value The value to write (0 or 1).
 */
void MCAL_GPIO_WritePin(GPIO_TypeDef* GPIOx, uint16_t pinNumber, uint8_t value);


/**
 * @brief Writes a digital value to the entire GPIO port.
 *
 * @param[in] GPIOx Pointer to the GPIO port (e.g., GPIOA, GPIOB, etc.).
 * @param[in] value The value to write to the port.
 */
void MCAL_GPIO_WritePort(GPIO_TypeDef* GPIOx, uint16_t value);


/**
 * @brief Reads the digital value of a specific GPIO pin.
 *
 * @param[in] GPIOx Pointer to the GPIO port (e.g., GPIOA, GPIOB, etc.).
 * @param[in] pinNumber The pin number of the GPIO pin to read from.
 * @return The digital value read from the pin (0 or 1).
 */
uint8_t MCAL_GPIO_ReadPin(GPIO_TypeDef* GPIOx, uint16_t pinNumber);


/**
 * @brief Reads the digital value of the entire GPIO port.
 *
 * @param[in] GPIOx Pointer to the GPIO port (e.g., GPIOA, GPIOB, etc.).
 * @return The digital value read from the port.
 */
uint16_t MCAL_GPIO_ReadPort(GPIO_TypeDef* GPIOx);


/**
 * @brief Toggles the digital state of a specific GPIO pin.
 *
 * @param[in] GPIOx Pointer to the GPIO port (e.g., GPIOA, GPIOB, etc.).
 * @param[in] pinNumber The pin number of the GPIO pin to toggle.
 */
void MCAL_GPIO_TogglePin(GPIO_TypeDef* GPIOx, uint16_t pinNumber);


/**
 * @brief Locks the configuration of a specific GPIO pin.
 *
 * @param[in] GPIOx Pointer to the GPIO port (e.g., GPIOA, GPIOB, etc.).
 * @param[in] pinNumber The pin number of the GPIO pin to lock.
 */
uint8_t MCAL_GPIO_LockPin(GPIO_TypeDef* GPIOx, uint16_t pinNumber);




#endif /* STM32F103X8_GPIO_DRIVER_H_ */
