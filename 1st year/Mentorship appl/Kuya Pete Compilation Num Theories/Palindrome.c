#include <stdio.h>
#include <math.h>

int main() {
    int n, rev=0;
    printf("Enter n: ");
    scanf("%d", &n);
    
    int tn=n;
    
    tn=n;
    while (tn>0) {
        int temp=tn%10;
        rev=rev*10+temp;
        tn/=10;
    }
    
    if(n==rev) {
        printf("Palindrome");
    }
    else {
        printf("Not a Palindrome");
    }
    return 0;
}