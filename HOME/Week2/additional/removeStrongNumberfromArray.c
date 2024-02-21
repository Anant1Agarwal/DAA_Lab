#include <stdio.h>
#include <stdlib.h>

int opcount = 0;

int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    int res = 1;
    for (int i = n; i >= 1; i--)
    {
        res = res * i;
    }
    return res;
}

int strongOrNot(int n)
{
    int n1 = n;
    int sum = 0;
    while (n1 > 0)
    {
        int dig = n1 % 10;
        sum = sum + factorial(dig);
        n1 = n1 / 10;
    }

    if (sum == n)
    {
        return 1;
    }
    return 0;
}

void deleteStrong(int arr[], int n, int *count)
{

    for (int i = 0; i < n; i++)
    {
        while (strongOrNot(arr[i]))
        {
            (*count)--;
            for (int j = i; j < *count; j++)
            {
                arr[j] = arr[j + 1];
            }
        }
    }
}

int main()
{
    int n;
    int Newn;

    printf("enter size of array:");
    scanf("%d", &n);
    int a[n];

    printf("enter elements of array:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Original array is:");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    
    Newn = n;
    deleteStrong(a, n, &Newn);
    
    printf("\nModified array is:");
    for (int i = 0; i < Newn; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\nNo of operation count is %d", opcount);
}