#include <stdio.h>
#define pi 3.14
int main(){
    float r;
    printf("Enter radius: ");
    scanf("%f", &r);
    printf("Area equals %.2f", pi*r*r);
}