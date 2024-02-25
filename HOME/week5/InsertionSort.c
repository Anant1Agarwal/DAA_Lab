
#include <stdio.h>
#include <stdlib.h>

int opcount = 0;

void InsertionSort(int arr[], int n)
{ for(int i=1;i<n;i++){
    int key=arr[i];
    int j=i-1;
    while(j>=0 && arr[j]>key){
        arr[j+1]=arr[j];
        j--;
    }
    arr[j+1]=key;
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

    InsertionSort(a,n);

    printf("\nModified array is:");
    printArray(a, n);
}