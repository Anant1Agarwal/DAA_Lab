#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int opcount = 0;

void findKnapSackitems(int values[], int weights[], int n, int MaxWeight, int selected[], int *SelCount)
{
    int counter = pow(2, n);

    int maxCounter = -1;
    int maxValue = -1;

    for (int i = 0; i < counter; i++)
    {
        int CurWeight = 0;
        int CurValue = 0;
        for (int j = 0; j < n; j++)
        {
            if ((i & (1 << j)) != 0)
            {
                CurWeight += weights[j];
                CurValue += values[j];
            }
        }
        if (CurWeight > MaxWeight)
        {
            continue;
        }
        if (CurValue > maxValue)
        {
            maxValue = CurValue;
            maxCounter = i;
        }
    }

    // putting selected counter variable elemetns in selected array
    for (int j = 0; j < n; j++)
    {
        if ((maxCounter & (1 << j)) != 0)
        {
            selected[*SelCount] = j;
            (*SelCount)++;
        }
    }
}

int main()
{

    int n;
    printf("This is A KnapSack Problem!-Get Max Value items under the weight limit given!");
    printf("\nEnter No. of items: ");
    scanf("%d", &n);
    int weights[n], values[n];
    int selected[n];
    int SelCount = 0;
    int MaxW;
    int CurWeight = 0;
    int CurValue = 0;
    for (int i = 0; i < n; i++)
    {
        printf("Enter weight and value for item %d: ", (i + 1));
        scanf("%d%d", &weights[i], &values[i]);
    }

    printf("Enter MAX Weight allowed:");
    scanf("%d", &MaxW);

    findKnapSackitems(values, weights, n, MaxW, selected, &SelCount);

    printf("\nChosen items are :{");
    for (int i = 0; i < SelCount; i++)
    {
        printf("%d,", selected[i]);
        CurValue += values[selected[i]];
        CurWeight += weights[selected[i]];
    }
    printf("}");
    printf("\nThey have a Total Value of %d with weight of %d as against the Max weight %d Allowed.", CurValue, CurWeight, MaxW);

    return 0;
}