
/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Rawan Sleem
 * @brief          : Main program body
 */

#include <stdint.h>

#define SYSCTL_RCGC2_R   (*(volatile uint32_t*)(0x400FE108))       // Address of the control register RCGC2
#define GPIOF 0x40025000                                           // Base address of the GPIOF peripheral
#define GPIOF_DEN (*(volatile uint32_t*)(GPIOF + 0x51C))           // Address of the DEN register
#define GPIOF_DIR (*(volatile uint32_t*)(GPIOF + 0x400))           // Address of the DIR register
#define GPIOF_DR  (*(volatile uint32_t*)(GPIOF + 0x3FC))           // Address of the data register

typedef union {
    uint32_t all_bits;
    struct {
        volatile uint32_t reserved:3;
        volatile uint32_t pin4:1;
    } pin;
} REG;

int main(void) {
	
    // Enable clock for GPIOF by setting bit 5 in RCGC2
    SYSCTL_RCGC2_R |= 0x00000020;

    // Delay for a short period to ensure the clock is stable
    for (int i = 0; i < 500; i++);

    // Define pointers to access GPIOF registers
		volatile REG *REG1 = (volatile REG*)&GPIOF_DIR;
		volatile REG *REG2 = (volatile REG*)&GPIOF_DEN;
		volatile REG *REG3 = (volatile REG*)&GPIOF_DR;

    // Set pin 4 of GPIOF as output (DIR)
    REG1->pin.pin4 = 1;

    // Enable digital I/O on pin 4 of GPIOF (DEN)
    REG2->pin.pin4 = 1;

    while (1) {
        // Turn on pin 4 of GPIOF (DR)
        REG3->pin.pin4 = 1;

        // Delay for a short period
        for (int i = 0; i < 5000; i++);

        // Turn off pin 4 of GPIOF
        REG3->pin.pin4 = 0;

        // Delay for a short period
        for (int i = 0; i < 5000; i++);
    }
    return 0;
}
