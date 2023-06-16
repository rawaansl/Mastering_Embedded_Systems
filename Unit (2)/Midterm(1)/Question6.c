#include <stdio.h>
int unique(int arr[], int size);
int main(){
    int arr[100];
    int size;
    printf("Enter size of the array: ");
    scanf("%d", &size);
    printf("Enter the array elements: ");
    for(int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    } 
    printf("Unique element is %d", unique(arr, size));
}

int unique(int arr[], int size){
    int x = 0;
    for(int i = 0; i < size ; i++){
        x ^= arr[i];
    }
return x;
}
