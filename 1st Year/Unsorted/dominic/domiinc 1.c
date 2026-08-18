#include <stdio.h>
#include <stdlib.h>

int main() {

    int n, sum = 0;

    printf("the numbers i choose are : ");

    while (n>0) {
        scanf("%d", &n);
        sum += n; }

    printf("%d", sum);

    return 0;
}