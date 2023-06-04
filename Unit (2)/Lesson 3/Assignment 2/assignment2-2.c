#include <stdio.h>
int main(){
    char x;
    char y[10] = {'i', 'I', 'e', 'E', 'a', 'A', 'O', 'o', 'U', 'u'};
    printf("Enter an alphabet: ");
    scanf("%c", &x);
    for (int i = 0; i < 10; i++ )
    {
        if (x == y[i])
        {
        printf("%c is a vowel", x);
        return 0;
        }
    }
    printf("%c is a consonant", x);
}