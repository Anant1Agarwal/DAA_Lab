#include <stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

void SelectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
            
        }
        swap(&arr[min], &arr[i]);
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

    SelectionSort(a, n);

    printf("\nModified array is:");
    printArray(a, n);
}