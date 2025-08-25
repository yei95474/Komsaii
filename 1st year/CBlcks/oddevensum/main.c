#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size, n = 2, odd, even, evensum, oddsum;
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
        if ((arr[i]%n)==0) {
            even = arr[i];
            evensum = even + arr[i];
        }
        else if ((arr[i]%n)!=0){
            odd = arr[i];
            oddsum = odd + arr[i];
        }
    }
    printf("Sum of:\nEven=%d\nOdd=%d", evensum, oddsum);
return 0;
}
