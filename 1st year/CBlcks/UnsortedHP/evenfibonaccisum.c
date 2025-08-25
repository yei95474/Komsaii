#include <stdio.h>

int main() {
    long long limit = 100;
    long long largest_prime = 0;

    for (long long i = 2; i <= limit; i++) {
        if (limit % i == 0) {
            largest_prime = i;
            limit /= i;
            i--;  
        }
    }
   printf("%lld\n", largest_prime);
    return 0;
}
