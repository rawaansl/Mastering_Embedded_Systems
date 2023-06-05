#include <stdio.h>
int main(){
    int x, y = 0;
    float mat[100][100];
    float tran_mat[100][100];
    printf("Enter rows and columns of matrix:");
    scanf("%d %d", &x, &y);
    printf("Enter elements of matrix:\n");
    for (int i = 0; i < x; i++ ){
        for(int j = 0; j < y; j++){
            printf("Enter element a%d%d: ", i, j);
            scanf("%f", &mat[i][j]);
            tran_mat[j][i] = mat[i][j];
        }
    }
    printf("Entered matrix:\n");
    for (int i = 0; i < x; i++ ){
         for(int j = 0; j < y; j++){
            printf("%.3f ", mat[i][j]);
            if (j == y - 1) printf("\n\n");
         }
    }
    printf("Transpose matrix:\n");
    for (int i = 0; i < y; i++ ){
         for(int j = 0; j < x; j++){
            printf("%.3f ", tran_mat[i][j]);
            if (j == x - 1) printf("\n\n");
         }
    }
}

        

    