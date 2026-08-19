#include <stdio.h>
#include <stdlib.h>

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
    int i=0, j=size;
    first = arr[i];
    last = arr[j];
    arr[0] = first;
    arr[size]= last;

    printf("After swap: ");
    for (int i=0; i<size; i++) {
        printf("%d", arr[i]);
    }
return 0;
}
