#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main () {
    int coin, Q, F, T, O, r;
    printf("Enter Coin: ");
    scanf("%d", &coin);
    Q=coin/25;
    r=coin%25;
    T=r/10;
    r=r%10;
    F=r/5;
    r=r%5;
    O=r/1;
    printf("\n%d = %d:25, %d:10, %d:5, %d:1", coin, Q, T, F ,O);
    return 0;
}