#include <stdio.h>

int main() {

    int n = 1;
    for (int i=0;i<4000000000;i++) {
         n += n;

    }
    printf("%d\n", n);
    return 0;
}
