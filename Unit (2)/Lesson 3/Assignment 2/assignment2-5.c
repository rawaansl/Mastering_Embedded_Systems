#include <stdio.h>
int main(){
    char x;
    printf("Enter a character: ");
    scanf("%c", &x);
    if ((x>='a' && x<='z') || (x>='A' && x<='Z'))
    printf("%c is an alphabet", x);
    else
    printf("%c is not an alphabet", x);
}