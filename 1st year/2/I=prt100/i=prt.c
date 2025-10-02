#include <stdio.h>
#include <math.h>

int main ()
        {
    int temp, rev=0, n, rem,prod, largest,x,y;
    for (int i=999; i>=100; i--) {
        for(int j=999;j>=100; j--) {
            prod = i * j;

            n=prod;
            rev=0;
            while(n!=0) {
                rem=n%10;
                rev=rev*10+rem;
                n=n/10;
            }

            if (prod==rev && prod>largest) {
                largest=prod;
                x=i;
                y=j;
            }
        }
    }

    printf("Largest palindrome is: %d\n", largest);
    printf("x: %d, y: %d", x,y);
    return 0;
    }

     /*int temp, rev, n, rem,prod, largest;
    for (int i=998001; i>0; i-- ) {
        n=i;
        rev=0;
        while (n!=0) {
            rem = n%10;
            rev = rev * 10 + rem;
            n = n/10;
        }
        if (rev==i) {
            largest=i;
            printf("%d %d\n",largest, rev);
             break;
        }
    }

    for (int i=100; i<1000; i++) {
        for (int r=100; r<1000; r++) {
            prod=i*r;
             if (prod==largest) {
                printf("x %d y %d", i, r);
                break;
                }
            }
        } */
