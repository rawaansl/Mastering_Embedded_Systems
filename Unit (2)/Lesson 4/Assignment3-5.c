#include <stdio.h>
int main(){
    int arr[100];
    int n = 0;
    int x = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    for(int i = 1; i <= n ; i++){
        arr[i-1] = i*11;
    }
    for(int i = 0; i < n ; i++){
    printf("%d ", arr[i]);
    }
    printf("\nEnter the element to be searched: ");
    scanf("%d", &x);
    for (int i = 0; i < n; i++){
        if (x == arr[i])
        printf("Number found at the location = %d", i+1);
    }
}