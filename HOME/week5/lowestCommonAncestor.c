#include<stdio.h>
#include<stdlib.h>

typedef struct node* nodepointer;

typedef struct node{
    int data;
    nodepointer lchild;
    nodepointer rchild;
}node;

node* InsertBST(node* root, int ele){
    if(root==NULL){
        node* newnode=(node*)malloc(sizeof(node));
        newnode->data=ele;
        newnode->lchild=NULL;
        newnode->rchild=NULL;
        return newnode;
    }

    if(ele<root->data){
        root->lchild=InsertBST(root->lchild,ele);
    }
    else if(ele>root->data){
        root->rchild=InsertBST(root->rchild,ele);
    }
    return root;
}

node* CreateBinaryTree(){
node* root=NULL;
int ele;
    printf("Enter Element to be inserted(-1 for no data) ");
    scanf("%d",ele);
    // if(ele=-1)
    // {
    //     return NULL;
    // }

    // temp=(node*)malloc(sizeof(node));
    // temp->data=ele;

    // printf("Enter lchild of %d,",ele);
    // temp->lchild=CreateBinaryTree();

    // printf("Enter rchild of %d",ele);
    // temp->rchild=CreateBinaryTree();

    // return temp;
    while(ele!=-1){
        root=InsertBST(root,ele);
        printf("Enter Element to be inserted(-1 for no data) ");
    scanf("%d",ele);
    }

    return root;
}


void RecInorder(node* ptr) {
    if (ptr != NULL) {
        RecInorder(ptr->lchild);
        printf("%d\t", ptr->data);
        RecInorder(ptr->rchild);
    }
}
int main(){
    node* root=NULL;
    int opt=1,ch;

   do {
        printf("-----MENU-----\n");
        printf("1.Insert\n2.Recursive Traversals\n3.Iterative Traversals\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Insert element into BST:\n");
                root = CreateBinarySearchTree();
                break;
            case 2:
                printf("\nInorder Traversal:\n");
                RecInorder(root);
                printf("\nPreorder Traversal:\n");
                RecPreorder(root);
                printf("\nPostorder Traversal:\n");
                RecPostorder(root);
                printf("\n");
                break;
            // case 3:
            //     printf("\nInorder Traversal:\n");
            //     IterInorder(root);
            //     printf("\nPreorder Traversal:\n");
            //     IterPreorder(root);
            //     break;
            case 4:
                opt = -1;
                break;
        }

    } while (opt == 1);

    return 0;


}