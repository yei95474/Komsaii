#include <stdio.h> 
#include <math.h> 
int main() { 
    int n, nc=0; 
    //get p 
    printf("(2^n)-1\n"); 
    printf("Enter n: "); 
    scanf("%d", &n); 
    //check if p is prime 
    for(int i=1; i<=n; i++) { 
        if (n%i==0) {
            printf("%d ", i); 
            nc++; 
        } 
    } 
    if (nc>2) { 
        printf("\nNot Prime!"); 
        return 1; 
    } 
    //check if mersenne prime 
    float mp=log2(n+1); 
    int mpc=0; 
    printf("\nlog_2(%d) = %.4f\n",n, mp); 
    if (fabs(mp-round(mp))>0.00000001) { 
        printf("Must be Integer!"); 
        return 1;
    } 
    int mp_int=round(mp); 
    for(int i=1; i<=mp_int; i++) { 
        if (mp_int%i==0) { 
            printf("%d ", i); 
            mpc++; 
        } 
    } 
    if (mpc>2) { 
        printf("\nNot Prime!"); 
        return 1; 
    } 
    printf("\n\n%d is a Mersenne Prime (%d)", n, mp_int); 
    return 0; 
}