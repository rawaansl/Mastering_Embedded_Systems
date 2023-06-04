#include <stdio.h>
int main(){
    int x, y;
    printf("Enter two integers: ");
    scanf("%d %d", &x, &y);
    int z = x + y;
    printf("Sum: %d ", z);
}