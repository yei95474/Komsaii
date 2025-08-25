#include <stdio.h>

int main() {
    int limit = 4000000;
    int a = 1, b = 2;
    int even_sum = 0;

    while (a <= limit) {
        if (a % 2 == 0) {
            even_sum += a;
        }
        int next = a + b;
        a = b;
        b = next;
    }

    printf("%d\n", even_sum);
    return 0;
}