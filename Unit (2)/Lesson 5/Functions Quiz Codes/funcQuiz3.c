#include <stdio.h>
#include <string.h>
void check (char name[], char user_name[]) ;
int main(){
    char name[100];
    char user_name[100];
    printf("Enter name: ");
    fgets(name, 100, stdin);
    printf("Enter username: ");
    fgets(user_name, 100, stdin);
    check(name, user_name);
}

void check(char name[], char user_name[]){
    int n;
    n = strcasecmp(name, user_name);
    if (n == 0) printf("The same");
    else printf("Different");
}