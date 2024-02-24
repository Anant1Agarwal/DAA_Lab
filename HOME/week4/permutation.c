#include <stdio.h>

void swap(int* a, int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void GeneratePermutations(int index, int arr[],int end){
    int static i=0;
    if(index==end){
        i++;
        printf("\nPermutation %d :{",i);
        for(int i=0;i<=end;i++){
            printf("%d ",arr[i]);
        }
        printf("}");
    }
    for(int i=index;i<=end;i++){
        swap(&arr[index],&arr[i]);
        GeneratePermutations(index+1,arr,end);
        swap(&arr[index],&arr[i]);  //backtrack swapping already swapped elements for new iteration
    }
}

int main(){

int a[5]={0,1,2,3};
    GeneratePermutations(0, a, 3);

}

//need to write approach 2