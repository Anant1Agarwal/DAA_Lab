#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// hoarepartition is given in book

// takes {5,3,8,4,2,7,1,10}
// makes array as {1,3,2,4,8,7,5,10}
// return j=3 as each element on left and including
// arr[j]<pivot(ie. 5) and each element on right of arr[j]
// is greater than//equal to pivot(ie. 5)
int partition(int arr[], int l, int h)
{
    int pivot = arr[l];
    int i = l - 1;
    int j = h + 1;

    while (1)
    {
        do
        {
            i++;
        } while (arr[i] < pivot);
        do
        {
            j--;
        } while (arr[j] > pivot);

        if (i >= j)
        {
            return j;
        }
        swap(&arr[i], &arr[j]);
    }
}

void QuickSort(int arr[], int l, int h)
{
    if (l < h)
    {
        int p = partition(arr, l, h);
        QuickSort(arr, l, p);
        QuickSort(arr, p + 1, h);
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

    QuickSort(a, 0, n - 1);

    printf("\nModified array is:");
    printArray(a, n);
}

// Original array is:5 3 1 9 8 2 4 7
// Modified array is:1 2 3 4 5 7 8 9