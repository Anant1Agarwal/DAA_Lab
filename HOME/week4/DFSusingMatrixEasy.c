#include <stdio.h>
#include <stdlib.h>

void DFSutil(int n, int GadjMat[][n], int u, int vis[])
{
    vis[u] = 1;
    printf("%d ", u);

    for (int j = 0; j < n; j++)
    {
        if (vis[j] == 0 && GadjMat[u][j])
        {
            DFSutil(n, GadjMat, j, vis);
        }
    }
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

    printf("\nDFS Traversal of given Matrix is:");
    DFStraversal(n, GadjMat);

    return 0;
}