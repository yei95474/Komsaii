/* Product of Digits – The Lock Code A lock
only opens if you multiply all the digits of
a 4-digit code and the result is 0.
Given a code like 4065, does the lock open?
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main () {
    int n, peel, productf =1;
    printf("Enter Number: ");
    scanf("%d", &n);

    while (n!=0){
        peel = n%10;
        productf*= peel;
        n /= 10;
    }

    printf("\nThe product is: %d\n", productf);
    if (productf==0) {
        printf("The lock is open");
    }
    else {
        printf("Still locked");
    }
    return 0;
}
