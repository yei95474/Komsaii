#include <stdio.h>

int main () {
    int a,b,sum_a=0,sum_b=0;

    printf("Integer A: ");
    scanf("%d", &a);
    printf("Integer B: ");
    scanf("%d", &b);

    if (a<=0 || b<=0) {
        printf("Invalid Number/s\n");
        return 1;
    }

    for(int i=1; i<a; i++) {
        if (a%i==0) {
            sum_a+=i;
        }
    }

    for(int i=1; i<b; i++) {
        if (b%i==0) {
            sum_b+=i;
        }
    }

    printf("Sum of factors for A: %d\n", sum_a);
    printf("Sum of factors for B: %d\n", sum_b);
    if (sum_a < sum_b) {
        printf("The Sum of factors for Integer A < Integer B");
    }
    else if (sum_a > sum_b) {
        printf("The Sum of factors for Integer A > Integer B");
    }
    else {
        printf("Equal");
    }
    return 0;
}
