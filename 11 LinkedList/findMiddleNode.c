#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *first = NULL;
struct Node *second = NULL;

void Create(int a[], int n)
{
    int i;
    struct Node *t, *last;

    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = a[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d --> ", p->data);
        p = p->next;
    }
    printf("\n");
}

int findMiddle(struct Node *p){
    struct Node * q;
    p = q = first;
    while (q)
    {
        q = q->next;
        if (q) q = q->next;
        if (q) p = p->next;
    }
    return p->data;
}

int main()
{
    int a[] = {10, 20, 30, 40, 50, 60, 70};
    Create(a, 7);
    printf("Middle is %d \n", findMiddle(first));
    Display(first);

    return 0;
}

