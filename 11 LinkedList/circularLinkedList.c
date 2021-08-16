#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node * next;
};
struct Node * head;

void Create(int a[], int n){
    int i;
    struct Node *t, *last;
    head = (struct Node *)malloc(sizeof(struct Node ));
    head->data = a[0];
    head->next = head;
    last = head;

    for ( i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node *));
        t->data = a[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *p){
    do
    {
        printf("%d --> ", p->data);
        p = p->next;
    } while (p != head);
    printf("\n");
}

void RecDisplay(struct Node *p){
    static int flag = 0;
    if (p != head || flag == 0){
        flag = 1;
        printf("%d ", p->data);
        RecDisplay(p->next);
    }
    flag = 0;
}

int Count(struct Node *p){
    int len = 0;
    do
    {
        len++;
        p = p->next;
    } while (p != head);
    return len;
}

void Insert(struct Node *p, int pos, int val){
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = val;

    if (pos < 0 || pos > Count(head))
        return;
    if (pos == 0){
        if (head == NULL){
            head = t;
            head->next = head;
        }
        else{
            while(p->next != head)
                p = p->next;
            p->next = t;
            t->next = head;
            head = t;
        }
    }
    else{
        for (int i = 0; i < pos - 1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
}

int Delete(struct Node *p, int pos){
    struct Node * q;
    int x;
    if (pos < 0 || pos > Count(head))
        return - 1;
    if(pos == 1){
        while(p->next != head)
            p = p->next;
        x = head->data;
        if (head == p){
            free(head);
            head = NULL;
        }
        else{
        p->next = head->next;
        free(head);
        head = p->next;
        }
        return x;
    }
    else{
        for (int i = 0; i < pos - 2; i++)
        {
            p = p->next;
        }
        q = p->next;
        p->next = q->next;
        x = q->data;
        free(q);
        return x;
    }

}

int main(){

    int a[] = {2, 3, 4, 5, 6};
    Create(a, 5);
    
    // Display using Iteration Approach
    Display(head);   

    // Display using Recursion Approach
    RecDisplay(head);

    // Insertion at a position
    Insert(head, 3, 17);
    Display(head);
 
    // Deletion at a position
    printf("%d Deleted\n", Delete(head, 5));
    Display(head);
    return 0;
}