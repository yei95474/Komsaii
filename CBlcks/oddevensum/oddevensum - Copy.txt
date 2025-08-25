#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size, n = 2, odd=0, even=0,r;
    printf("Enter size\n");
    scanf("%d", &size);
    int arr[size];
    printf("Enter Values:\n");

    for (int i=0;i<size;i++) {
        scanf("%d", &arr[i]);
    }
    printf("Your Numbers are: ");
    for (int i=0;i<size;i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    for (int i=0;i<size;i++) {
            r=arr[i]%n;
        if (r==0) {
            even = even+arr[i];
        }
        else {
            odd = odd+arr[i];
        }
    }
    printf("Sum of:\nEven=%d\nOdd=%d", even, odd);
return 0;
}
