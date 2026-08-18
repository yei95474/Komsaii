#include <stdio.h>

int main() {
    int n, sum=0;
    printf("Enter n: ");
    scanf("%d", &n);
    for (int i=1; i<n; i++) {
        if (n%i==0) {
            sum+=i;
        }
    }
    printf("Sum = %d\n", sum);
    if (sum>n) {
        printf("Abundant Number");
    }
    else if (sum<n) {
        printf("Deficit Number");
    }
    else {
        printf("Perfect Number");
    }
    return 0;
}