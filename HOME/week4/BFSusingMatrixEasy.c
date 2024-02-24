#include<stdio.h>
#include<stdlib.h>

typedef struct queue{
    int arr[30];
    int front;
    int rear;
}queue;

queue* createQueue(){
    queue* q=malloc(sizeof(queue));
    q->front=0;
    q->rear=0;
    
    return q;
}

int isEmpty(queue* q){
    return(q->rear==q->front);
}

void enqueue(queue*q, int x){
    q->rear++;
    q->arr[q->rear]=x;
}

int dequeue(queue *q){
    
    q->front++;
    return q->arr[q->front];
}

int front(queue *q){
    int f=q->front;
    return q->arr[++f];
}





void BFStraversal(int n, int GadjMat[][n]){
    int vis[n];
    for(int i=0;i<n;i++){
        vis[i]=0;
    }

    queue* q=createQueue();
    enqueue(q,0);
    vis[0]=1;
    while(!isEmpty(q)){
        int s=dequeue(q);
        printf("%d ",s);
    
        for(int i=0;i<n;i++){
            if(vis[i]==0 && GadjMat[s][i]){
                enqueue(q, i);
                vis[i]=1;
            }
        }
    }
}





int main(){
    int n;
    printf("Enter Number of vertices in your graph:");
    scanf("%d",&n);
    int GadjMat[n][n];

    printf("Enter your Graph in adjacency Matrix format");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&GadjMat[i][j]);
        }
    }

    printf("\nYour Matrix is:\n");
     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",GadjMat[i][j]);
        }
        printf("\n");
    }

    printf("\nBFS Traversal of given Matrix is:");
    BFStraversal(n,GadjMat);

    return 0;
}


// 0 1 1 1 0 0 0
// 1 0 0 0 0 1 0
// 1 0 0 0 0 0 0
// 1 0 0 0 0 1 1
// 0 0 0 0 0 0 1
// 0 1 0 1 0 0 0
// 0 0 0 1 1 0 0
