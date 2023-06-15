#include <stdio.h>
void swap (int arr1[], int arr2[], int size1, int size2);
void printarray (int arr[], int size);

int main(){
    int size1, size2, arr1[100], arr2[100];
    printf("Enter the size of the first array: ");
    scanf("%d", &size1);
    printf("Enter the size of the second array: ");
    scanf("%d", &size2);
    swap(arr1, arr2, size1, size2);
    printf("\nFirst array after swapping: ");
    printarray(arr1, size2);
    printf("\nSecond array after swapping: ");
    printarray(arr2, size1);

}

void swap (int arr1[], int arr2[], int size1, int size2){
int size = size1 > size2? size1 : size2;
int temp;
printf("Enter the first array: ");
for (int i = 0; i < size1; i++){
    scanf("%d", &arr1[i]);
}
printf("Enter the second array: ");
for (int i = 0; i < size2; i++){
    scanf("%d", &arr2[i]);
}
for (int i = 0; i < size; i++){
    temp = arr1[i];
    arr1[i] = arr2[i];
    arr2[i] = temp;
}
}

void printarray (int arr[], int size){
for (int i = 0; i < size; i++){
    printf("%d ", arr[i] );
}
}
