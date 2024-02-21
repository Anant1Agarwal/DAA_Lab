#include<stdio.h>
#include<stdlib.h>

typedef struct node* mypointer;

typedef struct node{
    int data;
    mypointer next;

}node;


node* createNode(int d){
    node* new=(node*)malloc(sizeof(node));
    new->data=d;
    new->next=NULL;
    return new;
}

typedef struct Graph{
    int No_of_vectors;
    node** array_of_linkedlist;

}Graph;

Graph* CreateGraph(int v){
    Graph *g=(Graph*)malloc(sizeof(Graph));
    g->No_of_vectors=v;
    g->array_of_linkedlist=(node**)malloc(v*sizeof(node*));
    
    for(int i=0;i<v;i++)
    g->array_of_linkedlist[i]=NULL;

    return g;

}

void addEdge(Graph*g, int v1, int v2){
    node* new=createNode(v2);
    new->next=g->array_of_linkedlist[v1];
    g->array_of_linkedlist[v1]=new;

    new=createNode(v1);
    new->next=g->array_of_linkedlist[v2];
    g->array_of_linkedlist[v2]=new;

}

void PrintGraph(Graph* g){
    if(g==NULL)
    {
        printf("NO graph exists");
    }
    
   int v=g->No_of_vectors;
    printf("No of vertices is %d\n",v);

    for(int i=0;i<v;i++)
    { node *temp=g->array_of_linkedlist[i];
        printf("\nvertex %d is connected to:",i);
        while(temp){
            printf("%d ->",temp->data);
            temp=temp->next;
                    }
                    printf("\n");
    }

}

int main(){
    Graph* gr;
    gr=CreateGraph(4);
    addEdge(gr,0,1);
    addEdge(gr,0,2);
    addEdge(gr,0,3);
    addEdge(gr, 1,2);
    PrintGraph(gr);
}