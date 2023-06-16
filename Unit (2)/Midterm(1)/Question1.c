#include <stdio.h>
#include <string.h>
int sum(char x[]);
int main(){
    char str[100];
    printf("Enter a number: ");
    gets(str);
    printf("Sum of digits equals %d", sum(str));
}

int sum(char x[]){
    int sum = 0;
    for (int i = 0; i < strlen(x) ; i++){
        sum += x[i] - '0';
    }
    return sum;
}