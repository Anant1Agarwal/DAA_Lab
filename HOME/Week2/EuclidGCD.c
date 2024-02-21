#include<stdio.h>
#include<stdlib.h>

int opcount=0;

unsigned int EuclidGCD(unsigned int m, unsigned int n){
    unsigned int r;
    while(n!=0){
        r=m%n;
        m=n;
        n=r;
        opcount++;

    }
    return m;
}

int main(){
    unsigned int m,n;
    printf("Enter 2 numbers whose GCD has to be calculated: ");
    scanf("%d",&m);
    scanf("%d",&n);
    printf("GCD of 2 numbers %d and %d using Euclid's Method is %d\n",m, n, EuclidGCD(m,n));
    printf("No of operation count is %d",opcount);
    return 0;
}

