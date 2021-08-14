// #include<stdio.h>

// int main(){

//     char s[] = "WELCOME";

//     for (int i = 0; s[i] != '\0'; i++)
//     {
//         s[i] = s[i] + 32;
//     }
//     printf("New string is : \'%s\'\n", s);
    
//     return 0;
// }



// #include<stdio.h>

// int main(){

//     char s[] = "welcome";

//     for (int i = 0; s[i] != '\0'; i++)
//     {
//         s[i] = s[i] - 32;
//     }
//     printf("New string is : \'%s\'\n", s);
    
//     return 0;
// }


// Toggle Cases : if it is lower then convert it to upper and vice-versa

#include<stdio.h>

int main(){

        char s[] = "wELcOmE";

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z'){
            s[i] += 32;
        }
        else if (s[i] >= 'a' && s[i] <= 'z'){
            s[i] -= 32;
        }
    }
    printf("New string is : \'%s\'\n", s);
    return 0;
}