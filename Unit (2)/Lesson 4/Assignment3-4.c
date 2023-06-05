#include <stdio.h>
int main(){
    int n = 0;
    int x = 0;
    int y = 0;
    int arr[100];
    printf("Enter number of elements: ");
    scanf("%d", &n);
    for(int i = 1; i <= n ; i++){
        arr[i-1] = i;
    }
    for(int i = 0; i < n ; i++){
    printf("%d ", arr[i]);
    }
    printf("\nEnter the element to be inserted: ");
    scanf("%d", &x);
    printf("Enter the location: ");
    scanf("%d", &y);
    for(int i = 0; i < n ; i++){
        if (i == y - 1){
            for ( int j = y ; j < n + 1; j++){
                arr[j] = j;
             }
             arr[i] = x;
             }
    }
     for(int i = 0; i < n + 1; i++){
        printf("%d ", arr[i]);
     }
}