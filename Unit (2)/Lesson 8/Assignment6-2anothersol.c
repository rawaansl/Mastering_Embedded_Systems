//another solution for question (2)
#include <Stdio.h>
int main(){
    //we need to have an array filled with the alphabets using a pointer, and print its elements using a pointer
    char alphabet[26];
    char* p = alphabet;   //the pointer reserves the location of the first element in the array
    for(int i = 0; i < 26; i++){
        *p = 'A' + i;     //issue a write operation in the elements locations of the empty array
        p++;              //go the next element location
    }
    p = alphabet;         //reinitialize the pointer to the beggining of the array
    printf("The alphabets are: ");
    for(int i = 0; i < 26; i++){
        printf("%c ", *p);
        p++;
    }
}