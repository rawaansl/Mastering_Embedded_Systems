#include <stdio.h>
float power(float n, int x);
int main(){
    float n;
    int x;
    printf("Enter base number: ");
    scanf("%f", &n);
    printf("Enter power number(positive integer): ");
    scanf("%d", &x);
    printf("%.3f^%d equals %.3f", n, x, power(n, x));
}
float power(float n, int x){
    if (x == 0) return 1;
    return n * power(n, x-1);
}