#include <stdio.h>
#include <string.h>
void reverse(char x[]);
int main(){
    char x[100];
    printf("Input : ");
    gets(x);
    reverse(x);
}

void reverse(char x[]){
    for (int i = 0; i < strlen(x) / 2 ; i++){
        int temp = x[i];
        x[i] = x[strlen(x) - i - 1];
        x[strlen(x) - 1 - i] = temp;
    }
   printf("Reverse is %s", x);
}