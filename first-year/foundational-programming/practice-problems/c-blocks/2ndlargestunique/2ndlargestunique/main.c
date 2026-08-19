
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int size;
    printf("Enter size: ");
    scanf("%d", &size);
    int arr[size];
    int unique[size];
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
        int compare = 0;
        for (int i2=0;i2<size;i2++) {
            compare = arr[i2];
             if (arr[i]== compare) {
                unique[i] = arr[i] && compare;
             }
        }
    }

    for (int i=0;i<size;i++) {
        printf("%d", unique[i]);
    }
    return 0;
}


/*
    int highest= -9999999, lowest=9999999;
    for (int i=0;i<size;i++) {
        if (arr[i]>highest) {
            highest = arr[i];
        }
        if (arr[i]<lowest) {
            lowest=arr[i];
        }
    }
    for (int i=0; i<size; i++) {

    }
*/
