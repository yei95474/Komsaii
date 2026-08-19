#include <stdio.h>

int main() {
    int n,c=0;
    printf("Enter n (4-digits): ");
    scanf("%d", &n);
   
   do {
    int temp=n, size=0, a=0, d=0;
    c++;
    printf("\nStep [%d]\n", c);
    while (temp>0) {
        temp/=10;
        size++;
    }
    int asc[size];
    
    int ti=size-1,tn=n;
    while (tn>0) {
        temp=tn%10;
        asc[ti]=temp;
        tn/=10;
        ti--;
    }
    
    if(size!=4) {
        printf("4-digit only");
        return 1;
    }
    for (int i=0; i<size; i++) {
        int min=9999999, mi;
        for (int j=i; j<size; j++) {
            if (asc[j]<min) {
                min=asc[j];
                mi=j;
            }
        }
        temp=asc[i];
        asc[i]=min;
        asc[mi]=temp;
    }
    
    ti=0;
    while(ti<=size-1) {
        a=a*10+asc[ti];
        ti++;
    }
    
    ti=size-1;
    while(ti>=0) {
        d=d*10+asc[ti];
        ti--;
    }
    
    n=d-a;
    printf("%d - %d = %d\n", d, a, n);
   } while (n!=6174 && n!=0);
   
    if (n==6174) {
        printf("\n4-Digit Kaprekar Constant is achieved in %d steps", c);
    }
    else if (n==0){
        printf("Invalid");
    }
    
    return 0;
}