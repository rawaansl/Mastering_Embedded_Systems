#include "LIFO.h"

// Function to initialize the stack
void Stack_init(LIFO_Stack* stack_p) {
    stack_p->base = stack_p->data;       // Set the base pointer to the stack data array
    stack_p->top = 0;                    // Initialize the stack index
}

// Function to remove an item from the stack
element_type Pop(LIFO_Stack* stack) {
    if (stack->top == 0){
        printf("Error: Stackunderflow. Nothing to pop.\n");
    } 
    else {
        return stack->data[--(stack->top)];
    }
}

// Function to push an item to the stack
void Add(LIFO_Stack* stack, element_type item) {
    if (stack->top >= max_size){
        printf("Error: Stackoverflow. Cannot add an item.\n");
    } 
    else {
        stack->data[(stack->top)++] = item;
    }
}

// Function to view the stack status
void view_status(const LIFO_Stack* stack) {
    if (stack->top == 0) {
        printf("Stack is empty");
    } else if (stack->top >= max_size) {
        printf("Stack is full");
    } else {
        printf("Stack is normal");
    }
}

// Function to clear the stack (similar to reinitializing it, overwriting existing data)
void clear(LIFO_Stack* stack){
    if (stack->top == 0){
        printf("Stack is already cleared\n");
    } 
    else {
        stack->base = stack->data;       
        stack->top = 0; 
        printf("Stack is cleared\n");
    }
}

// Function to view the size of the stack (number of stored elements)
void size(const LIFO_Stack* stack){
    int count = stack->top;
    printf("Total number of stored elements equal: %d\n", count);
}

// Function to view the stack contents
int view_stack(const LIFO_Stack* stack){
    int count = stack->top;
    for(int i = --count; i >= 0; i--){
        printf("%d\n", stack->data[i]);
    }
}
