// @gorakhcodes !!!

#include<stdio.h>
#include<stdlib.h>

struct Stack{
    char data;
    struct Stack * next;
};
struct Stack * top = NULL;

void Push(char x){
    struct Stack * t;
    t = (struct Stack *)malloc(sizeof(struct Stack));
    if (t == NULL)
        printf("Stack Overflow\n");
    else{
        t->data = x;
        t->next = top;
        top = t;
    }
}

char Pop(){
    struct Stack * p = top;
    int x = -1;
    if (top == NULL)
        printf("Stack Underflow\n");
    else{
        
        top = top->next;
        x = p->data;
        free(p);
    }
    return x;
}

int BracketMatching(char * exp){
    char x;
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            Push(exp[i]);
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']'){
            if (top == NULL) return 0;
            x = Pop();
            if (exp[i] == ')' && x != '(') return 0;
            if (exp[i] == '}' && x != '{') return 0;
            if (exp[i] == ']' && x != '[') return 0;
        }
    }

    if (top == NULL)
        return 1;
    else
        return 0;
}

int main(){
    
    char * exp = "[{(a+b) * {(c+d)}]}";

    printf("%d\n", BracketMatching(exp));
    // Output : 0

    return 0;
}