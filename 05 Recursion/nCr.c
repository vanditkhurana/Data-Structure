// Iterative method

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
// Output : 20.00


// Recursive Method using Pascal's Triangle Method

#include<stdio.h>

double nCr_R(int n, int r){
    if (r == 0 || n == r)
        return 1;
    return nCr_R(n-1, r-1) + nCr_R(n-1, r);
}
int main(){
    double res_r;
    res_r = nCr_R(6, 3);
    printf("%.2lf\n", res_r);
    return 0;
}
// Output : 20.00