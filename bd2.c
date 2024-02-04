#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*lchild;
    struct node*rchild;
}*root=NULL;
struct node * create(int key){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=key;
    newnode->lchild=newnode->rchild=NULL;
    return newnode;
}
struct node*insert(struct node*p,int key){
    struct node*t;
    if(p==NULL){
        
        return create(key);
    }
    if(key<p->data){
        p->lchild=insert(p->lchild,key);
    }
    else if(key>p->data){
        p->rchild=insert(p->rchild,key);
    }
    return p;
}
void inorder(struct node*p){
    if(p){
        inorder(p->lchild);
        printf("%d ",p->data);
        inorder(p->rchild);
    }
}
void preorder(struct node*p){
    if(p){
        printf("%d ",p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}
void postorder(struct node*p){
    if(p){
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d ",p->data);
    }
}

int main(){
    //struct node *g=NULL;
    //p=(struct node*)malloc(sizeof(struct node));
    struct node *root=NULL;
    int num;
    
    printf("Enter the number of elements: ");
    scanf("%d", &num);

    printf("Enter the elements:\n");
    for (int i = 0; i < num; i++) {
        int element;
        scanf("%d", &element);
        root = insert(root, element);
        
    }
    printf("\n");
    printf("Inorder traversal:\n");
    inorder(root);
    printf("\n");
    printf("Preorder traversal:\n");
    preorder(root);
    printf("\n");
    printf("Postorder traversal:\n");
    postorder(root);
    return 0;
}

