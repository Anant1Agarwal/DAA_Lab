#include <stdio.h>
#include <stdlib.h>

typedef struct Graph
{
    int No_of_V;
    int **matrix;
} Graph;

void addEdge(Graph *g, int v1, int v2)
{
    g->matrix[v1][v2] = 1;
    // g->matrix[v2][v1] = 1;
}

Graph *createGraph(int v)
{
    Graph *g;
    g = (Graph *)malloc(sizeof(Graph));

    g->No_of_V = v;
    g->matrix = (int **)malloc(v * sizeof(int *));

    for (int i = 0; i < v; i++)
    {
        g->matrix[i] = (int *)calloc(v, sizeof(int));
    }
    return g;
}

void PrintGraph(Graph *g)
{
    if (g == NULL)
    {
        printf("NO graph exists");
    }

    int v = g->No_of_V;
    printf("No of vertices is %d\n", v);
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
            printf("%d  ", g->matrix[i][j]);
        printf("\n");
    }
}

void DFSutil(Graph *g, int u, int vis[])
{
    int n = g->No_of_V;
    vis[u] = 1;
    printf("%d ", u);
    for (int j = 0; j < n; j++)
    {
        if (!vis[j] && g->matrix[u][j])
        {
            DFSutil(g, j, vis);
        }
    }
}

void DFStraversal(Graph *g)
{
    int n = g->No_of_V;
    int vis[n];

    for (int i = 0; i < n; i++)
    {
        vis[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            DFSutil(g, i, vis);
        }
    }
}

int main()
{
    Graph *gr;
    gr = createGraph(6);
    // addEdge(gr,1,2);
    // addEdge(gr,1,3);
    // addEdge(gr,1,4);
    // addEdge(gr,1,5);
    // addEdge(gr,6,2);
    // addEdge(gr,3,6);
    // addEdge(gr,6,8);
    // addEdge(gr,8,7);
    // addEdge(gr,4,7);
    // addEdge(gr,5,7);
    addEdge(gr, 5, 0);
    addEdge(gr, 4, 0);
    addEdge(gr, 5, 2);
    addEdge(gr, 4, 1);
    addEdge(gr, 3, 1);
    addEdge(gr, 2, 3);
   

    PrintGraph(gr);
    printf("\nDFS Traversal of given Matrix is:");
    DFStraversal(gr);
    return 0;
}

// 0       0       0       0       0       0       0       0       0
// 0       0       1       1       1       1       0       0       0
// 0       1       0       0       0       0       1       0       0
// 0       1       0       0       0       0       1       0       0
// 0       1       0       0       0       0       0       1       0
// 0       1       0       0       0       0       0       1       0
// 0       0       1       1       0       0       0       0       1
// 0       0       0       0       1       1       0       0       1
// 0       0       0       0       0       0       1       1       0
// 0 1 2 6 3 8 7 4 5

// addEdge(gr,0,1);
// addEdge(gr,1,2);
// addEdge(gr,1,5);
// addEdge(gr,4,5);
// addEdge(gr,3,4);
// addEdge(gr,3,2);
// addEdge(gr,3,6);
// addEdge(gr,7,6);

// 0  1  0  0  0  0  0  0
// 1  0  1  0  0  1  0  0
// 0  1  0  1  0  0  0  0
// 0  0  1  0  1  0  1  0
// 0  0  0  1  0  1  0  0
// 0  1  0  0  1  0  0  0
// 0  0  0  1  0  0  0  1
// 0  0  0  0  0  0  1  0