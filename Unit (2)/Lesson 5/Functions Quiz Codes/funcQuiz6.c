#include <stdio.h>
int check( int x);
int main(){
    int n;
    printf("Enter the number to be checked: ");
    scanf("%d", &n);
    printf("%d", check(n));
}

int check(int x){
    if(x % 3 == 0) return 0;
    return 1;
}