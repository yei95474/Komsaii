#include <stdio.h>
int main () {
    int p1, p2, c=0, f1=0, f2=0;
    printf("Enter p1: ");
    scanf("%d", &p1);
    //check if p1 is prime
    
    for (int i=1;i<=p1;i++) {
        if (p1%i==0) {
            c++;
        }
        if (c>2 || p1==1) {
        printf("Not Prime!\n");
        f1++;
        break;
    }
    }
    
    //get p2
    p2=p1+2;
    printf("p2= p1+2: %d\n", p2);
    //check if p2 is prime & set c to 0
    c=0;
    for (int i=1;i<=p2;i++) {
        if (p2%i==0) {
            c++;
        }
        if (c>2) {
        printf("Not Prime!\n");
        f2++;
        break;
    }
    }
    
    if (f1==0&&f2==0) {
        printf("\n%d and %d is a twin prime", p1, p2);
    }
    else {
        printf("\n%d and %d is not a twin prime", p1, p2);
    }
    return 0;
}