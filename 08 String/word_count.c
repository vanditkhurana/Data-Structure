#include<stdio.h>

int main(){

    char s[] = "C language is    Good";
    int word_count = 1;

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == 32 && s[i-1] != 32){
            word_count++;
        }
    }
    printf("No. of Words are : %d", word_count);
    return 0;
}