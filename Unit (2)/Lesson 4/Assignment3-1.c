#include <stdio.h>
int main(){
    float mat_1[2][2];
    float mat_2[2][2];
    float sum[2][2];
    printf("Enter the elements of the first matrix:\n");
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2 ;j++){
            printf("Enter a%d%d: ", i, j);
            scanf("%f", &mat_1[i][j] );
        }
    }
    printf("Enter the elements of the second matrix:\n");
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2 ;j++){
            printf("Enter b%d%d: ", i, j);
            scanf("%f", &mat_2[i][j] );
        }
    }
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2 ;j++){
            sum[i][j] = mat_1[i][j] + mat_2[i][j];
            } 
    }
    printf("Sum of matrix :\n%f %f\n%f %f", sum[0][0], sum[0][1], sum[1][0], sum[1][1] );

}