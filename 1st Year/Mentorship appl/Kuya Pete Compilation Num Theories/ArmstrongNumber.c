#include <stdio.h>
#include <math.h>

int main() {
    int n, size=0, sumf=0;
    printf("Enter n: ");
    scanf("%d", &n);
    
    int tn=n;
    while (tn>0) {
        tn/=10;
        size++;
    }
    
    tn=n;
    while (tn>0) {
        int temp=tn%10;
        sumf+=pow(temp, size);
        tn/=10;
    }
    
    if(n==sumf) {
        printf("Armstrong Number");
    }
    else {
        printf("Not an Armstrong Number");
    }
    return 0;
}