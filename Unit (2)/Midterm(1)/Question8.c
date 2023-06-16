#include <stdio.h>
void reverse(int arr[], int size);
void printarray (int arr[], int size);
int main(){
    int arr[10];
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    printf("Enter the array: ");
    for(int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }
    reverse(arr, size);
    printf("The array after reversing: ");
    printarray(arr, size);
}

void reverse(int arr[], int size){
    int temp;
    for (int i = 0; i < size/2; i++){
        temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;

    }
}
void printarray (int arr[], int size){
for (int i = 0; i < size; i++){
    printf("%d ", arr[i] );
}
}

