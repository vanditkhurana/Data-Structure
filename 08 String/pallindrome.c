
#include<stdio.h>
#include<string.h>

int StringPallindrome(char * str){
    int j, i;
    j = strlen(str);
    j = j - 1;
    for (i = 0; i <= j; i++, j--)
    {
        if (str[i] != str[j])
            return 0; 
    }
    return 1;
}

int main(){

    char s[] = "ajjjaa";

    if (StringPallindrome(s))
        printf("String is Pallindrome\n");
    else
        printf("String is not Pallindrome\n");
    
    return 0;
}