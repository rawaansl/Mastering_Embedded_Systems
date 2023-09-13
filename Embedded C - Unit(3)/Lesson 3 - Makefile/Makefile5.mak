#@copyright : Rawan Sleem
#Makefile4

#By specifying the Windows Command Prompt (cmd.exe) as the shell, 
#you ensure that Make uses a shell that is compatible with Windows commands.
#This can resolve issues related to the use of Unix-like commands like rm in a Windows environment.

SHELL=C:/Windows/System32/cmd.exe

#Build Variables
#Use SRC, OBJ, As, and AsOBJ automated build variables
CC =arm-none-eabi-
CFLAGS =-g -mcpu=arm926ej-s
INCS =-I .
LIBS =
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
As=$(wildcard *.s)
AsOBJ=$(As:.s=.o)
Project_name=Learn-In-Depth
#DRY Simplification
#Implicit Generic Rule


all: $(Project_name).bin
	@echo "Build is complete"

%.o: %.s
	$(CC)as.exe $(CFLAGS) $< -o $@

%.o: %.c
	$(CC)gcc.exe $(INCS) $(CFLAGS) -c $< -o $@

$(Project_name).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linker_script.ld $(OBJ) $(AsOBJ) -o $@ -Map=Map_file.map

$(Project_name).bin: $(Project_name).elf
	$(CC)objcopy.exe -O binary $< $@
	
clear_all: 
	rm *.o *.elf *.bin
	@echo "Everything Cleared"
clear:
	rm *.elf *.bin 