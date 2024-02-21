#include <stdio.h>
#include <stdlib.h>

int opcount = 0;
//floor of square root
//uses binary search
unsigned int root(unsigned int n){
   if(n==0||n==1){
    return n;
   }
   int low=0;
   int high=n; 
  int mid,result;
   while(low<=high){
    mid=(low+high)/2;
    opcount++;
    if(mid*mid==n){
        return mid;
    }
    else if (mid*mid<n){
        low=mid+1;
        result=mid;   
    }
    else{
        high=mid-1;
    }
   }
   return result;
}

int main(){
    int n;
    printf("Enter number for root to be found: ");
    scanf("%d",&n);
    printf("The low nearest to root of %d is %d whose square is %d", n, root(n),root(n)*root(n));
     printf("\nNo of operation count is %d", opcount);
}