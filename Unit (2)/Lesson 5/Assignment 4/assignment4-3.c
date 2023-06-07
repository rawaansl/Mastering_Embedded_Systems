#include <stdio.h>
#include <string.h>
void reverse(char x[]);
int main(){
    char sen[100];
    printf("Enter a sentence: ");
    gets(sen);
    reverse(sen);
}
void reverse(char x[]){
    if (x[0] == 0) return;
    printf("%c", x[strlen(x)-1]);
    x[strlen(x)-1] = 0;
    reverse(x);
}

