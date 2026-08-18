#include <stdio.h>

int main() {
    int n1, n2, gcd;
    printf("Enter n1: ");
    scanf("%d", &n1);
    printf("Enter n2: ");
    scanf("%d", &n2);
    int min = (n1<n2)? n1: n2;
    for (int i=1; i<=min; i++) {
        if (n1%i==0 && n2%i==0) {
            gcd=i;
        }
    }
    
    if (gcd==1) {
        printf("Relative Prime");
    }
    else if(gcd>1) {
        printf("Not Relative Prime");
    }
    return 0;
}