#include <stdio.h>
int main(){
    float a, b, c, temp, x;
    printf("Enter three numbers: ");
    scanf("%f\n%f\n%f", &a, &b, &c);
    temp = a > b? a:b ;
    x = temp > c? temp:c ; 
    printf("Largest number is %f", x);
}