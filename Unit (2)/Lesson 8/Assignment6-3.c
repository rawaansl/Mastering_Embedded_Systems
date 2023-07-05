#include <stdio.h>
#include <string.h>
int main(){
     char str[10];
     printf("Input string: ");
     gets(str);
     char* p = &str[(strlen(str) - 1)];
     printf("Reverse of the string is: ");
     for (int i = 0; i < strlen(str); i++){
        printf("%c", *p);
        p--;
     }
}