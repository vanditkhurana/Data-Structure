// #include<stdio.h>
// void funB(int n);

// void funA(int n){
//     if (n > 0){
//         printf("%d ", n);
//         funB(n-1);
//     }
// }

// void funB(int n){
//     if (n > 1){
//         printf("%d ", n);
//         funA(n/2);
//     }
// }

// int main(){

//     funA(20);    
//     return 0;
// }



// #include<stdio.h>

// int fun(int n){
//     if (n > 100)
//         return n - 10;
//     else
//         return fun(fun(n+11));
// }

// int main(){

//     printf("%d ", fun(56));
//     return 0;
// }


// #include<stdio.h>

// int sumR(int n){
//     if (n == 0){
//         return 0;
//     }
//     return sumR(n-1) + n;
// }

// int sumI(int n){
//     int sum = 0;
//     for (int i = 1; i <= n ; i++)
//     {
//         sum = sum + i;
//     }
//     return sum;   
// }

// int sumF(int n){
//     return n*(n+1)/2;
// }

// int main(){

//     int r, i, f;
//     r = sumR(5);
//     i = sumI(5);
//     f = sumF(5);
//     printf("%d\n", r);
//     printf("%d\n", i);
//     printf("%d\n", f);
//     return 0;
// }



#include<stdio.h>

int factI(int n){
    int fac = 1;
    for (int i = n; i > 0; i--)
    {
        fac = fac * i;
    }
    return fac;
}

int factR(int n){
    if (n == 0){
        return 1;
    }
    return n * factR(n-1);
}

int main(){

    int r;
    r = factR(5);
    printf("%d\n", r);
    return 0;
}