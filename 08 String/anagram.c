
// USING HASH TABLE
// THIS PROGRAM IS ONLY FOR LOWER CASE CHARACTER 
// FOR UPPER CASE CHARACTER YOU HAVE TO MODIFY THE VALUE 
// WHICH WE ARE SUBSTRACTING

#include<stdio.h>

int main(){

    char s1[] = "case";
    char s2[] = "sace";
    int val, flag = 1;
    char new_s[26] = {0};

    for (int i = 0; s1[i] != '\0'; i++)
    {
        val = s1[i] - 97;
        new_s[val]++;
    }
    for (int i = 0; s2[i] != '\0'; i++)
    {
        val = s2[i] - 97;
        new_s[val]--;
    }
    
    for (int i = 0; i < 26; i++)
    {
        if (new_s[i] != 0){
            flag = 0;           
        }
    }
    if (flag)
        printf("Strings are Anagram\n");
    else
        printf("Strings are not Anagram\n");    
    
    
    return 0;
}