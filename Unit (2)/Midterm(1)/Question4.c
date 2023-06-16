#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int reverse(char x[]);
int main(){
    char x[100];
    printf("Enter number: ");
    gets(x);
    printf("Reverse is %d", reverse(x));
}

int reverse(char x[]){
    for (int i = 0; i < strlen(x) / 2 ; i++){
        int temp = x[i];
        x[i] = x[strlen(x) - i - 1];
        x[strlen(x) - 1 - i] = temp;
    }
   return atoi(x);
}