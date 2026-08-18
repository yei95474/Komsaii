#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int size;
    printf("Enter size\n");
    scanf("%d", &size);
    int arr[size];
    printf("Enter Values:\n");

    for (int i=0; i<size; i++){
        scanf("%d", &arr[i]);
    }

    printf("Your numbers are: ");
    for (int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    int pos = 0, neg = 0, zero = 0;

    for (int i=0; i<size; i++) {
        if (arr[i]>0) {
            pos = pos + 1;
        }
        if (arr[i]<0) {
            neg = neg+1;
        }
        if (arr[i]==0) {
            zero=zero+1;
        }
    }

    printf("Positive=%d\nNegative=%d\nZero=%d", pos, neg, zero);

return 0;
}
