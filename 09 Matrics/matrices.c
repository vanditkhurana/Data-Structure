#include<stdio.h>

struct Matrix{
    int A[10];
    int n;
};

void setDetailsDiagonal(struct Matrix *m, int i, int j, int val){
    if (i == j){
        m->A[i] = val;
    }
}

int getDetailsDiagonal(struct Matrix *m, int i, int j){
    if (i == j){
        return m->A[i];
    }
    return 0;
}

void DisplayDiagonal(struct Matrix *m){
    printf("\n\n");
    for (int i = 0; i < m->n; i++)
    {
        for (int j = 0; j < m->n; j++)
        {
            if (i == j)
                printf("%8d ", m->A[i]);
            else
                printf("%8d ", 0);
        }
        printf("\n\n"); 
    }
    printf("\n"); 
}

void DiagonalMatrix(struct Matrix *m){
    char choice1 = 'y';
    int i, j, val;
    int n;

    do
    {
        printf("1. Add Element\n");
        printf("2. Get Element\n");
        printf("3. Display Elements\n");
        printf("8. Back Menu\n");

        printf("\n\nEnter Choice : ");
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            printf("Enter Locations (i and j) and Value : \n");
            scanf("%d %d %d", &i, &j, &val);
            setDetailsDiagonal(m, i, j, val);
            break;
        case 2:
            printf("Enter Locations (i and j) : \n");
            scanf("%d %d %d", &i, &j);
            val = getDetailsDiagonal(m, i, j);
            printf("\n\nValue at (%d, %d) is %d\n", i, j, val);
            break;

        case 3:
            DisplayDiagonal(m);
            break;

        case 8:
            choice1 = 'n';
            break;
        
        default:
            printf("Wrong Choice\n");
            break;
        }

    } while (choice1 == 'y');
}



int main(){
    char choice = 'y';
    struct Matrix m;
    m.n = 4;
    int n;

    do
    {
        printf("1. Diagonal Matrix\n");
        printf("8. Exit\n");

        printf("\n\nEnter Choice : ");
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            DiagonalMatrix(&m);
            break;
        case 8:
            printf("Thanks for using...\n");
            choice = 'n';
            break;
        
        default:
            printf("\nWrong Choice\n\n");
            break;
        }

    } while (choice == 'y');


    
    return 0;
}
