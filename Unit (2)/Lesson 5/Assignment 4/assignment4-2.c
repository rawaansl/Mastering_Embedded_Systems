#include <stdio.h>
int fac(int x);
int main(){
    int x;
    printf("Enter a positive integer: ");
    scanf("%d", &x);
    printf("Factorial of %d is %d", x, fac(x));
}

int fac(int x){
    int f = 1;
    f = f*x;
    if (x == 1) return f;
    return f * fac(x-1);
}