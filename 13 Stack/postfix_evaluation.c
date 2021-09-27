/* 
@uthor : Gorakh
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Stack{
    int data;
    struct Stack * next;
};
struct Stack * top = NULL;

void Push(int x){
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

int Pop(){
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

int isOperand(char x){
    if (x == '+' || x == '-' || x == '*' || x == '/')
        return 0;
    return 1;
}

int Precedence(char x){
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    return 0;
}

char * InfixToPostfix(char * infix){
    int i = 0, j = 0;
    char *postfix;
    int leng = strlen(infix);
    postfix = (char *)malloc((leng+2)*sizeof(char));

    while(infix[i] != '\0'){
        if (isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else{
            if (Precedence(infix[i]) > Precedence(top->data))
                Push(infix[i++]);
            else
                postfix[j++] = Pop();
        }
    }
    while (top != NULL)
    {
        postfix[j++] = Pop();
    }
    postfix[j] = '\0';
    return postfix;
}

int Evaluation(char * postfix){
    int i = 0;
    int x1, x2, r;

    for (i = 0; postfix[i] != '\0'; i++)
    {
        if (postfix[i] == '#') continue;
        if (isOperand(postfix[i])){
            Push(postfix[i] - '0');
        }
        else{
            x2 = Pop();
            x1 = Pop();
            switch (postfix[i])
            {
            case '+': r = x1 + x2; Push(r); break;
            case '-': r = x1 - x2; Push(r); break;
            case '*': r = x1 * x2; Push(r); break;
            case '/': r = x1 / x2; Push(r); break;
            default: break;
            }
        }
    }
    return Pop();   
}

int main(){
    char * infix = "2+3*4-8/2";
    // char * postfix = "234*+82/-";

    char * postfix;
    Push('#');
    postfix = InfixToPostfix(infix);
    printf("%s\n", postfix);
    int result = Evaluation(postfix);
    printf("After Evaluation, Result is %d\n", result);
    return 0;
}