#include <stdio.h>
#include <stdlib.h>

int opcount = 0;
void merge(int arr[],int l, int m, int r){
    int n1=m-l+1;
    int n2=r-m;
    int left[n1];
    int right[n2];

    for(int i=0;i<n1;i++){
        left[i]=arr[l+i];
    }
    for(int i=0;i<n2;i++){
        right[i]=arr[m+i+1];
    }
   
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
             if(left[i]<=right[j]){arr[k++]=left[i++];}
             else{arr[k++]=right[j++];}
         }
         
         while(i<n1){
             arr[k++]=left[i++];
         }
         while(j<n2){
             arr[k++]=right[j++];
         }

}

void MergeSort(int arr[], int l,int r)
{ if(r>l){
    int m=l+(r-l)/2;

    MergeSort(arr,l,m);
    MergeSort(arr,m+1,r);
    merge(arr,l,m,r);
}
}    

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}


int main()
{
    int n;

    printf("enter size of array:");
    scanf("%d", &n);
    int a[n];

    printf("enter elements of array:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Original array is:");
    printArray(a, n);

    MergeSort(a,0,n-1);

    printf("\nModified array is:");
    printArray(a, n);
}