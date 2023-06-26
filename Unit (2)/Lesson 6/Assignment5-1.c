#include <stdio.h>
struct Sstudent
{
    char name[50];
    int roll;
    float mark;
};


int main(){
    struct Sstudent s;
    printf("Enter information of student\n");
    printf("Enter name: ");
    gets(s.name);
    printf("Enter roll: ");
    scanf("%d", &s.roll);
    printf("Enter mark: ");
    scanf("%f", &s.mark);
    printf("\nDisplaying Information\n");
    printf("Name: %s\nRoll: %d\nMark: %.3f\n", s.name, s.roll, s.mark);

}