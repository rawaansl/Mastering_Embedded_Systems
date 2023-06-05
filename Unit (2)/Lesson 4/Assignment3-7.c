#include <stdio.h>
#include <string.h>
int main(){
    char str[100];
    int n = 0;
    printf("Enter a string: ");
    gets(str);
    for (int i = 0; i < strlen(str); i++){
        if(str[i] == 0) break;
        n++;
    }
    printf("Length of string is : %d", n);
}