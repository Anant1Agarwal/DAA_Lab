#include<stdio.h>

void swap(int *x, int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

void MinDist(int index, int arr[],int end, int Dist[][end+1],int realPath[]){
    static int Totaldist= INT_MAX;
    if(index==end){
        int CurCovered=0;
        printf("\neles are ");
        for(int i=0;i<=end;i++){

            CurCovered=dist[]
        }
    }

    for(int i=index;i<=end;i++){
        swap(&arr[index],&arr[i]);
        MinDist(index+1,arr,end, Dist,realPath);
        swap(&arr[index],&arr[i]);
    }
}


int main(){
    int n;
    printf("Enter number of destinations:");
    scanf("%d",&n);

    int dest[n][n];
    printf("Enter distances: ");
    for(int i=0;i<n;i<n){
        for(int j=0;j<n;j++){
            if(i==j){
                printf("distance from %d to %d is 0",i+1,j+1);
                dest[i][j]=0;
            }
            else{
                printf(" enter distance from %d to %d :",i+1,j+1);
                scanf("%d",&dest[i][j]);
            }
        }
    }

    printf("Your distance Matrix is:");
    for(int i=0;i<n;i<n){
        for(int j=0;j<n;j++){
           printf("%d ",dest[i][j]);
        }
        printf("\n");
    }
    int temppath[n+1];
    int realpath[n+1];

    for(int i=0;i<n+1;i++){
        temppath[i]=0;
        realpath[i]=0;
    }

    MinDist(1,temppath,n

    
}