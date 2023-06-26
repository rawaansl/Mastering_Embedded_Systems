#include <stdio.h>
struct Scomplex{
    float real;
    float imj;
}C1, C2;

void add(struct Scomplex C1, struct Scomplex C2){
    printf("Sum equals %.3f+%.3fi", C1.real + C2.real, C1.imj + C2.imj);
}

int main(){
    printf("For first number:\nEnter real and imajinary numbers respectively: ");
    scanf("%f %f", &C1.real, &C1.imj);
    printf("For second number:\nEnter real and imajinary numbers respectively: ");
    scanf("%f %f", &C2.real, &C2.imj);
    add(C1, C2);
}