//Another solution for question (3)
//use pointers entirly without using the string library 
#include <stdio.h>
int main(){
    char str[20];
    char* p = str;
    char reverse[20];   //an empty array to store the reversed string
    char* rev = reverse;
    
    int i = -1;
    printf("Input the string: ");
    scanf("%s", str);
    while(*p != 0){
        i++;
        p++;            //to know the length of the string without using strlen()
    }
    //after the above while loop, we have the pointer located at the last element of the array(the null character)

    while (i >= 0){
        p--;           //to go to the last character before the null
        *rev = *p;
        rev++;
        --i;           //must be post decrement
    }
    *rev = '\0';       //manually terminate the string

    printf("%s", reverse);
}