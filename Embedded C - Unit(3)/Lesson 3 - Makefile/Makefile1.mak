#@copyright : Rawan Sleem
#Makefile1

#By specifying the Windows Command Prompt (cmd.exe) as the shell, 
#you ensure that Make uses a shell that is compatible with Windows commands.
#This can resolve issues related to the use of Unix-like commands like rm in a Windows environment.

SHELL=C:/Windows/System32/cmd.exe

 variables to control the C compiler and compiler flags, respectively. These variables allow you to customize how your C code is compiled. Here's what they commonly represent:


#write all the dependencies 
Learn-in-depth.bin: uart.c app.c startup.s
	arm-none-eabi-gcc.exe -c -I . -g -mcpu=arm926ej-s uart.c -o uart.o
	arm-none-eabi-gcc.exe -c -I . -g -mcpu=arm926ej-s app.c -o app.o
	arm-none-eabi-as.exe -mcpu=arm926ej-s -g startup.s -o startup.o
	arm-none-eabi-ld.exe -T linker_script.ld startup.o uart.o app.o -o learn-in-depth.elf -Map=Map_file.map
	arm-none-eabi-objcopy.exe -O binary learn-in-depth.elf learn-in-depth.bin

clear_all: 
	rm *.o *.elf *.bin
	
clear:
	rm *.elf *.bin 
	
	
	