#include <stdio.h>
int main(){
    char x;
    printf("Enter a character: ");
    scanf("%c", &x);
    int y = x;
    printf("ASCII value of %c is %d", x, y );
}