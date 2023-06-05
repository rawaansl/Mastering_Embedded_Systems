#include <stdio.h>
#include <string.h>
int main(){
    char str[100];
    char x;
    int n = 0;
    printf("Enter a string: ");
    gets(str);
    printf("Enter a character to find frequency: ");
    scanf("%c", &x);
    for (int i = 0; i < strlen(str); i++){
        if(str[i] == x)
        n++;
    }
    printf("Frequency of %c is %d", x, n);
}