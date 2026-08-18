#include <stdio.h>

int main() {
    int Primectr=0, NthPrime;
    for (int i=2;Primectr<10001;i++) {
        int factorCtr=0;
        for (int j=1; j<=i; j++) {
            if(i%j==0) {
                factorCtr++;
            }
        }
        if (factorCtr==2) {
            NthPrime=i;
            Primectr++;
        }
    }
    printf("%d", NthPrime);

    return 0;
}