#include "FIFO.h"
#include <stdio.h>

// Function to initialize the circular FIFO
void FIFO_init(Queue* FIFO) {
    FIFO->tail = 0;          // Initialize the tail pointer to point to the beginning of the FIFO data array
    FIFO->head = 0;          // Initialize the FIFO index (head) to zero
    FIFO->is_empty = 1;
    FIFO->iterate = 0;
}


// Function to remove an item from the FIFO (Dequeue)
element_type Dequeue(Queue* FIFO) {
    if (FIFO->is_empty) {
        printf("FIFO empty, nothing to read.\n");
        return 0; // You may want to return a special value to indicate an error.
    } else {
        element_type item = FIFO->data[FIFO->tail];
        FIFO->tail = (FIFO->tail + 1) % max_size; // Increment the tail with wrap-around
        return item;
    }
}

// Function to add an item to the FIFO (Enqueue)
void Enqueue(Queue* FIFO, element_type item) {
    FIFO->data[FIFO->head] = item;
    FIFO->head++;
    if (FIFO->head == max_size) {
        printf("FIFO buffer is full, WARNING: overwrite\n");
        FIFO->head = 0;
        FIFO->iterate++;
    }
    FIFO->is_empty = 0;
}

// Function to view the FIFO status
void view_status(const Queue* FIFO) {
    if (FIFO->is_empty) {
        printf("FIFO buffer is empty\n");
    } else if ((FIFO->head + 1) == FIFO->tail) {
        printf("FIFO buffer is full, WARNING: overwrite\n");
    } else {
        printf("FIFO buffer is normal\n");
    }
}

// Function to clear the FIFO (similar to reinitializing it, overwriting existing data)
void clear(Queue* FIFO) {
    if (FIFO->head == FIFO->tail) {
        printf("FIFO buffer is already cleared\n");
    } else {
        FIFO->tail = 0;
        FIFO->head = 0;
        FIFO->is_empty = 1;
        FIFO->iterate = 0;
        printf("FIFO buffer is cleared\n");
    }
}


void view_FIFO_contents(const Queue* FIFO) {
    int count = FIFO->tail;

    if(FIFO->is_empty) {
            view_status(FIFO);
            return;
    }

    // Handle wrap-around for circular buffer
    printf("Buffer Contents:\n");
    if (FIFO->tail < FIFO->head && FIFO->iterate!=0) {
        for (int i = FIFO->head; i < max_size; i++) {
            printf("%d\n", FIFO->data[i]);
        }
        for (int i = FIFO->tail; i < FIFO->head; i++){
            printf("%d\n", FIFO->data[i]);
        }
    }
    else if (FIFO->tail < FIFO->head) {
        for (int i = FIFO->tail; i < FIFO->head; i++){
            printf("%d\n", FIFO->data[i]);
        }
    }
    else if (FIFO->head == FIFO->tail) {
            for(int i = count; i < max_size; i++){
                printf("\n%d\n", FIFO->data[i]);
            }
    }
    else if (FIFO->head < FIFO->tail) {
    for (int i = count; i < max_size; i++) {
        printf("\n%d\n", FIFO->data[i]);
    }
    for (int i = 0; i < FIFO->head; i++){
        printf("\n%d\n", FIFO->data[i]);
    }
    }
}
