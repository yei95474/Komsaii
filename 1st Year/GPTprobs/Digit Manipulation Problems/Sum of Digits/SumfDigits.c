/* Sum of Digits – The Cashier’s Mistake A 
cashier accidentally adds up all the digits of a 
customer’s ID number 4927. What is the total? 

(Hint: Peel digits with % 10, keep adding.)*/

# include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main () {
    int n, count=0, peel = 0, sumf;
    printf("Enter Number: ");
    scanf("%d", &n);
    int x = n;
    while (x!=0) {
        peel = x%10;
        count++;
        x /= 10;
    }

    peel = 0;
    
    int arr[count];

    while (n!= 0) {
        peel = n % 10;
        sumf += peel;
        n /= 10;
        }

    printf("Sum of Digits is: %d", sumf);
    return 0;
}