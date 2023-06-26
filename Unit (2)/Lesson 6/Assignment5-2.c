#include <stdio.h>
struct Sdistance{
    int feet;
    float inch;
};
int main(){
    struct Sdistance distance1;
    struct Sdistance distance2;
    struct Sdistance S;
    printf("Enter information of first distance: \nEnter feet: ");
    scanf("%d", &distance1.feet);
    printf("Enter inch: ");
    scanf("%f", &distance1.inch);
    printf("Enter information of second distance: \nEnter feet: ");
    scanf("%d", &distance2.feet);
    printf("Enter inch: ");
    scanf("%f", &distance2.inch);
    S.feet = distance1.feet + distance2.feet;
    S.inch = distance1.inch + distance2.inch;
    if (S.inch > 12) {
        S.inch = S.inch - 12;
        ++S.feet;   //12 inches equal one foot
    }
    printf("Sum of distances equals %d-%.3f", S.feet , S.inch);

}