#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *front=NULL,*rear=NULL;
void enqueue(int x){
    struct node *t;
    t=(struct node*)malloc(sizeof(struct node));
    if(t==NULL){
        printf("no space");
    }
    t->data=x;
    t->next=NULL;
    if(front==NULL){
        front=rear=t;
    }
    else{
        rear->next=t;
        rear=t;
    }
}
int dequeue(){
    struct node*p;
    p=front;
    int x=-1;
    if(front ==NULL){
        printf("empty\n");
        
    }
    else{
        x=front->data;
        p=front;
        front=front->next;
        free(p);
        
    }
    return x;
}
int main(){
    int ch,u;
    while(1){
        printf("Enter 1. for enqueue 2. for dequeue 3. for exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:printf("enter the element to be added \n");
            int n;
            scanf("%d",&n);
            enqueue(n);
            break;
            case 2: u=dequeue();
            if(u==-1){
                printf("Queue is empty\n");
                exit(0);
            }
            else{
                printf("dequeued element is %d",u);
            }
            break;
            case 3:
            exit(0);
        }
    }
    return 0;
}