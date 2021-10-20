/* @uthor : Gorakh */

#include<stdio.h>
#include<stdlib.h>

// Create a Structure of Node which is going to be used
struct Node{
    struct Node * lchild;
    int data;
    struct Node * rchild;
};

// Create a Structure of Queue
struct Queue{
    int size;
    int rear;
    int front;
    struct Node **Q;
};

// Create a Queue with Desired size
void Create(struct Queue *q, int size){
    q->size = size;
    q->rear = q->front = -1;
    q->Q = (struct Node **)malloc(q->size * sizeof(struct Node *));  
}

// Return 1 if Queue is Empty else return 0
int isEmpty(struct Queue q){
    return (q.front == q.rear);
}

// Insert Elements in Queue
void Enqueue(struct Queue * q, struct Node * val){
    if ((q->rear + 1 )% (q->size) == q->front)
        printf("Queue Overflow\n\n");
    
    else{
        q->rear = (q->rear+1)% q->size;
        q->Q[q->rear] = val;
        // printf("%d Enqueud Successfully\n\n");
    }
}

// Deletion of Elements in Queue
struct Node * Dequeue(struct Queue *q){
    struct Node * x = NULL;
    if (q->rear == q->front)
        printf("Queue Underflow\n\n");
    else{
        q->front = (q->front+1)% q->size;
        x = q->Q[q->front];
    }
    return x;
}

// ***** Generating Tree Using Queue *******

struct Node * root = NULL;

// Generate Tree Function
void TreeCreate(){
    struct Node *p, *t;
    int x;
    struct Queue q;
    Create(&q, 100);

    printf("Enter Root Value : ");
    scanf("%d", &x);

    root = (struct Node *)malloc(sizeof(struct Node ));
    root->data = x;
    root->lchild = root->rchild = NULL;
    Enqueue(&q, root);

    while (!isEmpty(q))
    {
        p = Dequeue(&q);
        printf("\nEnter Left Child of %d ", p->data);
        scanf("%d", &x);

        if (x != -1){
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            Enqueue(&q, t);
        }

        printf("\nEnter Right Child of %d ", p->data);
        scanf("%d", &x);

        if (x != -1){
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            Enqueue(&q, t);
        }

    }
}

// Display Elements in PreOrder Traversal
void PreOrder(struct Node *p){
    if(p){
        printf("%d --> ", p->data);
        PreOrder(p->lchild);
        PreOrder(p->rchild);
    }
}

// Display Elements in InOrder Traversal
void InOrder(struct Node *p){
    if(p){
        InOrder(p->lchild);
        printf("%d --> ", p->data);
        InOrder(p->rchild);
    }
}

// Display Elements in PostOrder Traversal
void PostOrder(struct Node *p){
    if(p){
        PostOrder(p->lchild);
        PostOrder(p->rchild);
        printf("%d --> ", p->data);
    }
}

void LevelOrder(struct Node *root){
    struct Queue q;
    Create(&q, 100);
    printf("%d --> ", root->data);
    Enqueue(&q, root);
    while(!isEmpty(q)){
        root = Dequeue(&q);
        if (root->lchild){
            printf("%d --> ", root->lchild->data);
            Enqueue(&q, root->lchild);
        }

        if (root->rchild){
            printf("%d --> ", root->rchild->data);
            Enqueue(&q, root->rchild);
        }
    }
}

// Main Function
int main()
{
    TreeCreate();

    LevelOrder(root);
    
    return 0;
}
