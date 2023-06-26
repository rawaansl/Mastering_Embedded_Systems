#include <stdio.h>
struct Student {
    int roll;
    char name[50];
    int mark;
};

int main() {
    struct Student student[10];

    printf("Enter data of students:\n");
    for (int i = 0; i < 10; i++) {
        printf("\nFor roll number: ");
        scanf("%d", &student[i].roll);
        getchar();

        printf("Enter name: ");
        fgets(student[i].name, sizeof(student[i].name), stdin);

        printf("Enter mark: ");
        scanf("%d", &student[i].mark);
    }

    printf("\nDisplaying information of students:\n");
    for (int i = 0; i < 10; i++) {
        printf("\nInformation for roll number %d\n", student[i].roll);
        printf("Name: %s", student[i].name);
        printf("Mark: %d\n", student[i].mark);
    }
}
