#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
};
struct Node * top = NULL;

int isEmpty(){
    if (top==NULL)
        return 1;
    else
        return 0;
}

int isFull(){
    struct Node * t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if (t==NULL)
        return 1;
    else
        return 0;
}

void Push(int x){
    struct Node * t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if (isFull())
        printf("Stack Overflow\n");
    else{
        t->data = x;
        t->next = top;
        top = t;
        printf("%d Pushed Successfully\n", x);
    }
}

int Peek(int pos){
    struct Node * p = top;
    for (int i = 0; i < pos-1 && p!=NULL; i++)
        p = p->next;
    if (p)
        return p->data;
    else
        return -1;
}

int Pop(){
    int x = -1;
    if (isEmpty())
        printf("Stack Underflow\n");
    else{
        struct Node * p = top;
        top = top->next;
        x = p->data;
        free(p);
    }
    return x;
}

int StackTop(){
    if (top)
        return top->data;
    else
        return -1;
}

void Display(){
    struct Node * p = top;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main(){
  
    // Check if a Stack is Empty or Not
    if(isEmpty())
        printf("Stack is Empty\n");
    else
        printf("Stack is Not Empty\n");

    // Push Element in Stack
    Push(12);
    Push(18);
    Push(35);
    Push(19);
    Push(85);

    // Peek Element in Stack
    printf("%d present at Index %d\n", Peek(1), 1);
    printf("%d present at Index %d\n", Peek(3), 3);

    // Pop a element from Stack
    printf("%d Popped\n", Pop());
    printf("%d Popped\n", Pop());

    // stack Top 
    printf("Stack Top : %d\n", StackTop());

    // Check if a Stack is Full or Not
    if(isFull())
        printf("Stack is Full\n");
    else
        printf("Stack is Not Full\n");

    // Displaying Elements in Stack
    Display();
    return 0;
}