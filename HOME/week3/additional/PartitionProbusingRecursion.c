#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int opcount = 0;


void printAllSubsets(int arr[], int n)
{
    
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

    printf("All subsets of given array are:");
    printAllSubsets(a, n);

    printf("\nNo of operation count is %d", opcount);
}
