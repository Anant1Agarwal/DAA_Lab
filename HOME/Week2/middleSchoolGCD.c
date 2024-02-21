#include <stdio.h>
#include <stdlib.h>

int opcount = 0;

void findFactorArray(int arr[], int n, int *fcount)
{
    int index = 0;
    int n1 = n;
    for (int i = 2; i < n; i++)
    {
        while (n1 % i == 0)
        {
            arr[index] = i;
            index++;
            n1 = n1 / i;
            opcount++;
            (*fcount)++;
        }
    }

    // extra
    printf("\nFactors of %d is: ", n);
    for (int i = 0; i < *fcount; i++)
    {
        printf("%d ", arr[i]);
    }
    
    
}

int *findCommonFactors(int a[], int b[], int res[], int l1, int l2, int *count)
{
    int i = 0, j = 0, k = 0;

    while (i < l1 && j < l2)
    {
        if (a[i] == b[j])
        {
            res[k] = a[i];
            k++;
            i++;
            j++;
            (*count)++;
        }
        else if (a[i] < b[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
}

unsigned int MiddleSchoolGCD(unsigned int m, unsigned int n)
{
    int mfactor[100];
    int nfactor[100];
    int comfac[100];
    int mfacN = 0;
    int nfacN = 0;
    int comfacN = 0;

    int res = 1;

    findFactorArray(mfactor, m, &mfacN);
    findFactorArray(nfactor, n, &nfacN);
    findCommonFactors(mfactor, nfactor, comfac, mfacN, nfacN, &comfacN);

    // int l3 = *(&comfac + 1) - comfac;

    printf("\nCommon Factors of %d and %d are :",m,n);
    for (int i = 0; i < comfacN; i++)
    {
        printf("%d ", comfac[i]);
    }

    for (int i = 0; i < comfacN; i++)
    {
        res = res * comfac[i];
    }

    return res;
}

int main()
{
    unsigned int m, n;
    printf("Enter 2 numbers whose GCD has to be calculated: ");
    scanf("%d", &m);
    scanf("%d", &n);
    printf("\nGCD of 2 numbers %d and %d using Middle School Method is %d", m, n, MiddleSchoolGCD(m, n));
    printf("\nNo of operation count is %d", opcount);
    return 0;
}