// Fibonacci Series
// Sum of Previous 2 terms
// 0 1 1 2 3 5 8 and so on...

// Iterative Method  Time Complexity O(n)
#include<stdio.h>

int fiboI(int n){
    int t0 = 0, t1 = 1;
    int s;
    if (n <= 1){
        return n;
    }
    
    for (int i = 2; i < n+1; i++)
    {
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }
    
    return s;
}

int main(){

    int i;
    i = fiboI(6);
    printf("%d\n", i);
    return 0;
}
// Output
// 8


// Recursive Method Time Complexity (Aprox. 2^n)
#include<stdio.h>

int fiboR(int n){
    if (n <= 1){
        return n;
    }
    return fiboR(n-2) + fiboR(n-1);
}
int main(){   
    int r;
    r = fiboR(6);
    printf("%d\n", r);
    return 0;
}
// Output
// 8



//  
#include<stdio.h>

int F[10];
int effective_fibo(int n){
    if (n <= 1){
        F[n] = n;
        return n;
    }
    else{
        if (F[n-2] == -1){
            F[n-2] = effective_fibo(n-2);
        }
        if (F[n-1] == -1){
            F[n-1] = effective_fibo(n-2);
        }
        return effective_fibo(n-2) + effective_fibo(n-1);
    }
}
int main(){
    for (int i = 0; i < 10; i++)
    {
        F[i] = -1;
    }
    int eff_r;
    eff_r = effective_fibo(6);
    printf("%d\n", eff_r);
    return 0;
}
// Output
// 8
