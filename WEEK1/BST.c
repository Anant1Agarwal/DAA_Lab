#include<stdio.h>
#include<stdlib.h>
typedef struct Node* nodepointer;
typedef struct Node{
    int data;
    nodepointer lchild;
    nodepointer rchild;

}Node;
Node* CreateBinaryTree()
{
    Node* Temp;
    int ele;
    printf("Enter element to be inserted(-1 for no data)");
    scanf("%d",&ele);
    if(ele==-1)
    return NULL;

    Temp=(Node*)malloc(sizeof(Node));
    Temp->data=ele;

    printf("Enter lchild of %d;\n",ele);
    Temp->lchild=CreateBinaryTree();
    
    printf("Enter rchild of %d:\n",ele);
    Temp->rchild=CreateBinaryTree();
    return Temp;

}
void RecPreorder(Node *ptr)
{
    if(ptr!=NULL)
    {
      printf("%d\t",ptr->data);
      RecPreorder(ptr->lchild);
      RecPreorder(ptr->rchild);
    }
}


void RecInorder(Node *ptr){
    if(ptr!=NULL)
    {
        RecInorder(ptr->lchild);
        printf("%d\t",ptr->data);
        RecInorder(ptr->rchild);
    }
}

void RecPostorder(Node *ptr)
{
    if(ptr!=NULL)
    {
     
      RecPostorder(ptr->lchild);
      RecPostorder(ptr->rchild);
        printf("%d\t",ptr->data);
    }
}


int main()
{  Node* root;
   root=NULL;
   int opt=1,ch;
   do{
   printf("-----MENU-----\n");
   printf("1.Insert\n2.Recursive Traversals\n3.Iterative Traversals\n4.Exit\n");
   printf("Enter your choice:   ");
   scanf("%d",&ch);
   switch(ch)
   {
    case 1: printf("START by adding NODE:\n");
            root=CreateBinaryTree();
            break;
    case 2: printf("\nInorder Traversal:\n");
            RecInorder(root);
            printf("\nPreorder Traversal:\n");
            RecPreorder(root);
            printf("\nPostorder Traversal:\n");
            RecPostorder(root);
            printf("\n"); 
            break;
    // case 3:printf("\nInorder Traversal:\n");
    //         IterInorder(root);
    //  printf("\nPreorder Traversal:\n");
    //         IterPreorder(root);
    //         break;
    case 4: opt=-1;
            break;
   }

   }while(opt==1);
    
    return 0;
}