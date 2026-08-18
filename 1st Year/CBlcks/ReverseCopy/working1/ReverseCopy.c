#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

int main() {

    int size, temp=0;
    printf("Enter Size: ");
    scanf("%d", &size);
    int arr[size];

    printf("Enter Values: \n");
    for (int i=0; i<size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Your Numbers are: ");
    for (int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }

    for (int i=0, j=size-1; i<=j; i++, j--) {
        temp = arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
    printf("\nReversed Copy: ");
    for (int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}