#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct Term{
    int coeff;
    int exp;
};

struct Polynomial{
    int n;
    struct Term * t;
};

void Create(struct Polynomial *p){
    printf("Enter Non-Zero Element : ");
    scanf("%d", &p->n);

    p->t = (struct Term *)malloc(p->n * sizeof(struct Term));
    printf("Enter Terms : \n");

    for (int i = 0; i < p->n; i++)
    {
        printf("Term no. %d : ", i+1);
        scanf("%d %d", &p->t[i].coeff, &p->t[i].exp);
    }
    
}
void Display(struct Polynomial p){
    for (int i = 0; i < p.n; i++)
    {
        if (p.t[i].exp == 0)
            printf("%d", p.t[i].coeff);
        else
            printf("%dx^%d + ", p.t[i].coeff, p.t[i].exp);
    }   
}

int Evaluate(int x, struct Polynomial p){
    int result = 0;
    for (int i = 0; i < p.n; i++)
    {
        result = result + (p.t[i].coeff * pow(x, p.t[i].exp));
    }
    return result;
}

struct Polynomial * Add(struct Polynomial *p1, struct Polynomial *p2){
    struct Polynomial *p3;
    p3 = (struct Polynomial *)malloc(sizeof(struct Polynomial));

    p3->t = (struct Term *)malloc((p1->n + p2->n) * sizeof(struct Term));

    int i, j, k;
    i = j = k = 0;
    while(i < p1->n && j < p2->n){
        if (p1->t[i].exp > p2->t[j].exp)
            p3->t[k++] = p1->t[i++];
        else if (p1->t[i].exp < p2->t[j].exp)
            p3->t[k++] = p2->t[j++];
        else{
            p3->t[k].exp = p1->t[i].exp;
            p3->t[k++].coeff = p1->t[i++].coeff + p2->t[j++].coeff;
        }
    }
    for(; i < p1->n; i++)
        p3->t[k++] = p1->t[i];
    for (; j < p2->n; j++)
        p3->t[k++] = p2->t[j];

    p3->n = k;
    
    return p3;
}

int main(){

    struct Polynomial p1, p2, *p3;
    
    Create(&p1);
    printf("\n\nPolynomial 1\n\n");
    Display(p1);

    Create(&p2);
    printf("\n\nPolynomial 2\n\n");
    Display(p2);
    
    printf("\n\nPolynomial After Sum\n\n");
    p3 = Add(&p1, &p2);
    Display(*p3);
    return 0;
}