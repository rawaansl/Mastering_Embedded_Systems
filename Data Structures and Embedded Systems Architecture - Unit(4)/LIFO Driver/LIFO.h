#ifndef LIFO_H
#define LIFO_H
#include <stdint.h>

// Define the data type for elements in the stack (change as needed)
#define element_type uint32_t

// Define the maximum size of the LIFO stack (change as needed)
#define max_size 10

// Define the LIFO stack data structure
typedef struct {
    element_type top;           // Current index of the stack
    element_type* base;         // Pointer to the base of the stack
    element_type data[max_size]; // Data array to store stack elements
} LIFO_Stack;

// Function to add an item to the LIFO stack
void Add(LIFO_Stack* stack, element_type item);

// Function to initialize the LIFO stack
void Stack_init(LIFO_Stack* stack);

// Function to view the status of the LIFO stack
void view_status(const LIFO_Stack* stack);

// Function to pop (remove) an item from the LIFO stack
element_type Pop(LIFO_Stack* stack);

// Function to clear (reset) the LIFO stack
void clear(LIFO_Stack* stack);

// Function to get the size (number of stored elements) of the LIFO stack
void size(const LIFO_Stack* stack);

// Function to view the contents of the LIFO stack
int view_stack(const LIFO_Stack* stack);

#endif
