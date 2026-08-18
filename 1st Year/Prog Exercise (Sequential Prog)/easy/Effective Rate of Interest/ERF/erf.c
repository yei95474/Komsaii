#include <stdio.h>
#include <math.h>

int main() {
    float r=0.08, m=4, r_eff;
    r_eff=pow((1+r/m), m)-1;
    printf("%f", r_eff);
    return 0;
}