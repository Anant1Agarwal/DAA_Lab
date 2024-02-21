#include <stdio.h>;
#include <stdlib.h>;
// using adjacency list

typedef struct node *mypointer;

typedef struct node
{
    int data;
    mypointer next;

} node;

typedef struct Graph
{
    int No_Of_vectors;
    node **array_of_linkedlist;
} Graph;

node *createNode(int v)
{
    node *new = (node *)malloc(sizeof(node));
    new->data = v;
    new->next = NULL;
}

Graph *CreateGraph(int No_of_V)
{
    Graph *g = malloc(sizeof(Graph));

    g->No_Of_vectors = No_of_V;
    g->array_of_linkedlist = (node *)malloc(No_of_V * sizeof(node *));

    for (int i = 0; i < No_of_V; i++)
        g->array_of_linkedlist = NULL;
    return g;
};

void addEdge(Graph *g, int u, int v)
{ node *new = createNode(v);

    g->array_of_linkedlist[u]=new;


    new=createNode(u);
    

    
    
}

void printGraph(Graph *gr, int size)
{

    for(int i=0;i<size;i++)
    {
            node*temp=gr->array_of_linkedlist[size];
            
            printf("\n Vertex %d \n", i);
            while(temp){
                printf("%d->",temp->data);
                temp=temp->next;
            }
            printf("\n");
    }
}

int main()
{
    Graph* gra=CreateGraph(4);

    addEdge(gra, 0,1);
    addEdge(gra, 0,2);
    addEdge(gra, 0,3);
    addEdge(gra, 1,2);
    
    printGraph(gra,4);

}