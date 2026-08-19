#include <stdio.h>

int main() {
    int n1, n2, sum1=0, sum2=0;
    printf("Enter n1: ");
    scanf("%d", &n1);
    printf("Enter n2: ");
    scanf("%d", &n2);
    
    for (int i=1; i<n1; i++) {
        if (n1%i==0) {
            sum1+=i;
        }
    }
    
    for (int i=1; i<n2; i++) {
        if (n2%i==0) {
            sum2+=i;
        }
    }
    
    if (sum1==n2 && sum2==n1) {
        printf("\nAmicable Pairs");
    }
    else {
        printf("\nNot Amicable Pairs");
    }
    return 0;
}