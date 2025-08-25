#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <stdio.h>

int main() {
    int n, i = 2;
    int flag = 1;

    // Read input
    printf("Enter a number: ");
    scanf("%d", &n);

    // If n <= 1, it's not prime
    if (n <= 1) {
        printf("n is not prime\n");
        return 0;
    }

    // Loop from i=2 to n/2
    while (i < n / 2) {
        if (n % i == 0) {
            flag = 0;
            break; // Can break early when divisible
        }
        i = i + 1;
    }

    // Final check on flag
    if (flag == 0) {
        printf("n is not prime\n");
    } else {
        printf("n is prime\n");
    }

    return 0;
}
