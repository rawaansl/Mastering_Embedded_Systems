#include <stdio.h>
#include <string.h>
int indx(int x, int arr[], int size);
int main(){
    int arr[100];
    int size;
    int x;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    printf("Array = ");
    for (int i = 0; i < size ; i++){
        scanf("%d", &arr[i]);
    }
    printf("The number: ");
    scanf("%d", &x);
    printf("The index is %d", indx(x, arr, size) );
}


int indx(int x, int arr[], int size){
    int n = 0;
    for (int i = 0; i < size; i++){
        if ( arr[i] == x )
            n = i;
    }
    if (n == 0) return -1;
    return n;
}