#include <stdio.h>
#include <stdlib.h>

int opcount = 0;

int fibonacci(int n){
    opcount++;
    if(n==0||n==1){
        return n;
    }
    
    else {
        return fibonacci(n-1)+fibonacci(n-2);
    }
}

int main()
{
    int n;
    printf("enter number for which you want fibonacci of:");
    scanf("%d", &n);
    printf("\nfibonacci of given number is %d", fibonacci(n));
    printf("\nNo of operation count is %d", opcount);
}