#include <stdio.h>
#include <math.h>

int main() {
    long long int NthPrime = 0;

    for (int i = 2; i < 2000000; i++) {
        int factorCtr = 0;
        for (int j = 1; j * j <= i; j++) {
            if (i % j == 0) {
                factorCtr++;
                if (j != i / j) factorCtr++;  // count both factors (j and i/j)
            }
            if (factorCtr > 2) break;  // not prime anymore
        }
        if (factorCtr == 2) {
            NthPrime += i;
        }
    }

    printf("%lld\n", NthPrime);
    return 0;
}
