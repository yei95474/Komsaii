#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int size;
    printf("Enter size: ");
    scanf("%d", &size);
    int arr[size];

    printf("Select Values:\n");
    for (int i=0;i<size;i++) {
        scanf("%d", &arr[i]);
    }
    printf("Your numbers are: ");
    for (int i=0;i<size;i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    for (int i=0;i<size;i++) {
        if (arr[i]<0) {
            arr[i] = 0;
        }
    }

    printf("Your numbers are now: ");
    for (int i=0;i<size;i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
