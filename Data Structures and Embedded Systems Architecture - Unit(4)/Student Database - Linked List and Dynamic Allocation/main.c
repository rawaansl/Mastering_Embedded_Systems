#include <stdio.h>
#include <stdlib.h>
#include "list.h"


int main(){

    while(1){
        int choice;
        printMenu();
        scanf("%d", &choice);
        fflush(stdin);
        switch(choice){
        case(1):
            addStudentRecord();
            break;
        case(2):
            deleteRecord();
            break;
        case(3):
            viewRecords();
            break;
        case(4):
            deleteAllRecords();
            break;
        case(5):
            getNth();
            break;
        case(6):
            listSize();
            break;
        case(7):
            reverseList();
            break;
        case(8):
            return 0;
        default:
            printf("Not a valid choice");
            break;
        }
    }
    return 0;
}

