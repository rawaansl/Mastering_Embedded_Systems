#include <stdio.h>
struct Semployee{
    int ID;
    char name[20];
    };
    
int main(){
    //first create objects
    struct Semployee e1 = {100, "Rawan"}, e2 = {101, "Alex"}, e3 = {102, "Sleem"};
    struct Semployee(*arr[]) = {&e1, &e2, &e3};   //array of pointers to the three objects
    struct Semployee (*(*p)[3]) = &arr;           //pointer p points to an array of three elements of pointers to structures
    printf("Employee name: %s", (**(*p+1)).name);
    printf("\nEmployee ID: %d", (**(*p+1)).ID );
}
