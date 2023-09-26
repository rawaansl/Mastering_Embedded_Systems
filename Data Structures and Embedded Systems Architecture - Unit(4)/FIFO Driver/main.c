#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "FIFO.h"

// Function to display the available operations
void new_operation() {
    printf("\nPlease choose an operation for your stack:\n");
    printf("1. Enqueue an item\n");
    printf("2. Dequeue an item\n");
    printf("3. View FIFO status\n");
    printf("4. Clear the buffer\n");
    printf("5. View the FIFO buffer contents\n");
    printf("6. Exit\n");
}

int main() {
    Queue FIFO; // Create a local FIFO variable
    FIFO_init(&FIFO); // Initialize the FIFO
    int i = 0;

    while (1) {
        new_operation(); // Display available operations
        scanf("%d", &i);

        if (i == 1) {
            char addMore = 'y'; // Initialize a character to 'y'

            // Loop to allow adding multiple items until the user decides to stop
            while (addMore == 'y') {
                printf("Enqueue an item to the FIFO buffer: ");
                element_type value;
                scanf("%d", &value); // Read the value
                Enqueue(&FIFO, value); // Add the value to the stack

                printf("Do you want to ENQUEUE more items? (y/n): ");
                scanf(" %c", &addMore); // Read a character (including whitespace)
                if (addMore != 'y' && addMore != 'Y') {
                    break; // Break out of the loop if the user doesn't want to add more
                }
            }
        } else if (i == 2) {
            char removeMore = 'y'; // Initialize a character to 'y'

            // Loop to allow removing multiple items until the user decides to stop
            while (removeMore == 'y') {
                Dequeue(&FIFO); // Dequeue an item
                if(FIFO.head == FIFO.tail) break;
                printf("Do you want to dequeue more items? (y/n): ");
                scanf(" %c", &removeMore); // Read a character (including whitespace)

                if (removeMore != 'y' && removeMore != 'Y') {
                    break; // Break out of the loop if the user doesn't want to remove more
                }
            }
        } else if (i == 3) {
            view_status(&FIFO); // Display the FIFO status
        } else if (i == 4) {
            clear(&FIFO); // Clear the FIFO
        } else if (i==5)   {
            view_FIFO_contents(&FIFO);
        } else if (i == 6) {
            break; // Exit the program
        } else {
            printf("Invalid operation. Please choose a valid operation.\n");
        }
    }
    return 0;
}
