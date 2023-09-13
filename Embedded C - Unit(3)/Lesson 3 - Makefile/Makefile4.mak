#@copyright : Rawan Sleem
#Makefile4

#By specifying the Windows Command Prompt (cmd.exe) as the shell, 
#you ensure that Make uses a shell that is compatible with Windows commands.
#This can resolve issues related to the use of Unix-like commands like rm in a Windows environment.

SHELL=C:/Windows/System32/cmd.exe

#Build Variables
CC =arm-none-eabi-
CFLAGS =-g -mcpu=arm926ej-s
INCS =-I .
LIBS =

#DRY Simplification
#Implicit Generic Rule 

all: Learn-in-depth.bin
	@echo "Build is complete"

startup.o: startup.s
	$(CC)as.exe $(CFLAGS) $< -o $@

app.o: app.c
	$(CC)gcc.exe -c $(INCS) $(CFLAGS) $< -o $@
	
uart.o: uart.c 
	$(CC)gcc.exe -c $(INCS) $(CFLAGS) $< -o $@

Learn-in-depth.elf: uart.o app.o startup.o
	$(CC)ld.exe -T linker_script.ld startup.o uart.o app.o -o $@ -Map=Map_file.map

Learn-in-depth.bin: learn-in-depth.elf
	$(CC)objcopy.exe -O binary $< $@
	
clear_all: 
	rm *.o *.elf *.bin
	
clear:
	rm *.elf *.bin 