#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int opcount = 0;

void printAllSubsets(int arr[], int n)
{
    int counter = pow(2, n);
    for (int i = 0; i < counter; i++)
    { // loop through every iteration of powerset
        printf("\nSubset %d:{", i);
        for (int j = 0; j < n; j++)
        {                            // to select numbers in subset
            if ((i & (1 << j)) != 0) // to check if jth bit is active in counter. if active, choose it
            {
                printf("%d,", arr[j]);
            }
        }
        printf("}");
    }
}

void printpartitiondisjoint(int arr[], int n, int sumreq)
{ 
    int counter = pow(2, n);
    int k=0;
    for (int i = 0; i < counter; i++)
    { // loop through every iteration of powerset
        int cursum = 0;
        for (int j = 0; j < n; j++)
        {                            // to select numbers in subset
            if ((i & (1 << j)) != 0) // to check if jth bit is active in counter. if active, choose it
            {
                cursum += arr[j];
                opcount++;
            }
        }

        if (cursum == sumreq)
        {
            k++;
            printf("\nDisjoint Set %d is {", k);
            for (int j = 0; j < n; j++)
            {                            // to select numbers in subset
                if ((i & (1 << j)) != 0) // to check if jth bit is active in counter. if active, choose it
                {
                    printf("%d,", arr[j]);
                }
            }
            printf("}");
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

    printf("All subsets of given array are:");
    printAllSubsets(a, n);

    // check if disjoint set can exist. means 2 sets have same sum
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }
    if (sum % 2 == 0)
    {
        printf("\nDisjoint set exists!");
    }
    else
    {
        printf("\ndisjoint sets dont exist");
        return 0;
    }

    printf("\nAll partition based disjoint sets are:");
    printpartitiondisjoint(a, n, sum/2);
    printf("\nNo of operation count is %d", opcount);
}