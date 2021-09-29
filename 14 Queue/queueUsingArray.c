#include<stdio.h>
#include<stdlib.h>


// Create a Structure of Queue
struct Queue{
    int size;
    int rear;
    int front;
    int *Q;
};

// Create a Queue with Desired size
void Create(struct Queue *q, int size){
    q->size = size;
    q->rear = q->front = -1;
    q->Q = (int *)malloc(q->size * sizeof(int));  
}

// Display of elements in Queue
void Display(struct Queue q){
    if (q.front == q.rear)
        printf("Queue is Empty");
    else{
        printf("\nElements are : \n\n");
        for (int i = q.front + 1; i <= q.rear; i++)
            printf("%d <--> ", q.Q[i]);
    }
    printf("\n");
}

// Return 1 if Queue is Empty else return 0
int isEmpty(struct Queue q){
    if (q.front == q.rear)
        return 1;
    return 0;
}

// Return 1 if Queue is Full else return 0
int isFull(struct Queue q){
    if (q.rear >= q.size-1)
        return 1;
    return 0;
}

// Insert Elements in Queue
void Enqueue(struct Queue *q, int val){
    if (isFull(*q))
        printf("Queue Overflow\n");
    else{
        q->rear++;
        q->Q[q->rear] = val;
        printf("%d Enqueud Successfully\n");
    }
}

// Delete Elements from Queue
int Dequeue(struct Queue *q){
    int x = -1;
    if (isEmpty(*q)){
        printf("Queue Underflow ");
        return x;
    }
    else{
        q->front++;
        x = q->Q[q->front];
        return x;
    }
}

// Main function with some operations of above described functions
int main(){
    
    // Create a Queue
    struct Queue q;
    Create(&q, 7);

    // Check if Queue is Empty or Not
    printf("%d\n", isEmpty(q));

    // Push Elements in Queue
    Enqueue(&q, 56);
    Enqueue(&q, 3);
    Enqueue(&q, 16);

    // Check if Queue is Full or Not
    printf("%d\n", isFull(q));

    // Delete Element from Queue
    printf("%d Dequeud Successfully\n", Dequeue(&q));
    printf("%d Dequeud Successfully\n", Dequeue(&q));

    // Display Elements of Queue
    Display(q);

    return 0;
}