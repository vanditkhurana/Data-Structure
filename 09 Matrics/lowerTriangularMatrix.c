#include<stdio.h>
#include<stdlib.h>

struct Matrix{
    int * A;
    int n;
};

void setElement(struct Matrix *m, int i, int j, int val){
    if (i >= j){
        m->A[i * (i-1)/2 + j-1] = val;
    }
}

void Display(struct Matrix *m){
    for (int i = 1; i <= m->n; i++)
    {
        for (int j = 1; j <= m->n; j++)
        {
            if (i >= j)
                printf("%d ", m->A[i * (i-1)/2 + j-1]);
            else
                printf("0 ");
        }
        printf("\n");
    }
    
}

int main(){

    struct Matrix m;
    int val;
    printf("Enter Dimension : \n");
    scanf("%d", &m.n);

    m.A = (int *)malloc(m.n * (m.n + 1)/2 * sizeof(int));
    printf("Enter Elements : \n");
    for (int i = 1; i <= m.n; i++)
    {
        for (int j = 1; j <= m.n; j++)
        {
            scanf("%d", &val);
            setElement(&m, i, j, val);
        }
        
    }
    printf("\n\n");
    Display(&m);

    return 0;
}