#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int size;
    printf("Enter size\n");
    scanf("%d", &size);
    int arr[size];
    int first, last;
    printf("Enter Values:\n");

    for (int i=0; i<size; i++){
        scanf("%d", &arr[i]);
    }

    printf("Your numbers are: ");
    for (int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
    printf("before swap\n");

    int temp;

    temp = arr[0];
    arr[0] = arr[size-1];
    arr[size-1] = temp;

    printf("After Swap: ");
    for (int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
return 0;
}


