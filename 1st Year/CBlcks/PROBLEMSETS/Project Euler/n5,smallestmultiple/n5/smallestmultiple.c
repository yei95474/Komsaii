#include <stdio.h>

int main() {
    int smallestMultiple=1;
    for (int i=1; i<=20; i++) {
        if(smallestMultiple%i==0) {
            continue;
        }
        int a=i, b=smallestMultiple;
        while(b!=0) {
            int temp = a%b;
            a=b;
            b=temp;
        }
        //a becomes the gcd
        smallestMultiple= (smallestMultiple*i)/a;
    }
    
    printf("%d", smallestMultiple);
    

    return 0;
}