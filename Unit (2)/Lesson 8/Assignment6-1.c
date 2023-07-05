#include <stdio.h>
int main(){
    int m = 29;
    printf("Address of m : %x\nValue of m: %d", &m, m);
    int* ab = &m;
    printf("\n\nThe address of the pointer ab is: %x\nThe content of the pointer ab is: %d", ab, *ab);
    m = 34;
    printf("\n\nThe address of the pointer ab is: %x\nThe content of the pointer ab is: %d", ab, *ab);
    *ab = 7;
    printf("\n\nAddress of m : %x\nValue of m: %d", &m, m);

}