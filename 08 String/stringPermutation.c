#include<stdio.h>

void swap(char * a, char * b){
    char t;
    t = *a;
    *a = *b;
    *b = t;

}
void perm(char *arr, int l, int h){
    if (l == h){
        printf("%s\n", arr);
    }
    else{
        for (int i = l; i < h+1; i++)
        {
           swap(&arr[l], &arr[i]);
           perm(arr, l+1, h);
           swap(&arr[i], &arr[l]);
        }    
    }
}

int main(){

    char s[] = "ABCD";
    perm(s, 0, 3);   
    return 0;
}