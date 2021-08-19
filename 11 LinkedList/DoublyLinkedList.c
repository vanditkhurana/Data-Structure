#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node * prev;
    int data;
    struct Node * next;
};
struct Node * first = NULL;

void Create(int a[], int n){
    
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = a[0];
    first->prev = first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = a[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *p){
    while(p){
        printf("%d <--> ", p->data);
        p = p->next;
    }
    printf("\n");
}

int Count(struct Node *p){
    int c = 0;
    while(p){
        c++;
        p = p->next;
    }
    return c;
}

void Insert(struct Node *p, int pos, int val){
    if (pos < 0 || pos > Count(first))
        return;
    struct Node * t;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = val;
    if (pos == 0){
        t->prev = first->prev;
        first->prev = t;
        t->next = first;
        first = t;
    }
    else{
        for (int i = 0; i < pos - 1; i++)
            p = p->next;

        t->prev = p;
        t->next = p->next;
        if (p->next)
            p->next->prev = t;
        p->next = t;
    }
}

int Delete(struct Node *p, int pos){
    p = first;
    struct Node * q;
    int x;
    if (pos < 0 || pos > Count(first))
        return -1;

    if (pos == 1){
        first = first->next;
        p->next = NULL;
        x = p->data;
        free(p);
        if (first) first->prev = NULL;
        return x;
    }
    else{
        for (int i = 0; i < pos - 1; i++)
            p = p->next;
        p->prev->next = p->next;
        if (p->next)
            p->next->prev = p->prev;
        x = p->data;
        return x;
    }
}

void Reverse(struct Node * p){
    struct Node * temp;
    while (p)
    {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;
        if (p != NULL && p->next == NULL)
            first = p;
    }
}

int main(){

    int a[] = {10, 20, 30, 40, 50};
    // Create Doubly Linked List
    Create(a, 5);
 
    Reverse(first);
    Display(first);

    return 0;
}