#include <stdio.h>
void prime_num(int x, int y);
int check(int x);
int main(){
    int x, y;
    printf("Enter two numbers : ");
    scanf("%d %d", &x, &y);
    printf("Prime numbers between %d and %d are: ", x, y);
    prime_num(x, y);
}
int check(int x)
{
    for (int i = 2; i < x; i++) {
        if (x % i == 0) {
            return 0;
        }
    }
    return 1;
}
void prime_num(int x, int y){
    for ( int i = x + 1; i < y; i++){
    if(check(i)) printf("%d ", i);
    }
}

    