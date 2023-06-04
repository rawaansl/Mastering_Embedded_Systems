#include <stdio.h>
int main() {
    char x;
    float a, b;
    printf("Enter an operator either + or - or * or /: ");
    scanf("%c", &x);
    printf("Enter two operands: ");
    scanf("%f %f", &a, &b);
    switch (x){
        case '+':
        printf("%f + %f = %f", a, b, a + b);
        break;
        case '-':
        printf("%f - %f = %f", a, b, a - b);
        break;
        case '*':
        printf("%f * %f = %f", a, b, a * b);
        break;
        case '/':
        printf("%f / %f = %f", a, b, a / b);
        break;
        default:
        printf("Not an operator");
        break;
    }
}