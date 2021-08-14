// Recursive method

#include<stdio.h>

double eR(int x, int n){
    static double pow = 1, fact = 1;
    double res;
    if (n == 0){
        return 1;
    }
    else{
        res = eR(x, n-1);
        pow = pow * x;
        fact = fact * n;
        return res + pow/fact;
    }
}

int main(){

    printf("%lf\n", eR(1, 10));
    return 0;
}
// Output 
// 2.718282




// Efficient Iterative Method
#include<stdio.h>

double efficient_eI(int x, int n){
    double s = 1;
    for ( ; n > 0; n--)
    {
        s = 1 + x * s / n ;
    }
    return s;
}
int main(){

    printf("%lf\n", efficient_eI(1, 10));
    return 0;
}
// Output 
// 2.718282



// Efficient Recursive Method

double efficient_eR(int x, int n){
    static double s = 1;
    if (n == 0){
        return s;
    }
    s = 1 + x * s / n;
    return efficient_eR(x, n-1);
}


int main(){

    printf("%lf\n", efficient_eR(1, 10));
    return 0;
}
// Output 
// 2.718282



