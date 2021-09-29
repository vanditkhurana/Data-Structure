#include<stdio.h>
#include<stdlib.h>

// Create a Structure of Queue
struct Queue{
    int size;
    int rear;
    int front;
    int *Q;
};

// Return 1 if a Circular Queue is Empty else return 0
int isEmpty(struct Queue q){
    if (q.rear == q.front)
        return 1;
    return 0;
}

// Return 1 if a Circular Queue is Full else return 0
int isFull(struct Queue q){
    if ((q.rear+1)% q.size == q.front)
        return 1;
    return 0;
}

// Create a Circular Queue of Desired Size
void Create(struct Queue *q, int size){
    q->size = size;
    q->rear = q->front = 0;
    q->Q = (int *)malloc(q->size * sizeof(int));
}


// Insert Elements in Circular Queue
void Enqueue(struct Queue * q, int val){
    if ((q->rear + 1 )% (q->size) == q->front)
        printf("Queue Overflow\n\n");
    
    else{
        q->rear = (q->rear+1)% q->size;
        q->Q[q->rear] = val;
        printf("%d Enqueud Successfully\n\n");
    }
}

// Deletion of Elements in Circular Queue
int Dequeue(struct Queue *q){
    int x = -1;
    if (q->rear == q->front)
        printf("Queue Underflow\n\n");
    else{
        q->front = (q->front+1)% q->size;
        x = q->Q[q->front];
    }
    return x;
}

// Display of elements in Circular Queue
void Display(struct Queue q){
    int i = q.front + 1;
    do
    {
        printf("%d <--> ", q.Q[i]);
        i = (i+1)%q.size;

    } while (i != (q.rear+1)%q.size);
    
    printf("\n");
}

// Main function with some operations of above described functions
int main(){
    
    // Create a Circular Queue
    struct Queue q;
    Create(&q, 5);

    // Check if Circular Queue is Empty or Not
    printf("%d\n", isEmpty(q));

    // Push Elements in Circular Queue
    Enqueue(&q, 43);
    Enqueue(&q, 16);
    Enqueue(&q, 186);

    // Check if Circular Queue is Full or Not
    printf("%d\n", isFull(q));

    // Delete Element from Circular Queue
    printf("%d Dequeud Successfully\n", Dequeue(&q));
    printf("%d Dequeud Successfully\n", Dequeue(&q));

    // Display Elements of Circular Queue
    Display(q);

    return 0;
}