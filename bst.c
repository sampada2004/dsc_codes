#include<stdio.h>
#include<stdlib.h>
#define max 200
#define full(n) (n==max-1)
#define empty(n) (!n)
typedef struct {
    int key;
}element;
element heap[max];
int n=0;
void push(element item,int *n){
    int i;
    if(full(*n)){
        fprintf(stderr,"The heap is full\n");
        exit(0);
    }
    i=++(*n);
    while((i!=1)&&(item.key>heap[i/2].key)){
        heap[i]=heap[i/2];
        i/=2;
    }
    heap[i]=item;
}
element pop(int *n){
    int parent,child;
    element item,temp;
    if(empty(*n)){
        fprintf(stderr,"Empty\n");
        exit(0);
    }
    item=heap[1];
    temp=heap[(*n)--];
    parent=1;
    child=2;
    while(child<=*n){
        if((child<*n)&&(heap[child].key<heap[child+1].key)){
            child++;
        }
        if(temp.key>=heap[child].key)break;
        heap[parent]=heap[child];
        parent=child;
        child*=2;

    }
    heap[parent]=temp;
    return item;
}
void display(int n){
    int i;
    if (empty(n)) {
        printf("Heap is empty\n");
        return;
    }
    printf("Heap elements: ");
    for (i = 1; i <= n; i++) {
        printf("%d ", heap[i].key);
    }
    printf("\n");
}
int main() {
    int choice;
    element item;

    while (1) {
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to push: ");
                scanf("%d", &item.key);
                push(item, &n);
                break;

            case 2:
                if (!empty(n)) {
                    element popped_item = pop(&n);
                    printf("Popped: %d\n", popped_item.key);
                } else {
                    printf("Heap is empty, cannot pop.\n");
                }
                break;

            case 3:
                display(n);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
