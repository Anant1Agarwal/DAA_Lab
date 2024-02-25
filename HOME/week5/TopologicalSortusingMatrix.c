#include <stdio.h>
#include <stdlib.h>
// NOTE: WE ARE USING DIRECTED ACYCLIC GRAPHS IN THIS>
// SO MATRIX REPRESENTATION WOULD CHANGE IN MATRIX REPRESENTATION TOUGH PROGRAM

int stack[100];
int top = -1;
void push(int arr[], int x)
{
    arr[++top] = x;
}
int pop(int arr[])
{
    return arr[top--];
}

int queue[100];
int rear = -1;
int front = -1;

void enqueue(int arr[], int x)
{
    arr[++rear] = x;
}
int dequeue(int arr[])
{
    return (arr[++front]);
}

int IsEmptyQueue()
{
    return (front == rear);
}

void DFSutil(int n, int GadjMat[][n], int u, int vis[])
{
    vis[u] = 1;

    for (int j = 0; j < n; j++)
    {
        if (vis[j] == 0 && GadjMat[u][j])
        {
            DFSutil(n, GadjMat, j, vis);
        }
    }
    push(stack, u);
}

void DFStraversal(int n, int GadjMat[][n])
{
    int vis[n];
    for (int i = 0; i < n; i++)
    {
        vis[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
        {
            DFSutil(n, GadjMat, i, vis);
        }
    }

    // for(int i=top;i>=0;i--){
    //     printf("%d ", stack[i]);
    // }
    while (top >= 0)
    {
        printf("%d ", pop(stack));
    }
}

void TopoSortUsingBFS(int n, int GadjMat[][n])
{
    int indegree[n];
    for (int i = 0; i < n; i++)
    {
        indegree[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (GadjMat[i][j])
            {
                indegree[j] += 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            enqueue(queue, i);
        }
    }

    while (!IsEmptyQueue())
    {
        int x = dequeue(queue);
        printf("%d ", x);

        for (int i = 0; i < n; i++)
        {
            if (GadjMat[x][i])
            {
                indegree[i]--;
                if (indegree[i] == 0)
                {
                    enqueue(queue, i);
                }
            }
        }
    }
}

int main()
{
    int n;
    printf("Enter Number of verices in your graph:");
    scanf("%d", &n);
    int GadjMat[n][n];

    printf("Enter your Graph in adjacency Matrix format");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &GadjMat[i][j]);
        }
    }

    printf("\nYour Matrix is:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", GadjMat[i][j]);
        }
        printf("\n");
    }

    printf("\nTopological Sort using DFS of given Matrix is: ");
    DFStraversal(n, GadjMat);
    printf("\nTopological Sort using BFSSource Removal Technique/Kahn's Algo of given Matrix is: ");
    TopoSortUsingBFS(n, GadjMat);

    return 0;
}

// 0  0  0  0  0  0
// 0  0  0  0  0  0
// 0  0  0  1  0  0
// 0  1  0  0  0  0
// 1  1  0  0  0  0
// 1  0  1  0  0  0