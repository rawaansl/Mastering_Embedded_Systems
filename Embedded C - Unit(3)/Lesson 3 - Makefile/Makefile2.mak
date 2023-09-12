#@copyright : Rawan Sleem
#Makefile2

#By specifying the Windows Command Prompt (cmd.exe) as the shell, 
#you ensure that Make uses a shell that is compatible with Windows commands.
#This can resolve issues related to the use of Unix-like commands like rm in a Windows environment.

SHELL=C:/Windows/System32/cmd.exe

#We can also add variables to control the C compiler and compiler flags, etc.
#These variables allow you to customize how your C code is compiled.

CC =arm-none-eabi-
CFLAGS =-g -mcpu=arm926ej-s
INCS =-I .
LIBS =


#To have incremental building, we need to separate the dependencies.
all: Learn-in-depth.bin
	@echo "Build is complete"

startup.o: startup.s
	$(CC)as.exe $(CFLAGS) startup.s -o startup.o

app.o: app.c
	$(CC)gcc.exe -c $(INCS) $(CFLAGS) app.c -o app.o
	
uart.o: uart.c 
	$(CC)gcc.exe -c $(INCS) $(CFLAGS) uart.c -o uart.o

Learn-in-depth.elf: uart.o app.o startup.o
	$(CC)ld.exe -T linker_script.ld startup.o uart.o app.o -o learn-in-depth.elf -Map=Map_file.map

Learn-in-depth.bin: learn-in-depth.elf
	$(CC)objcopy.exe -O binary learn-in-depth.elf learn-in-depth.bin
	
clear_all: 
	rm *.o *.elf *.bin
	
clear:
	rm *.elf *.bin 