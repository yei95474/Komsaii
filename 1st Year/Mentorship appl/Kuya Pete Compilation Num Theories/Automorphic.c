#include <stdio.h>
#include <math.h>

int main() {
    int nb, size=0, se=0;
    printf("Enter n: ");
    scanf("%d", &nb);
    int n=nb*nb;
    
    printf("\n%d^2 = %d\n", nb, n);
    int tn=nb;
    while (tn>0) {
        tn/=10;
        size++;
    }
    
    tn=n;
    int m=1;
    for (int i=0; i<size; i++) {
        int temp=tn%10;
        se=se+temp*m;
        tn/=10;
        m*=10;
    }
    
    if (se==nb) {
        printf("\nAutomorphic Number");
    }
    else {
        printf("\nNot an Automorphic Number");
    }
    
    return 0;
}