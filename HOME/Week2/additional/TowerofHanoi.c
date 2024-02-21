#include<stdio.h>
#include<stdlib.h>

int opcount=0;
void towerOfhanoi(int n,char source,char aux,char destination){
    if(n==0){
        return;
    }

    towerOfhanoi(n-1, source,destination,aux);
    opcount++;
    printf("Move disk %d from %c to %c\n",n, source, destination);
    towerOfhanoi(n-1, aux, source, destination);
}

int main(){
    int n=3;
    towerOfhanoi(n,'A','B','C');
    printf("No of operation count is %d", opcount);
    return 0;
}