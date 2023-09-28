#include "list.h"
#include <stdio.h>
#include <stdlib.h>

Student* firstRecord = NULL;

// Function to add a new student record to the linked list
void addStudentRecord() {
    Student* newStudent;
    Student* lastStudent;

    // Check if the list is empty
    if (firstRecord == NULL) {
        newStudent = (Student*) malloc(sizeof(Student));
        firstRecord = newStudent;
    } else {
        // Find the last student in the list
        lastStudent = firstRecord;
        while (lastStudent->nextRecord) {
            lastStudent = lastStudent->nextRecord;
        }
        newStudent = (Student*) malloc(sizeof(Student));
        lastStudent->nextRecord = newStudent;
    }
    // Fill in the record data
    fill_record_data(newStudent);
    newStudent->nextRecord = NULL;
}

// Function to fill in student record data
void fill_record_data(Student* p_newStudentData) {
    fflush(stdin);
    printf("Enter Student's name: ");
    gets(p_newStudentData->studentName);
    printf("Enter Student's ID: ");
    scanf("%d", &p_newStudentData->studentID);
    printf("Enter Student's GPA: ");
    scanf("%f", &p_newStudentData->studentGPA);
}

// Function to delete a student record by ID
void deleteRecord() {
    int ID;
    Student* removeRecord = firstRecord;
    Student* previousRecord = NULL; // Track the previous node
    printf("Please enter the Student's ID to be deleted: \n");
    scanf("%d", &ID);

    // Traverse the list to find the record to delete
    while (removeRecord != NULL) {
        if (removeRecord->studentID == ID) {
            // Found the record to delete
            if (previousRecord == NULL) {
                // If it's the first record, update the head
                firstRecord = removeRecord->nextRecord;
            } else {
                // Otherwise, update the previous node's next pointer
                previousRecord->nextRecord = removeRecord->nextRecord;
            }
            // Free the memory of the deleted node
            free(removeRecord);

            // Exit the loop after deleting the record
            break;
        }
        // Move to the next node
        previousRecord = removeRecord;
        removeRecord = removeRecord->nextRecord;
    }

    // Check if the ID was not found
    if (removeRecord == NULL) {
        printf("Student with ID %d not found.\n", ID);
    } else {
        printf("Student with ID %d deleted successfully.\n", ID);
    }
}

// Function to view all student records in the list
void viewRecords() {
    int count = 0;
    if (firstRecord == NULL)
        printf("Empty list, nothing to view\n");

    Student* viewRecord = firstRecord;
    while (viewRecord != NULL) {
        printf("\nStudent record (%d) data:\n", ++count);
        printf("Student Name: %s \n", viewRecord->studentName);
        printf("Student ID: %d \n", viewRecord->studentID);
        printf("Student GPA: %.2f \n", viewRecord->studentGPA);

        viewRecord = viewRecord->nextRecord;
    }
}

// Function to delete all student records in the list
void deleteAllRecords() {
    if (firstRecord == NULL) {
        printf("\nEmpty list, nothing to delete\n");
    } else {
        Student* deleteSelectedRecord = firstRecord;
        while (deleteSelectedRecord) {
            Student* temp = deleteSelectedRecord;
            deleteSelectedRecord = deleteSelectedRecord->nextRecord;
            free(temp);
        }
        firstRecord = NULL;
        printf("All records deleted successfully\n");
    }
}

// Function to get and display the student record at a specified index
void getNth() {
    int indx;
    int count = 0;
    int listSize = 0;
    printf("Enter the required index: \n");
    scanf("%d", &indx);
    Student* size = firstRecord;
    while (size) {
        ++listSize;
        size = size->nextRecord;
    }
    if (indx >= listSize || indx < 0) {
        printf("Chosen index does not exist\n");
    } else if (firstRecord == NULL) {
        printf("\nEmpty list, nothing to view\n");
    } else {
        Student* currentRecord = firstRecord;
        while (currentRecord != NULL) {
            if (indx == count) {
                printf("\nStudent record (%d) data:\n", indx);
                printf("Student Name: %s \n", currentRecord->studentName);
                printf("Student ID: %d \n", currentRecord->studentID);
                printf("Student GPA: %.2f \n", currentRecord->studentGPA);
                break;
            }
            currentRecord = currentRecord->nextRecord;
            count++;
        }
    }
}

// Function to display the size of the linked list
void listSize() {
    int count = 0;
    Student* size = firstRecord;
    while (size) {
        ++count;
        size = size->nextRecord;
    }
    printf("List size equals: %d\n", count);
}

// Function to reverse the linked list
void reverseList() {
    if (firstRecord == NULL) {
        printf("\nEmpty list, nothing to reverse\n");
        return;
    }

    Student* prev = NULL;
    Student* current = firstRecord;
    Student* next = NULL;

    while (current != NULL) {
        next = current->nextRecord; // Store the next node

        // Reverse the pointer direction
        current->nextRecord = prev;

        // Move to the next nodes
        prev = current;
        current = next;
    }

    // Update the head to point to the last node (prev)
    firstRecord = prev;
    printf("\nList reversed successfully\n");
}

// Function to display the menu
void printMenu() {
    printf("\nStudent Records Menu:\n");
    printf("1. Add a Student Record\n");
    printf("2. Delete a Student Record\n");
    printf("3. View Student Records\n");
    printf("4. Delete All records\n");
    printf("5. View data of selected record index\n");
    printf("6. View the size of the list\n");
    printf("7. Reverse the list\n");
    printf("8. Exit\n");
    printf("Enter your choice (1-8): ");
}

