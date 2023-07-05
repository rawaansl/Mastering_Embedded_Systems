#include <stdio.h>
#include <string.h>
int main(){
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char* p = alphabet;
    for (int i = 0; i < strlen(alphabet); i++){
        printf("%c ", *(p+i));
    }
}