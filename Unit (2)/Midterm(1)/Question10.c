#include <stdio.h>

int max_ones(int x);

int main() {
    int x;
    printf("Enter number: ");
    scanf("%d", &x);
    printf("Maximum number of ones between two zeroes is %d", max_ones(x));
    return 0;
}

int max_ones(int x) {
    int ones_count = 0;
    int max_count = 0;
    int temp[32];
    for (int i = 31; i >= 0; i--) {
        if ((x >> i) & 1)
            temp[i] = 1;
        else
            temp[i] = 0;
    }
    for(int i = 0; i < 32; i++){
        if (temp[i] == 1){
            ones_count++;
        }
        else if (ones_count > max_count){
            max_count = ones_count;
            ones_count = 0;
        }
    }
   return max_count;
}
