# @copyright : Rawan Sleem
# Makefile

# By specifying the Windows Command Prompt (cmd.exe) as the shell, 
# you ensure that Make uses a shell that is compatible with Windows commands.
# This can resolve issues related to the use of Unix-like commands like rm in a Windows environment.

SHELL=C:/Windows/System32/cmd.exe

CC =arm-none-eabi-
# add the '-gdwarf' option to set the debugger level, making it compatible with Proteus.
CFLAGS =-mcpu=cortex-m4 -gdwarf-2 -g       
INCS =-I .
LIBS =
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
As=$(wildcard *.s)
AsOBJ=$(As:.s=.o)
Project_name=Lab3_Cortex-M4

# DRY Simplification
# Implicit Generic Rule


all: $(Project_name).bin
	@echo "Build is complete"
	
# we add in this makefile, we need to ensure that we are 
# compiling the code with the correct instruction set for the Cortex-M3 processor,
# which is the Thumb instruction set, so we add -mthumb in the compiler command.

# add the -std=c99 flag to your compiler command to enable C99 mode, 
# which allows for loop initial declarations.
%.o: %.c
	$(CC)gcc.exe $(INCS) $(CFLAGS) -mthumb -std=c99 -c $< -o $@

$(Project_name).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linker_script.ld $(OBJ) $(AsOBJ) -o $@ -Map=Map_file.map

$(Project_name).bin: $(Project_name).elf
	$(CC)objcopy.exe -O binary $< $@
	cp $(Project_name).elf $(Project_name).axf
	
clear_all: 
	rm *.o *.elf *.bin
	@echo "Everything Cleared"
clear:
	rm *.elf *.bin 