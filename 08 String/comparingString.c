#include<stdio.h>

int main(){

    char a[] = "paint";
    char b[] = "ascent";
    int i, j;

    for (i = 0, j = 0; a[i] != '\0' && b[i] != '\0' ; i++, j++)
    {
        if (a[i] != b[j])
            break;
    }
    if (a[i] == b[j])
        printf("Strings are Equal\n");
    else if (a[i] > b[j])
        printf("String \'%s\' is Greater\n", a);
    else
        printf("String \'%s\' is Greater\n", b);
    
    return 0;
}