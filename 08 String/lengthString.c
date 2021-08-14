#include<stdio.h>
#include<string.h>

int main(){


    char *name = "Ramesh";
    int i;

    // Manual Method
    for ( i = 0; name[i] != '\0'; i++);
    printf("Length of String Using Manual Methodis %d\n", i);

    // Inbuilt Function
    int len = strlen(name);
    printf("Length of String Using Inbuilt Function is %d\n", i);
    
    return 0;
}