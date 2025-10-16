#include <stdio.h>

int main() {
    long long int SumOfSquares=0, SquareOfSum=0;
    for(int i=1; i<=100; i++) {
        SumOfSquares+=(i*i);
    }
    for(int i=1; i<=100; i++) {
        SquareOfSum+=i;
    }
    
    SquareOfSum*=SquareOfSum;

    printf("%lld", SquareOfSum-SumOfSquares);
    

    return 0;
}