#include <stdio.h>

int main () {
int size, a=0, b=1, temp, c=0;
float ratio, odd=0, even=0;

printf("N: ");
scanf("%d", &size);

printf("Sequence: ");
for (int i=0; i<size; i++) {
    printf("%d ", a);
    temp=a+b;
    a=b;
    b=temp;

    if (b%2==0) {
        even++;
    }
    else {
        odd++;
    }
}
ratio=odd/even;
printf("\n\nOdd Fib: %.f\n", odd);
printf("Even Fib: %.f\n", even);
printf("Ratio: %.2f\n", ratio);
return 0;
}
