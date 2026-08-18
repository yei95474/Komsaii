#include <stdio.h>   // 👈 needed for scanf, printf
#include <stdlib.h>
#include <math.h>

int main () {
    int size, sumf = 0,n=1;
    printf("Enter Size: ");
    scanf("%d", &size);
    while (n <= size) {
        sumf += n;
        n += 1;
    }

    printf("sumf %d\n", sumf);
    return 0;
}
