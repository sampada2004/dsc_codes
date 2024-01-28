#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *llink;
    struct node *rlink;

} *front , *rear = NULL;
/**void create(int A[], int n)
{
    int i;
    struct node *t, *last;
    front = (struct node *)malloc(sizeof(struct node));
    front->data = A[0];
    front->rlink = NULL;
    last = front;

    for (i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = A[i];
        t->rlink = NULL;
        last->rlink = t;
        last = t;
    }
}**/
void insert_f(struct node **front, int x)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->data = x;
    p->llink = NULL;
    p->rlink = *front;
    if (*front != NULL)
    {
        (*front)->llink = p;
    }
    *front = p;
}
int delete_f()
{
    struct node *p;
    int x;

    if (front == NULL)
    {
        printf("empty \n");
        exit(0);
    }

    p = front;
    x = p->data;
    front = front->rlink;

    if (front != NULL)
    {
        front->llink = NULL;
    }

    free(p);
    return x;
}
void insert_r(struct node **front, int x)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    if (*front == NULL)
    {
        *front = p;
        p->data = x;
        p->llink = NULL;
        p->rlink = NULL;
        rear=p;
    }
    else
    {
        struct node *rear = *front;
        while (rear->rlink != NULL)
        {
            rear = rear->rlink;
        }
        rear->rlink = p;
        p->llink = rear;
        p->data = x;
        p->rlink = NULL;
        rear = p;
    }
}
int delete_r(struct node **front)
{
    struct node *rear = *front;
    struct node *p;
    int g = -1;
    //rear = front;
    if (rear == NULL)
    {

         printf("empty \n");
        exit(0);
    }
    else
    {
        while (rear->rlink != NULL)
        {
            rear = rear->rlink;
        }
        p = rear;
        g = p->data;
        if (rear->llink == NULL)
        {
            free(rear);
            front = NULL;
            rear=NULL; // Update front to NULL as the list is now empty
        }
        else {
            rear->llink->rlink = NULL;
            rear = rear->llink;
            free(p);
        }
    }
    return g;
}
void display(struct node *p)
{
    if(p==NULL){
        exit(0);
    }
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->rlink;
    }
    
}
int main()
{
     
     int ch;
     while(1){
        printf("Enter the 1.for insert front 2.for insert rear 3. for delete rear 4. for delete front 5. for exit 6.Display\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:printf("enter the element to be inserted at front\n");
            int n;
            scanf("%d",&n);
            insert_f(&front,n);
            break;
            case 2:printf("enter the element to be inserted at rear\n");
            int m;
            scanf("%d",&m);
            insert_r(&front,m);
            break;
            case 3:printf("deleted element from rear is %d\n",delete_r(&front));
            break;
            case 4:printf("deleted element from front is %d\n",delete_f());
            break;
            case 6:display(front);
            break;
            case 5:exit(0);
        }
     }
    //int A[] = {10, 20, 40, 50, 60};
    //create(A, 5);

    /*insert_f(&front, 9);
    insert_f(&front, 9);
    insert_f(&front, 11);
    printf("%d is the dequeue element from front\n", delete_f());
    printf("%d is the dequeue element from front \n", delete_f());
    printf("%d is the dequeue element from front \n", delete_f());
    insert_r(&front, 80);
    insert_r(&front, 80);
    insert_r(&front, 90);
    printf("%d is the dequeue element from end \n", delete_r(&front));
    display(front);*/

    return 0;
}