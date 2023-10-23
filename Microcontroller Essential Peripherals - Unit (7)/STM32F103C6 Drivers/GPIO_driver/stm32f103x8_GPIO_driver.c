


#include "STM32F103x8.h"
#include "stm32f103x8_GPIO_driver.h"




// to get the postion of the four bits for CNF and MODE for the specified pin
int getPosition(uint16_t pinNumber) {
    switch (pinNumber) {

// CRL bits
        case GPIO_PIN0_MASK:
            return 0;
        case GPIO_PIN1_MASK:
            return 4;
        case GPIO_PIN2_MASK:
            return 8;
        case GPIO_PIN3_MASK:
            return 12;
        case GPIO_PIN4_MASK:
            return 16;
        case GPIO_PIN5_MASK:
            return 20;
        case GPIO_PIN6_MASK:
            return 24;
        case GPIO_PIN7_MASK:
            return 28;


// CRH bits
        case GPIO_PIN8_MASK:
        	return 0;
        case GPIO_PIN9_MASK:
            return 4;
        case GPIO_PIN10_MASK:
            return 8;
        case GPIO_PIN11_MASK:
            return 12;
        case GPIO_PIN12_MASK:
            return 16;
        case GPIO_PIN13_MASK:
            return 20;
        case GPIO_PIN14_MASK:
            return 24;
        case GPIO_PIN15_MASK:
            return 28;
        default:
            return -1; // Handle the case when pinNumber does not match any of the specified cases
    }
}





void MCAL_GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_Config_TypeDef* pinConfig){
	uint8_t pin_temp;
	// GPIOx_CRL for pins 0 >>> 7
	// GPIOx_CRH for pin 8 >>> 15

	volatile uint32_t* configRegister = NULL;
	configRegister = (pinConfig->GPIO_pinNumber > GPIO_PIN8_MASK? &GPIOx->GPIO_CRH : &GPIOx->GPIO_CRL);

	// reset clear CNF and MODE bits
	*configRegister &= ~(0xF << getPosition(pinConfig->GPIO_pinNumber));
	// check  if the pin is output, speed is configured
	if (pinConfig->GPIO_Mode == GPIO_MODE_OUTPUT_PP ||
	    pinConfig->GPIO_Mode == GPIO_MODE_OUTPUT_OD ||
	    pinConfig->GPIO_Mode == GPIO_MODE_ALTERNATE_PP ||
	    pinConfig->GPIO_Mode == GPIO_MODE_ALTERNATE_OD) {
		pin_temp = (((pinConfig->GPIO_Mode - 4) << 2) | (pinConfig->GPIO_Speed & 0x0F));
	}

	// if the pin is input
	// alternating input is configured as floating input

	else
	{
		if((pinConfig->GPIO_Mode) == (GPIO_MODE_ANALOG) || (pinConfig->GPIO_Mode) == (GPIO_MODE_FLOATING)){
			pin_temp = ((((pinConfig->GPIO_Mode) << 2) | 0x0) & 0X0F);
		}
		else
		{
			pin_temp = ((((GPIO_MODE_INPUT_PULLUP) << 2)  | 0x0) & 0X0F);
			if((pinConfig->GPIO_Mode) == GPIO_MODE_INPUT_PULLUP){
				GPIOx->GPIO_ODR |= (pinConfig->GPIO_pinNumber);
		}
			else
			{
				GPIOx->GPIO_ODR &= ~(pinConfig->GPIO_pinNumber);
			}
		}
	}
	// configure CRL or CRH registers
	*configRegister |= ((pin_temp) << (getPosition(pinConfig->GPIO_pinNumber)));
}





void MCAL_GPIO_DeInit(GPIO_TypeDef* GPIOx){
	// without using the RCC
	GPIOx->GPIO_ODR = 0x00000000;
	// IDR read only
	GPIOx->GPIO_BRR = 0x00000000;
	GPIOx->GPIO_BSRR = 0x00000000;
	GPIOx->GPIO_CRH = 0x44444444;
	GPIOx->GPIO_CRL = 0x44444444;

	// through APB2 peripheral reset register (RCC_APB2RSTR)
//	if (GPIOx == GPIOA){
//		RCC->RCC_APB2RSTR |= (1 << 2);
//	}
//	else if(GPIOx == GPIOB){
//		RCC->RCC_APB2RSTR |= (1 << 3);
//	}
//	else if(GPIOx == GPIOC){
//			RCC->RCC_APB2RSTR |= (1 << 4);
//		}
//	else if(GPIOx == GPIOD){
//			RCC->RCC_APB2RSTR |= (1 << 5);
//		}
//	else if(GPIOx == GPIOE){
//			RCC->RCC_APB2RSTR |= (1 << 6);
//		}
//	else if(GPIOx == GPIOF){
//			RCC->RCC_APB2RSTR |= (1 << 7);
//		}
//	else if(GPIOx == GPIOG){
//			RCC->RCC_APB2RSTR |= (1 << 8);
//		}
}




void MCAL_GPIO_WritePin(GPIO_TypeDef* GPIOx, uint16_t pinNumber, uint8_t value){
	if (value == GPIO_PIN_SET)
		GPIOx->GPIO_BSRR = (uint32_t)pinNumber;   // set the pin
	else
		GPIOx->GPIO_BRR = (uint32_t)pinNumber;   // reset the pin
 }


void MCAL_GPIO_WritePort(GPIO_TypeDef* GPIOx, uint16_t value){
	GPIOx->GPIO_ODR = (uint32_t ) value;

}



uint8_t MCAL_GPIO_ReadPin(GPIO_TypeDef* GPIOx, uint16_t pinNumber){
	if((GPIOx->GPIO_IDR & pinNumber) == GPIO_PIN_RESET)
		return (uint8_t)GPIO_PIN_RESET;
	else
		return (uint8_t)GPIO_PIN_SET;
}



uint16_t MCAL_GPIO_ReadPort(GPIO_TypeDef* GPIOx){
	return (uint16_t)GPIOx->GPIO_IDR;
}




void MCAL_GPIO_TogglePin(GPIO_TypeDef* GPIOx, uint16_t pinNumber){
	GPIOx->GPIO_ODR ^= pinNumber;
}


uint8_t MCAL_GPIO_LockPin(GPIO_TypeDef* GPIOx, uint16_t pinNumber){
// Each lock bit freezes the corresponding 4 bits of the control register (CRL, CRH).
//	LOCK key writing sequence: on bit 16
//	Write 1
//	Write 0
//	Write 1
//	Read 0
//	Read 1 (this read is optional but confirms that the lock is active)
	volatile uint32_t temp = 1 << 16;
	temp |= pinNumber;
	GPIOx->GPIO_LCKR |= temp;
	GPIOx->GPIO_LCKR |= pinNumber;
	GPIOx->GPIO_LCKR |= temp;
	temp = GPIOx->GPIO_LCKR;
	if((uint32_t) temp & 1 >> 16)
		return GPIO_LOCK_RETURN_ENABLED;
	else
		return GPIO_LOCK_RETURN_ERROR;
}
