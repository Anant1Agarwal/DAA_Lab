#include <stdio.h>
#include <stdlib.h>

int opcount = 0;

void matrixMultiplication(int a[][],int b[][], int c[][]){

}


int main(){
    int m1,n1,m2,n2;
    printf("Enter number of rows in matrix 1:");
    scanf("%d",&m1);
    printf("Enter number of columns in matrix 1:");
    scanf("%d",&n1);

    printf("Enter number of rows in matrix 2:");
    scanf("%d",&m2);
    printf("Enter number of columns in matrix 2:");
    scanf("%d",&n2);

    if(n1!=m2){
        printf("Matrix Multiplication not possible!");
        return 0;
    }

    int a[m1][n1];
    int b[m2][n2];
    int c[m1][n2]; 

    printf("Enter Elements in matrix 1:"):
    for(int i=0;i<m1;i++){
        for(int j=0;j<n1;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter Elements in matrix 2:"):
    for(int i=0;i<m2;i++){
        for(int j=0;j<n2;j++){
            scanf("%d",&b[i][j]);
        }
    }

    matrixMultiplication(a[m1][n1],b[m2][n2],c[m1][n2]);
    printf("Resultant Matrix is :"):
    for(int i=0;i<m1;i++){
        for(int j=0;j<n2;j++){
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }

    
}