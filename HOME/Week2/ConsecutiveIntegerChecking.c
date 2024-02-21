#include<stdio.h>
#include<stdlib.h>

int opcount=0;

unsigned int ConsecutiveIntegerGCD(unsigned int m, unsigned int n)
{
    unsigned int t;
    if(m<n){
        t=m;
    }
    else{
        t=n;
    }
    opcount++;
    while(m%t!=0 || n%t!=0 ){
      t--;
      opcount++;
    }
    return t;
}

int main(){
    unsigned int m,n;
    printf("Enter 2 numbers whose GCD has to be calculated: ");
    scanf("%d",&m);
    scanf("%d",&n);
    printf("GCD of 2 numbers %d and %d using Consecutive Integer Checking Method is %d\n",m, n, ConsecutiveIntegerGCD(m,n));
    printf("No of operation count is %d",opcount);
    return 0;
}