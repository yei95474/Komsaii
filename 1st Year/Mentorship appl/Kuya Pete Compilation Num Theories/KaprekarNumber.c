#include <stdio.h>
#include <math.h>

int main() {
    int nb, size=0;
    printf("Enter n: ");
    scanf("%d", &nb);
    int n=nb*nb;
    
    printf("\n%d^2 = %d\n", nb, n);
    int tn=n;
    while (tn>0) {
        tn/=10;
        size++;
    }
    
    int p1,p2,p1n=0,p2n=0;
    p1=size/2;
    p2=size-p1;
    
    tn=n;
    int m=1;
    for (int i=0; i<p2; i++){
        p2n = p2n + (tn % 10) * m;
        tn/=10;
        m*=10;
    }
    
   m=1;
    for (int i=0; i<p1; i++){
        p1n = p1n + (tn % 10) * m;
        tn/=10;
        m*=10;
    }
    printf("%d|%d\n", p1n, p2n);
    int sum=p1n+p2n;
    printf("%d + %d = %d\n", p1n, p2n, sum);
    if (sum==nb) {
        printf("\nKaprekar Number");
    }
    else {
        printf("\nNot a Kaprekar Number");
    }
    
    return 0;
}