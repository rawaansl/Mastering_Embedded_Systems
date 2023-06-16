#include <stdio.h>

int ones(int x);

int main() {
    int x;
    printf("Enter number: ");
    scanf("%d", &x);
    printf("Number of 1s is %d", ones(x));
    return 0;
}

int ones(int x) {
    int temp[32];
    for (int i = 31; i >= 0; i--) {
        if ((x >> i) & 1)
            temp[i] = 1;
        else
            temp[i] = 0;
    }
    int sum = 0;
    for (int i = 31; i >= 0; i--) {
        sum += temp[i];
    }
    return sum;
}
