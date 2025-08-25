#include <stdio.h>

int main() {
    int x;

    while (2) {
        printf("Enter an integer: ");
        if (scanf("%d", &x) != 1) {
            printf("Invalid input! Please enter an integer.\n");
            return 1;  // exit or handle error
        }
    }

printf("You entered %d\n", x);
return 0;
}
