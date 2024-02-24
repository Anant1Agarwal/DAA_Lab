#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    int arr[30];
    int front;
    int rear;
} queue;

queue *createQueue()
{
    queue *q = malloc(sizeof(queue));
    q->front = 0;
    q->rear = 0;

    return q;
}

int isEmpty(queue *q)
{
    return (q->rear == q->front);
}

void enqueue(queue *q, int x)
{
    q->rear++;
    q->arr[q->rear] = x;
}

int dequeue(queue *q)
{

    q->front++;
    return q->arr[q->front];
}

int front(queue *q)
{
    int f = q->front;
    return q->arr[++f];
}

int OppColor(int x)
{
    if (x == 7)
    {
        return 11;
    }
    else if (x == 11)
    {
        return 7;
    }
}

int CheckBipartiteUsingBFS(int n, int GadjMat[][n])
{
    int vis[n];
    int colors[n];
    for (int i = 0; i < n; i++)
    {
        vis[i] = 0;
        colors[i] = -1;
    }

    queue *q = createQueue();
    enqueue(q, 0);
    vis[0] = 1;
    colors[0] = 7;
    int x = 7;
    while (!isEmpty(q))
    {
        int s = dequeue(q);
        printf("\n%d has color %d ", s, colors[s]);

        for (int i = 0; i < n; i++)
        {
            int curColor = colors[s];
            if (GadjMat[s][i])
            {
                if (vis[i] == 0)  //if its not colored
                {
                    enqueue(q, i);
                    vis[i] = 1;
                    colors[i] = OppColor(curColor);
                }
                else if (colors[i] == curColor)  //if its already colored
                {
                    return 0;
                }
            }
        }
    }
    return 1;
}

int DFSutil(int n, int GadjMat[][n],int u, int colors[],int color){
    colors[u]=color;
    printf("\n%d has color %d ", u, colors[u]);
    
    for(int j=0;j<n;j++){
        if(colors[j]==color && GadjMat[u][j]){
            return 0;
        }
        if(colors[j]==-1 && GadjMat[u][j]){
            if(DFSutil(n,GadjMat,j,colors,OppColor(color))==0){
                    return 0;
            }
        }
        
    }
    return 1;

}

int CheckBipartiteUsingDFS(int n, int GadjMat[][n])
{
    int colors[n];
    for (int i = 0; i < n; i++)
    {
        colors[i] = -1;
    }
    for(int i=0;i<n;i++){
        if(colors[i]==-1){
            if(DFSutil(n,GadjMat,i,colors,7)==0){
                return 0;
            }
        }
    }
    return 1;
    }


int main()
{
    int n;
    printf("Enter Number of vertices in your graph:");
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

    printf("\nBFS Traversal of given Matrix is:");
    if (CheckBipartiteUsingBFS(n, GadjMat) == 1)
    {
        printf("\nGraph is Bipartite! using BFS");
    }
    else
    {
        printf("\nGraph is NOT Bipartite! using BFS");
    }

    printf("\nDFS Traversal of given Matrix is:");
    if (CheckBipartiteUsingDFS(n, GadjMat) == 1)
    {
        printf("\nGraph is Bipartite! using DFS");
    }
    else
    {
        printf("\nGraph is NOT Bipartite! using DFS");
    }

    return 0;
}

// 0 1 1 1 0 0 0
// 1 0 0 0 0 1 0
// 1 0 0 0 0 0 0
// 1 0 0 0 0 1 1
// 0 0 0 0 0 0 1
// 0 1 0 1 0 0 0
// 0 0 0 1 1 0 0



// 0 1 0 0 0 0 0
// 1 0 1 0 0 1 0
// 0 0 1 0 1 0 1
// 0 0 0 1 0 1 0
// 0 1 0 0 1 0 0
// 0 0 0 1 0 0 0

// BFS Traversal of given Matrix is:
// 0 has color 7
// 1 has color 11
// 2 has color 7
// 5 has color 7
// 3 has color 11
// Graph is NOT Bipartite!
      
// Your Matrix is:
// 0 1 0 0 0 0
// 1 0 1 0 1 0
// 0 1 0 1 0 0
// 0 0 1 0 1 1
// 0 1 0 1 0 0
// 0 0 0 1 0 0

// BFS Traversal of given Matrix is:
// 0 has color 7
// 1 has color 11
// 2 has color 7
// 4 has color 7
// 3 has color 11
// 5 has color 7
// Graph is Bipartite! using BFS
// DFS Traversal of given Matrix is:
// 0 has color 7
// 1 has color 11
// 2 has color 7
// 3 has color 11
// 4 has color 7
// 5 has color 7
// Graph is Bipartite! using DFS


// Your Matrix is:
// 0 1 0 0 0 0 0 0
// 1 0 1 0 0 1 0 0
// 0 1 0 1 0 0 0 0
// 0 0 1 0 1 0 1 0
// 0 0 0 1 0 1 0 0
// 0 1 0 0 1 0 0 0
// 0 0 0 1 0 0 0 1
// 0 0 0 0 0 0 1 0

// BFS Traversal of given Matrix is:
// 0 has color 7
// 1 has color 11
// 2 has color 7
// 5 has color 7
// 3 has color 11
// Graph is NOT Bipartite! using BFS
// DFS Traversal of given Matrix is:
// 0 has color 7
// 1 has color 11
// 2 has color 7
// 3 has color 11
// 4 has color 7
// 5 has color 11
// Graph is NOT Bipartite! using DFS