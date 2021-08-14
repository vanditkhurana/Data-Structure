#include<stdio.h>

int factI(int n){
    int fac = 1;
    for (int i = n; i > 0; i--)
        fac = fac * i;
    return fac;
}

double nCr_I(int n, int r){
    double t1, t2, t3;
    t1 = factI(n);
    t2 = factI(r);
    t3 = factI(n-r);
    return t1/(t2 * t3);
}

int main(){

    double res;
    res = nCr_I(6, 3);
    printf("%.2lf\n", res);
    return 0;
}