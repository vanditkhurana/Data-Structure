#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct Node{
    int coeff;
    int exp;
    struct Node * next;
};
struct Node * poly = NULL;

void Create(){
    int term;
    printf("Enter Number of terms \n");
    scanf("%d", &term);
    struct Node *t, *last = NULL;
    printf("Enter Coefficient and Exponents\n");
    for (int i = 0; i < term; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->next = NULL;
        scanf("%d %d", &t->coeff, &t->exp);
        if (poly == NULL)
            poly = last = t;
        else{
            last->next = t;
            last = t;
        }
    }
}

void Display(struct Node *p){
    while (p)
    {
        printf("%dx^%d + ", p->coeff, p->exp);
        p = p->next;
    }
    printf("\n");
}

long Eval(struct Node *p, int x){
    long sum = 0;
    while (p)
    {
        sum = sum + p->coeff*pow(x, p->exp);
        p = p->next;    
    }
    return sum;
}

int main(){

    Create();
    Display(poly);
    printf("%d\n", Eval(poly, 1));
    return 0;
}