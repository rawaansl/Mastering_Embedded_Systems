#include <stdio.h>
int main(){
    int x = 0;
    int fac = 1;
    printf("Enter an integer: ");
    scanf("%d", &x);
    if (x < 0){
        printf("Factorial does not exist");
        return 0;
    }
    if (x == 0) x = 1;
    if (x > 0){
        for (int i = x; i > 0; i--){
            fac = fac*i;
        }
        }
    printf("%d", fac);
}