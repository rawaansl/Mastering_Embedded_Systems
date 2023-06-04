#include <stdio.h>
int main(){
    float x;
    printf("Enter a number: ");
    scanf("%f", &x);
    if (x > 0)
        printf(" %f is positive", x);
    else if (x == 0)
        printf(" You entered zero");
    else
        printf(" %f is negative", x);
}