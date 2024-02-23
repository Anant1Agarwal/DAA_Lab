#include <stdio.h>
#include <stdlib.h>

int opcount = 0;
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void BubbleSort(int arr[], int n)
{
    int i, j;

    for (int i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                opcount++;

            }
        }
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

    BubbleSort(a,n);

    printf("\nModified array is:");
    printArray(a, n);

    printf("\nNo of operation count is %d", opcount);
}