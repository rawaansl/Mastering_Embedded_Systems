################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../GPIO_driver/stm32f103x8_GPIO_driver.c 

OBJS += \
./GPIO_driver/stm32f103x8_GPIO_driver.o 

C_DEPS += \
./GPIO_driver/stm32f103x8_GPIO_driver.d 


# Each subdirectory must supply rules for building sources it contributes
GPIO_driver/stm32f103x8_GPIO_driver.o: ../GPIO_driver/stm32f103x8_GPIO_driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/STM32F103C6 Drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"GPIO_driver/stm32f103x8_GPIO_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

