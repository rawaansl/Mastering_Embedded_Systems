//a method to configure a register with all its ports using typedef
//using the header file of stdint
//this method of register configuraton can be used inside a header file for all the used registers for all the modules
#include <stdio.h>
#include <stdint.h>
typedef volatile uint32_t vuint32_t;
typedef union{                   //to have a shared memory
    vuint32_t ALLPORTS;
    struct Sregister{
        vuint32_t PORTA:8;       //one byte for each port
        vuint32_t PORTB:8;     
        vuint32_t PORTC:8;     
        vuint32_t PORTB:8;    
    }REG_FIELDS;
}REG;


int main(){
    volatile REG* ports = (volatile REG*)0x5555;  //a pointer of the same data type to the register address
    ports->ALLPORTS = 0xFFFFFFFF;                 //to access all the ports (the whole register)
    ports->REG_FIELDS.PORTA = 0XFFFF;             //to access a certain port
}
