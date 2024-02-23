#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int opcount = 0;

int main()
{
    int n;
    printf("This is a Assignment Problem.\n Goal: To allot n jobs to n people.\neach person gets one job.\neach job gets one person.\nYour task:Minimize cost/Quantity!");
    printf("\nEnter Number of jobs and people: ");
    scanf("%d", &n);
    int Costs[n][n]; // also called as quantity

    //output is in form of <j1, j3,j4....jn> person1 assigned job1 person2 assigned job3 etc.
    printf("Enter cost of each person for a particular job:");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Enter Cost if person %d does %d job", i, j);
            scanf("%d", Costs[i][j]);
        }
    }

}