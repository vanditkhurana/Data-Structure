#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

    char s[] = "C Language"; 
    int i, j;
    i = strlen(s);
    char *new_s = (char *)malloc(i * sizeof(char));
    i = i - 1;
    for (j = 0; i >= 0; j++, i--)
    {
        new_s[j] = s[i];
    }
    new_s[j] = '\0';
    printf("Reversed String : %s\n", new_s);
    return 0;
}


#include<stdio.h>
#include<string.h>

void swap(char *i, char *j){
    char t;
    t = *i;
    *i = *j;
    *j = t;
}

int main(){

    char s[] = "C Language"; 
    int j;
    j = strlen(s);
    j = j - 1;
    for (int i = 0; i < j; i++)
    {
        swap(&s[i], &s[j]);
        j--;
    }
    printf("Reversed String : %s\n", s);
    
    return 0;
}