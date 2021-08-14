// #include<stdio.h>

// int powerI(int m, int n){
//     int res = 1;
//     while (n > 0)
//     {
//         res = res * m;
//         n--;
//     }
//     return res;   
// }

// int main(){

//     int i;
//     i = powerI(2, 9);
//     printf("%d\n", i);
//     return 0;
// }
// Output 
// 512




// #include<stdio.h>

// int powerR(int m, int n){
//     if (n==0){
//         return 1;
//     }
//     return powerR(m, n-1) * m;
// }

// int main(){

//     int r;
//     r = powerR(2, 9);
//     printf("%d\n", r);
//     return 0;
// }

// // Output 
// // 512


// #include<stdio.h>

// int power_efficient(int m, int n){
//     if (n == 0)
//         return 1;
//     else if (n % 2 == 0)
//         return power_efficient(m*m, n/2);
//     else    
//         return m * power_efficient(m*m, (n-1)/2);
// }

// int main(){

//     int r_ef;
//     r_ef = power_efficient(2, 9);
//     printf("%d\n", r_ef);
//     return 0;
// }