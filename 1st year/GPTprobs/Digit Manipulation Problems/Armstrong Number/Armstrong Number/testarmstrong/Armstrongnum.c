/* Armstrong Number – The Special Number Plate A car’s plate 
number is “407”. If you cube each digit and add them, does it
equal the original plate number? */

# include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main () {
    int n, peel = 0, sumf=0;
    printf("Enter Number: ");
    scanf("%d", &n);

    while (n!= 0) {
        peel = n % 10;
        peel=peel*peel*peel;
        sumf += peel;
        n /= 10;
        }

    printf("Sum of Digits Cube is: %d", sumf);
    return 0;
}
