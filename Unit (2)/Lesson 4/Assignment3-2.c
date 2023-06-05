#include <stdio.h>
int main(){
    int n = 0;
    float arr[100];
    float sum = 0;
    printf("Enter the number of data: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        printf("Enter number: ");
        scanf("%f", &arr[i] );
        sum = sum + arr[i];
    }
    printf("Average = %.3f", sum/n );
}