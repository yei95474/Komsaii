#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n, i = 2;
    int flag = 1;
    int response;
    int Yn[] = {0,1};

    do {
printf("Enter a number: ");
scanf("%d", &n);

    while (getchar() != '\n') {
        printf("Invalid \n\nEnter again\n\n");
        scanf("%d", &n);
       }

printf("Your number is %d\n", n);
    if (n <= 1) {
        printf("n is not prime\n\n");
    }

    while (i <= n / 2) {
        if (n % i == 0) {
            flag = 0;
            break;
        }
        else {
        i = i + 1;
    } }

    if (flag == 0) {
        printf("n is not prime\n\n");
    } else {
        printf("n is prime\n\n");
    }
int n, i = 2;
int flag = 1;

printf("Would you like to try again?\n\n0-Yes\n\n1-No\n");
scanf("%d", &response);

    while ((getchar() != '\n') || response>=2) {
        printf("Invalid \n\nTry Again\n\n0-Yes\n\n1-No\n");
        scanf("%d", &response);
        if (response==1 || response==0) {
        break; }

        }

    if (response == Yn[1]) {
        printf("Thank you!\n");
        break;
    }
    else {
        continue;
    }
    } while (response == Yn[0]);

    return 0;
}

//NGGAAAA MU SPAM AG INVALID TRY AGAIN BY THE NUMBER OF CHARACTERS SA IMO INPUT IF n!= integer
