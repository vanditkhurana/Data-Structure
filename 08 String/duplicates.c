#include<stdio.h>

int main(){
    char s[] = "findingi";
    int i, j, count;

    for ( i = 0; s[i] != '\0'; i++)
    {
        count = 1;
        for ( j = i+1 ; s[j] != '\0'; j++)
        {
            if (s[i] == s[j] && s[j] != '0'){
                count++;
                s[j] = '0';
            }
        }
        if (count > 1)
            printf("%c Occurs %d times\n", s[i], count);
    }
    return 0;
}




// USING HASH TABLE
// THIS PROGRAM IS ONLY FOR LOWER CASE CHARACTER 
// FOR UPPER CASE CHARACTER YOU HAVE TO MODIFY THE VALUE 
// WHICH WE ARE SUBSTRACTING

#include<stdio.h>

int main(){

    char s[] = "finding";
    char new_s[26];
    int val;
    for (int i = 0; i < 26; i++)
    {
        new_s[i] = 0;
    }

    for (int i = 0; s[i] != '\0'; i++)
    {
        val = s[i] - 97;
        new_s[val]++;
    }
    
    for (int i = 0; i < 26; i++)
    {
        if (new_s[i] > 1){
            printf("%c Occurs %d times\n", i + 97, new_s[i]);
        }
    }
    
    
    return 0;
}