#include <stdio.h>
#include<stdlib.h>
#include <math.h>

int main () {
    float C, F, K;
    printf("Enter C: ");
    scanf("%f", &C);
    F= (C*9/5)+32;
    K= C+273.15;
    printf("F: %.2f F, K: %.2f K", F, K);
    return 0;
}