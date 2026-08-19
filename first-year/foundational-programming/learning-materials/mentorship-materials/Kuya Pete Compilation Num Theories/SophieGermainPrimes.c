#include <stdio.h>

int main() {
    int p, pc=0;
    //get p
    printf("Enter p: ");
    scanf("%d", &p);
    //check if p is prime
    for(int i=1; i<=p; i++) {
        if (p%i==0) {
            printf("%d ", i);
            pc++;
        }
    }
    
    if (pc>2) {
        printf("\nNot Prime!");
        return 1;
    }
    
    int sp=2*p+1, spc=0;
    printf("\n2p+1 = %d\n", sp);
    
    for(int i=1; i<=sp; i++) {
        if (sp%i==0) {
            printf("%d ", i);
            spc++;
        }
    }
    
    if (spc>2) {
        printf("\nNot Prime!");
        return 1;
    }
    
    printf("\n\n%d is a Sophie Germain Prime (%d)", p, sp);
    
    return 0;
}