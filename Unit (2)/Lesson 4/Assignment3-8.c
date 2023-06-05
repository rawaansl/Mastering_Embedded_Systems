#include <stdio.h>
#include <string.h>
int main(){
    char str[100];
    char temp;
    printf("Enter a string: ");
    gets(str);
    for(int i = 0; i < strlen(str) / 2; i++){
        if (str[i] == 0) break;
        temp = str[i];
        str[i] = str[(strlen(str) - 1 - i)];
        str[(strlen(str) - 1 - i)] = temp;
        }
    printf("Reversed String is: %s ", str);
}