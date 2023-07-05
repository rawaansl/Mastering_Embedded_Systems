#include <stdio.h>
int main(){
    int arr[15];
    int size;
    int* p = arr;
    printf("Enter the number of elements to store in the array: ");
    scanf("%d", &size);
    printf("Input %d elements of the array: \n", size);
    for(int i = 1; i <= size ; i++){
        printf("element %d : ", i);
        scanf("%d", p);
        ++p;
    }
    p--;
    printf("\nElements of the array in reversed order: ");
    for(int i = 1; i <= size; i++){
    printf("\nelement %d : %d", i, *p);
    p--;
    }
}
//we can also have an additional array to store the elements in reverse 