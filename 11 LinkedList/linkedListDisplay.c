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

void Create2(int a[], int n)
{
    int i;
    struct Node *t, *last;

    second = (struct Node *)malloc(sizeof(struct Node));
    second->data = a[0];
    second->next = NULL;
    last = second;

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

void RecDisplay(struct Node *p)
{
    if (p != NULL)
    {
        printf("%d ", p->data);
        RecDisplay(p->next);
    }
}

int Count(struct Node *p)
{
    int c = 0;
    while (p != NULL)
    {
        c++;
        p = p->next;
    }
    return c;
}

int RecCount(struct Node *p)
{
    if (p == NULL)
        return 0;
    else
        return RecCount(p->next) + 1;
}

int Sum(struct Node *p)
{
    int sum = 0;
    while (p)
    {
        sum = sum + p->data;
        p = p->next;
    }
    return sum;
}

int RecSum(struct Node *p)
{
    if (p == NULL)
        return 0;
    else
        return RecSum(p->next) + p->data;
}

int Max(struct Node *p)
{
    int m = INT_MIN;
    while (p != NULL)
    {
        if (p->data > m)
            m = p->data;
        p = p->next;
    }
    return m;
}

int RecMax(struct Node *p)
{
    int x;
    if (p == NULL)
        return INT_MIN;
    x = RecMax(p->next);
    return x > p->data ? x : p->data;
}

int Min(struct Node *p)
{
    int m = INT_MAX;
    while (p != NULL)
    {
        if (p->data < m)
            m = p->data;
        p = p->next;
    }
    return m;
}

int RecMin(struct Node *p)
{
    int x;
    if (p == NULL)
        return INT_MAX;
    x = RecMin(p->next);
    return x < p->data ? x : p->data;
}

int LinearSearch(struct Node *p, int key)
{
    while (p != NULL)
    {
        if (p->data == key)
            return 1;
        p = p->next;
    }
    return 0;
}

int RecLinearSearch(struct Node *p, int key)
{
    if (p == NULL)
        return 0;
    if (p->data = key)
        return 1;
    else
        return RecLinearSearch(p->next, key);
}

int ImprovedLinearSearch(struct Node *p, int key)
{
    struct Node *q = NULL;
    while (p != NULL)
    {   
        q = p;
        if (key == p->data)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return 1;
        }
        p = p->next;
    }
    return 0;
}

void Insert(struct Node * p, int pos, int val){
    if (pos < 0 || pos > Count(p))
        return;
    struct Node * new = (struct Node *)malloc(sizeof(struct Node));
    new->data = val;

    if (pos == 0){
        new->next = first;
        first = new;
    }
    else{
        struct Node * temp;
        temp = first;
        for (int i = 0; i < pos-1; i++)
            temp = temp->next;
        
        new->next = temp->next;
        temp->next = new;
    }
}

void InserSorted(struct Node *p, int val){
    struct Node *q = NULL;
    struct Node * new = (struct Node *)malloc(sizeof(struct Node));
    new->data = val;
    new->next = NULL;
    if (first == NULL)
        first = new;
    
    else{
        while(p && p->data < val){
            q = p;
            p = p->next;
        }
        if (p == first){
        new->next = first;
        first = new;
        }
        else{
        new->next = q->next;
        q->next = new;
        }
    }
}

int Delete(struct Node *p, int pos){
    struct Node * q = NULL;
    int x = -1;
    if (pos < 1 || pos > Count(first))
        return x;
    if (pos == 1){
        first = p->next;
        x = p->data;
        free(p);
        return x;
    }
    else{
        for (int i = 0; i < pos - 1; i++)
        {
            q = p;
            p = p->next;
        }
        if (p){
            q->next = p->next;
            x = p->data;
            free(p);
        }
    }
    return x;
}

int IsSorted(struct Node * p){
    int x = -32768;
    while (p != NULL){
        if (p->data < x)
            return 0;
        x = p->data;
        p = p->next;
    }
    return 1;
}

void DeleteDuplicate(struct Node * p){
    struct Node * q;
    p = first;
    q = p->next;
    while (q != NULL)
    {
        if (p->data != q->data){
            p = q;
            q = q->next;
        }
        else{
            p->next = q->next;
            free(q);
            q = p->next;
        }
    } 
}

void ReverseLinkedList(struct Node * p){
    int size = Count(p);
    int *arr;
    arr = (int *)malloc(size * sizeof(int));
    int i = 0;
    while (p != NULL)
    {
        arr[i] = p->data;
        p = p->next;
        i++;
    }
    p = first;
    i--;
    while (p != NULL)
    {
        p->data = arr[i--];
        p= p->next;
    }
}

void ReverseUsingSlidingPointers(struct Node * p){
    struct Node *q, *r;
    p = first;
    q = r = NULL;
    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

void ReverseRecursion(struct Node * q, struct Node * p){
    if (p != NULL){
        ReverseRecursion(p, p->next);
        p->next = q;
    }
    else
        first = q;
}

struct Node * Concatenate(struct Node *p, struct Node *q){
    struct Node * third;
    third = first;
    while(p->next != NULL)
        p = p->next;

    p->next = q;
    q = NULL;
    return third;
}

struct Node * Merge(struct Node *p, struct Node *q){
    struct Node * third, *last;
    third = last = NULL;
    if (p->data < q->data){
        third = last = p;
        p = p->next;
        last->next = NULL;
    }
    else{
        third = last = q;
        q = q->next;
        last->next = NULL;
    }
    while (p != NULL && q != NULL){
        if (p->data < q->data){
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else{
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if (p != NULL)
        last->next = p;
    else    
        last->next = q;
    return third;
}

int IsLoop(struct Node * p){
    struct Node *a, *b;
    a = b = p;
    do
    {
        a = a->next;
        b = b->next;
        b != NULL ? b = b->next : b;
    } while (a && b && a != b);

    if (a == b)
        return 1;
    else    
        return 0;
}

int main()
{
    int a[] = {10, 20, 30, 40, 50, 60};
    Create(a, 6);
    Display(first);

    // Concatenating
    struct Node * third;
    int a[] = {10, 20, 30, 40, 50, 60};
    int b[] = {25, 28, 38, 47};
    Create(a, 6);
    Create2(b, 4);
    third = Concatenate(first, second);
    Display(third);

    // Merging
    int a[] = {10, 20, 30};
    int b[] = {25, 28, 38, 47};
    Create(a, 3);
    Create2(b, 4);
    third = Merge(first, second);
    Display(third);

    // Is Loop or not
    struct Node * t1, *t2;
    t1 = first->next->next;
    t2 = first->next->next->next->next->next;
    t2->next = t1;

    if (IsLoop(first))
        printf("It is a Loop\n");
    else
        printf("It is not a Loop\n");

    return 0;
}