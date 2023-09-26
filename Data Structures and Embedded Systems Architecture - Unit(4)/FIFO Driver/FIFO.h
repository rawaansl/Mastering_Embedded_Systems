#ifndef FIFO_H
#define FIFO_H

#include <stdint.h>

// Define the data type for elements in the Queue (change as needed)
#define element_type uint32_t

// Define the maximum size of the Queue (change as needed)
#define max_size 5

// Define the Queue data structure
typedef struct {
    element_type head;           // Current index of the Queue
    element_type tail;           // Tail index of the Queue
    element_type data[max_size]; // Data array to store Queue elements
    int is_empty;
    int iterate;
} Queue;

// Function to add an item to the Queue
void Enqueue(Queue* FIFO, element_type item);

// Function to initialize the Queue
void FIFO_init(Queue* FIFO);

// Function to view the status of the Queue
void view_status(const Queue* FIFO);

// Function to read (remove) an item from the Queue
element_type Dequeue(Queue* FIFO);

// Function to clear (reset) the Queue
void clear(Queue* FIFO);

// Function to view the buffer contents
void view_FIFO_contents(const Queue* FIFO);

#endif   // FIFO_H

