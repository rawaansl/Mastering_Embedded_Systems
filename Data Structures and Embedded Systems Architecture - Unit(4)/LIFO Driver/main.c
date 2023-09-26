#include <stdio.h>
#include <stdint.h>
#include "LIFO.h"

// Function to display the available operations
void new_operation() {
    printf("\nPlease choose an operation for your stack:\n");
    printf("1. Add an item\n");
    printf("2. Pop an item\n");
    printf("3. View stack status\n");
    printf("4. Clear the stack\n");
    printf("5. View stack size\n");
    printf("6. View stack\n");
    printf("7. Exit\n");
}

int main() {
    LIFO_Stack stack; // Create a local LIFO_Stack variable
    Stack_init(&stack); // Initialize the stack
    int i = 0;

    while (1) {
        new_operation(); // Display available operations
        scanf("%d", &i);

        if (i == 1) {
            char addMore = 'y'; // Initialize a character to 'y'

            // Loop to allow adding multiple items until the user decides to stop
            while (addMore == 'y') {
                printf("Add an item to the stack: ");
                element_type value;
                scanf("%d", &value); // Read the value
                Add(&stack, value); // Add the value to the stack

                printf("Do you want to add more items? (y/n): ");
                scanf(" %c", &addMore); // Read a character (including whitespace)
                if (addMore != 'y' && addMore != 'Y') {
                    break; // Break out of the loop if the user doesn't want to add more
                }
            }
        } else if (i == 2) {
            char removeMore = 'y'; // Initialize a character to 'y'

            // Loop to allow removing multiple items until the user decides to stop
            while (removeMore == 'y') {
                Pop(&stack);
                if (stack.top == 0){
                    view_status(&stack); // Display the stack status
                    break;
                }
                   
                printf("Do you want to pull more items? (y/n): ");
                scanf(" %c", &removeMore); // Read a character (including whitespace)
                if (removeMore != 'y' && removeMore != 'Y') {
                    break; // Break out of the loop if the user doesn't want to remove more
                }
            }
        } else if (i == 3) {
            view_status(&stack); // Display the stack status
        } else if (i == 4) {
            clear(&stack); // Clear the stack
        } else if (i == 5) {
            size(&stack); // Display the stack size
        } else if (i == 6) {
            view_stack(&stack); // Display the stack contents
        } else if (i == 7) {
            break; // Exit the program
        } else {
            printf("Invalid operation. Please choose a valid operation.\n");
        }
    }

    return 0;
}
