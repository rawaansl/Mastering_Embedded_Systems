#include <stdio.h>
int main(){
    int n = 0;
    printf("Enter an integer: ");
    scanf("%d", &n);
    int sum = 0;
    for( int i = 1; i <= n; i++){
        sum = sum + i;
    }
    printf("Sum = %d", sum);
}