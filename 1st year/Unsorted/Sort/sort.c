#include <stdio.h>
#include <stdlib.h>

int main () {
    int size, count;
    printf("Enter Size: ");
    scanf("%d", &size);
    int arr[size];
    int min;

    printf("Enter Values: ");
    for (int i=0; i<size; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < size; i++) {
        min = arr[i];
        for (int j=1;j<size; j++) {
            if (min>arr[j]) {
                arr[i] = arr[j];
            }
        }
    }
    
    for (int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}