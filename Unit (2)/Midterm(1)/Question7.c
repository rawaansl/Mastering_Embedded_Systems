#include <stdio.h>
int sum(int n);
int main(){
    printf("Sum of numbers from 1 to 100 is %d", sum(1));
}


int sum(int n){
    if (n > 100) return 0;
    else return n + sum(n + 1);
}