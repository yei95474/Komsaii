#include <stdio.h>

int main() {
    int dividend=10, divisor=3, rem, q=0;
    for (int n=dividend; n>divisor; n-=divisor) {
        rem=n-divisor;
        q++;
        printf("%d - %d = %d, Partial Quotient: %d\n", n, divisor, rem, q);
    }

    printf("\nQuotient: %d, Remainder: %d", q, rem);
    return 0;
}