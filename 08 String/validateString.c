#include<stdio.h>

int valid(char * s){
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (!((s[i] >= 65 && s[i] <= 90) || 
        (s[i] >= 'a' && s[i] <= 'z') || 
        (s[i] >= '0' && s[i] <= '9'))){
            return 0;
        }
    }
    return 1;
}

int main(){

    char s[] = "validString1234"; 
    if (valid(s))
        printf("String is valid...");
    else
        printf("String is Invalid...");

    return 0;
}