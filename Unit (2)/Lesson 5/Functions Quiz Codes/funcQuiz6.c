#include <stdio.h>
#include <math.h>
int check( int x);
int main(){
    int n;
    printf("Enter the number to be checked: ");
    scanf("%d", &n);
    printf("%d", check(n));
}

int check(int x){
    float i = log(x) / log (3);
    if ( i == trunc(i) ) return 0;
    return 1;
}