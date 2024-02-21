#include<stdio.h>
#include<stdlib.h>

typedef struct Graph{
    int No_of_V;
   int** matrix;

}Graph;

void addEdge(Graph*g, int v1,int v2) //from v1->v2
{
    g->matrix[v1][v2]=1;
    g->matrix[v2][v1]=1;
}
Graph* createGraph(int v){
    // printf("enter no of vertices:");
    // int v;
    // scanf("%d",&v);
    Graph* g;
    
    g=(Graph*)malloc(sizeof(Graph));
    
    g->No_of_V=v;
    g->matrix=(int**)malloc(v*sizeof(int*));
   
    for(int i=0;i<v;i++)
    {
        g->matrix[i]=(int*)calloc(v,sizeof(int));
    }
    return g;
}

void PrintGraph(Graph* g){
    if(g==NULL)
    {
        printf("NO graph exists");
    }
    
   int v=g->No_of_V;
    printf("No of vertices is %d\n",v);
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        printf("%d\t", g->matrix[i][j]);
        printf("\n");
    }

}


int main(){
Graph* gr;
gr=createGraph(5);
addEdge(gr,1,2);
addEdge(gr,4,1);
PrintGraph(gr);
return 0;
}