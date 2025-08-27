#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main () {
    int x, rev=0, peel;
    printf("Enter Number : ");
    scanf("%d", &x);
    int orig=x;
    while (x!=0){
        peel = x%10;
        rev = rev*10+peel;
        x /= 10;
    }

    if (rev == orig) {
        printf("Palindrome");
    }
    else {
        printf("Not Palindrome");
    }
    return 0;
}
