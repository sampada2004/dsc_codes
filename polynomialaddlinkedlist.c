#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node
{
    int coeff;
    int exp;
    struct Node *next;
} *poly = NULL;

void create(struct Node **poly)
{
    struct Node *t, *last = NULL;
    int num, i;

    printf("Enter number of terms: ");
    scanf("%d", &num);
    printf("Enter each term with coeff and exp:\n");

    for (i = 0; i < num; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d%d", &t->coeff, &t->exp);
        t->next = NULL;
        if (*poly == NULL)
        {
            *poly = last = t;
        }
        else
        {
            last->next = t;
            last = t;
        }
    }
}

void attach(int coefficient, int exponent, struct Node **ptr)
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->coeff = coefficient;
    temp->exp = exponent;
    temp->next = NULL;  // Set the next pointer of the new node to NULL
    (*ptr)->next = temp;
    *ptr = temp;
}


struct Node *padd(struct Node *a, struct Node *b)
{
    struct Node *rear, *temp;
    struct Node *c;
    int sum;

    rear = (struct Node *)malloc(sizeof(struct Node));
    c = rear;

    while (a && b)
    {
        int res;
        if (a->exp < b->exp)
        {
            res = -1;
        }
        else if (a->exp == b->exp)
        {
            res = 0;
        }
        else
        {
            res = 1;
        }
        switch (res)
        {
        case -1:
            attach(b->coeff, b->exp, &rear);
            b = b->next;
            break;
        case 0:
            sum = a->coeff + b->coeff;
            if (sum)
                attach(sum, a->exp, &rear);
            a = a->next;
            b = b->next;
            break;
        case 1:
            attach(a->coeff, a->exp, &rear);
            a = a->next;
        }
    }

    for (; a; a = a->next)
        attach(a->coeff, a->exp, &rear);

    for (; b; b = b->next)
        attach(b->coeff, b->exp, &rear);

    temp = c;
    c = c->next;
    free(temp);

    return c;
}


void Display(struct Node *p)
{
    while (p)
    {
        printf("%dx%d +", p->coeff, p->exp);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    struct Node *poly1 = NULL, *poly2 = NULL, *result = NULL;

    printf("Enter the first polynomial:\n");
    create(&poly1);
    Display(poly1);

    printf("Enter the second polynomial:\n");
    create(&poly2);
    Display(poly2);

    result = padd(poly1, poly2);

    printf("Result after addition:\n");
    Display(result);

    return 0;
}

