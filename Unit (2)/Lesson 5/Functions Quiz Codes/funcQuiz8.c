#include <stdio.h>
#include <stdlib.h>
void ascii_to_int(char arr[]);
int main(){
    char arr[100];
    printf("Enter the ASCII array: ");
    gets(arr);
    ascii_to_int(arr);
    
}
void ascii_to_int(char arr[]){
    int n = atoi(arr);
    if (n < 65535)   //maximum of unsigned int
     printf("%d", n);
    else printf("Exceeds range");
}