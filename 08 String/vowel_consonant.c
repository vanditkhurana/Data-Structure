#include<stdio.h>

int main(){

    char s[] = "C language is Good";
    int v_count = 0, c_count = 0;

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == 'a' || s[i] == 'A' || s[i] == 'e' || s[i] == 'E' ||
        s[i] == 'i' || s[i] == 'I' || s[i] == 'o' || s[i] == 'O' ||
        s[i] == 'u' || s[i] == 'U'){
            v_count++;
        }

        else if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')){
            c_count++;
        }
    }
    printf("Vowels : %d\n", v_count);
    printf("Consonants : %d\n", c_count);

    
    return 0;
}