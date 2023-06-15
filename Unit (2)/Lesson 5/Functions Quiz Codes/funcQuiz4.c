#include <stdio.h>
int fourth_bit(int x);
int main(){
    int x, bit;
    printf("Enter the number: ");
    scanf("%d", &x);
    bit = fourth_bit(x);
    printf("The fourth bit of the number %d is %d", x, bit);
}

int fourth_bit(int x){
    return (x >> 3) & 1;
}
