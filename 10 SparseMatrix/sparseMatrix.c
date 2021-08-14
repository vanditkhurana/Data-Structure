#include<stdio.h>
#include<stdlib.h>

struct Element{
    int i;
    int j;
    int x;
};

struct Sparse{
    int m;
    int n;
    int num;
    struct Element * e;
};

void Create(struct Sparse * s1){
    printf("Enter Dimension : ");
    scanf("%d %d", &s1->m, &s1->n);
    printf("Enter No. of Non-zero Element : ");
    scanf("%d", &s1->num);

    s1->e = (struct Element *)malloc(s1->num * sizeof(struct Element));
    printf("Enter Elements : Row_No Col_No Val\n");
    for (int i = 0; i < s1->num; i++)
    {
        scanf("%d %d %d", &s1->e[i].i, &s1->e[i].j, &s1->e[i].x);
    }
}

void Display(struct Sparse s1){
    for (int i = 0; i < s1.m; i++)
    {
        for (int j = 0; j < s1.n; j++)
        {
            if (i == s1.e[i].i && j == s1.e[i].j)
                printf("%d ", s1.e[i].x);
            else    
                printf("0 ");
        }
        printf("\n");
    }
}

struct Sparse * Add(struct Sparse * s1, struct Sparse * s2){
    struct Sparse * sum;
    sum = (struct Sparse *)malloc(sizeof(struct Sparse));
    sum->e = (struct Element *)malloc((s1->num + s2->num) * sizeof(struct Element));

    int i, j, k;
    i = j = k = 0;

    while (i < s1->num && j < s2->num){
        if (s1->e[i].i < s2->e[j].i)
            sum->e[k++] = s1->e[i++];
        else if (s1->e[i].i > s2->e[j].i)
            sum->e[k++] = s2->e[j++];
        else{
            if (s1->e[i].j < s2->e[j].j)
                sum->e[k++] = s1->e[i++];
            else if (s1->e[i].j > s2->e[j].j)
                sum->e[k++] = s2->e[j++];
            else{
                sum->e[k] = s1->e[i];
                sum->e[k++].x = s1->e[i++].x + s2->e[j++].x;
            }
        }
    }
    for(; i < s1->num; i++) sum->e[k++] = s1->e[i];
    for(; j < s2->num; j++) sum->e[k++] = s2->e[j];
    sum->m = s1->m;
    sum->n = s1->n;
    sum->num = k;

    return sum;
}

int main(){

    struct Sparse s1, s2, *s3;
    Create(&s1);
    printf("\nMatrix 1 \n\n");
    Display(s1);

    Create(&s2);
    printf("\nMatrix 2 \n\n");
    Display(s2);  

    s3 = Add(&s1, &s2);
    printf("\nSum Matrix \n\n");
    Display(*s3);  
    return 0;
}