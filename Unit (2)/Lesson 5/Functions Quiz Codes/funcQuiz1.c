#include <stdio.h>
int func(int x, int y);
int main(){
    int x;
    int y;
    printf("Input number: ");
    scanf("%d", &x);
    printf("Bit position: ");
    scanf("%d", &y);
    printf("Result: %d", func(x, y));
}

int func( int x, int y){
    return x &~ 1 << y;
}
