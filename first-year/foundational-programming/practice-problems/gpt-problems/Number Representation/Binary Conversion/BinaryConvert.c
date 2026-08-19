#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main () {
    int n, binary=0;
    printf("Enter Number: ");
    scanf("%d", &n);

    while (n!=0) {
        
        if (n>64) {
            n %=64;
            binary = 1000000;
        }
        else {
            binary = 0000000;
        }

        if (n>32) {
            n%=32;
            binary+= 100000;
        }
        else {
            binary = 000000;
        }

        if (n>16) {
            n%=16;
            binary+= 10000;
        }
        else {
            binary += 00000;
        }

        if (n>8) {
            n%=8;
            binary += 1000;
        }
        else {
            binary += 0000;
        }

        if (n>4) {
            n%=4;
            binary += 100;
        }
        else {
            binary += 000;
        }

        if (n>2) {
            n%=2;
            binary += 10;
        }
        else {
            binary += 00;
        }

        if (n>1) {
            n%=1;
            binary +=1;
        }
        else {
            binary += 0;
        }
    }
    printf("Binary: %d", binary);
    return 0;
}