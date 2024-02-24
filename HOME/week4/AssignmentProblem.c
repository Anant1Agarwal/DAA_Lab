#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int opcount = 0;
//galat h
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

void ChooseMinCostamongPermutations(int index, int arr[], int end, int Costs[end][end], int joblist[])
{
    static int TotalCost = INT_MAX;

    if (index == end)
    {
        // int temp[end];
        int curCost = 0;
        // for (int i = 0; i < end; i++)
        // {
        //     temp[i] = arr[i];
        // }
        printf("\neles are");
        for (int i = 0; i <= end; i++)
        {   printf("%d ",arr[i]);
            curCost += Costs[arr[i]][i];
        }
        printf("curcost%d totalcose%d",curCost,TotalCost);
        if (curCost < TotalCost)
        {
            TotalCost = curCost;
            for (int i = 0; i <= end; i++)
            {
                joblist[i] = arr[i];
            }
        }
    }
    for (int i = index; i <= end; i++)
    {
        swap(&arr[index], &arr[i]);
        ChooseMinCostamongPermutations(index + 1, arr, end, Costs, joblist);
        swap(&arr[index], &arr[i]); // backtrack swapping already swapped elements for new iteration
    }
}

int main()
{
    int n;
    printf("This is a Assignment Problem.\n Goal: To allot n jobs to n people.\neach person gets one job.\neach job gets one person.\nYour task:Minimize cost/Quantity!");
    printf("\nEnter Number of jobs and people: ");
    scanf("%d", &n);
    int Costs[n][n]; // also called as quantity

    // output is in form of <j1, j3,j4....jn> person1 assigned job1 person2 assigned job3 etc.
    printf("Enter cost of each person for a particular job:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Enter Cost if person %d does %d job: ", i + 1, j + 1);
            scanf("%d", &Costs[i][j]);
        }
    }

    int joblist[n];
    int tempjoblist[n];
    for (int i = 0; i < n; i++)
    {
        joblist[i] = i;
        tempjoblist[i] = i;
    }

    ChooseMinCostamongPermutations(0, tempjoblist, n-1, Costs, joblist);
    printArray(joblist, n);
}