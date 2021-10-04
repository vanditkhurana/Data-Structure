#include<stdio.h>
#include<stdlib.h>

// Create a Node Structure
struct Node{
    int data;
    struct Node * next;
};
struct Node *front = NULL;
struct Node *rear = NULL;


// Inserting Elements in Queue
void Enqueue(int x){
    struct Node *t = (struct Node *)malloc(sizeof(struct Node ));
    if (t == NULL)
        printf("Queue is Full\n\n");
    else{
        t->data = x;
        t->next = NULL;
        if (front == NULL) front = rear = t;
        else{
            rear->next = t;
            rear = t;
        }
        printf("%d Enqueued Successfully\n", x);
    }
}

// Deleting Elements from Queue
int Dequeue(){
    int x = -1;
    struct Node *p;
    if (front == NULL)
        printf("Queue is Empty\n\n");
    else{
        p = front;
        front = front->next;
        x = p->data;
        free(p);
    }
    return x;
}


// Display Elements of Queue
void Display(){
    struct Node *t;
    t = front;
    if (t == NULL)
        printf("Queue is Empty\n\n");
    else{
        while (t != rear->next)
        {
            printf("%d <--> ", t->data);
            t = t->next;
        }
    }
    printf("\n");
}

// Main Function with all of the Operations described above
int main(){

    // Inserting Elements in Queue
    Enqueue(24);
    Enqueue(245);
    Enqueue(64);
    Enqueue(29);
    Display();

    // Deleting Elements from Queue
    printf("%d Dequeued Successfully\n", Dequeue());
    printf("%d Dequeued Successfully\n", Dequeue());

    // Display Elements of Queue
    Display();
    return 0;
}