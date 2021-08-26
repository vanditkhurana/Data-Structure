/*  Author : Gorakh 
    Twitter : @gorakhcodes
*/ 

#include<stdio.h>
#include<stdlib.h>

struct Stack{
    int size;
    int top;
    int * a;
};

void Create(struct Stack * st){
    printf("Enter size of Stack\n");
    scanf("%d", &st->size);  
    st->top = -1;
    st->a = (int *)malloc(st->size * sizeof(int));
}

void Display(struct Stack st){
    for(int i = st.top; i >= 0; i--){
        printf("%d ", st.a[i]);
    }
    printf("\n");
}

int isEmpty(struct Stack st){
    if (st.top == -1)
        return 1;
    else
        return 0;
}

int isFull(struct Stack st){
    if (st.top == st.size - 1)
        return 1;
    else
        return 0;
}

void Push(struct Stack * st, int x){
    if (isFull(*st))
        printf("Stack Overflow\n");
    else{
        st->top++;
        st->a[st->top] = x;
        printf("%d Pushed in Stack!!!\n", x);
    }
}

int Pop(struct Stack * st){
    int x = -1;
    if (isEmpty(*st))
        printf("Stack Underflow\n");
    else{
        x = st->a[st->top];
        st->top--;
    }
    return x;
}

int Peek(struct Stack st, int pos){
    int x = -1;
    if (st.top + 1 - pos < 0 && pos > st.top){
        printf("Position Invalid\n");
        return x;
    }
    else{
        x = st.a[st.top+1-pos];
        return x;
    }
}

int StackTop(struct Stack st){
    if (!isEmpty(st))
        return st.a[st.top];
    return -1;
}

int main(){

    struct Stack st;

    // Creation of Stack
    Create(&st);   

    // Check if a Stack is Empty or Not
    if(isEmpty(st))
        printf("Stack is Empty\n");
    else
        printf("Stack is Not Empty\n");

    // Push Element in Stack
    Push(&st, 23);
    Push(&st, 65);
    Push(&st, 87);
    Push(&st, 67);

    // Peek Element in Stack
    printf("%d present at Index %d\n", Peek(st, 1), 1);
    printf("%d present at Index %d\n", Peek(st, 3), 3);

    // Pop a element from Stack
    printf("%d Popped\n", Pop(&st));
    printf("%d Popped\n", Pop(&st));

    // stack Top 
    printf("Stack Top : %d\n", StackTop(st));

    // Check if a Stack is Full or Not
    if(isFull(st))
        printf("Stack is Full\n");
    else
        printf("Stack is Not Full\n");

    // Displaying Elements in Stack
    Display(st); 
    return 0;
}