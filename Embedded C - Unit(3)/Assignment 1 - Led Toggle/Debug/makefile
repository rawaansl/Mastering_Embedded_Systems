################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
led_toggle_.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
led_toggle_.list \

OBJCOPY_HEX += \
led_toggle_.hex \

OBJCOPY_BIN += \
led_toggle_.bin \


# All Target
all: led_toggle_.elf secondary-outputs

# Tool invocations
led_toggle_.elf: $(OBJS) $(USER_OBJS) D:\led_toggle_\STM32F103C6TX_FLASH.ld
	arm-none-eabi-gcc -o "led_toggle_.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"D:\led_toggle_\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="led_toggle_.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

led_toggle_.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "led_toggle_.list"
	@echo 'Finished building: $@'
	@echo ' '

led_toggle_.hex: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "led_toggle_.hex"
	@echo 'Finished building: $@'
	@echo ' '

led_toggle_.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "led_toggle_.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
