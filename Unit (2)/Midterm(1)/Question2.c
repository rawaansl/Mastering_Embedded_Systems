#include <stdio.h>
float sqrt(float x);
int main(){
    float x;
    printf("Enter the number: ");
    scanf("%f", &x);
    printf("The square root of %.3f is %.3f", x, sqrt(x));
}

float sqrt(float x){
    int n = x;
    while(x * x - n > 0.001){
        x = (x + (n / x)) / 2;
    }
    return x;

}