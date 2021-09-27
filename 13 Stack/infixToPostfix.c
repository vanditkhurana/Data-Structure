/* 
@uthor : Gorakh
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


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

int main(){

    char * infix = "a+b*c-d/e";
    char * postfix;
    Push('#');

    postfix = InfixToPostfix(infix);
    printf("\n\n\n");
    printf("Postfix of the Operation is : ");
    printf("%s\n", postfix);
    printf("\n\n\n");

    return 0;
}