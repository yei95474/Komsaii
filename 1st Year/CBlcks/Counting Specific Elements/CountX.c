#include <stdio.h>
#include <stdlib.h>
#include <math.h>  
//Count X occurences
int main() {

    int size, x, count = 0;
    printf("Enter Size: ");
    scanf("%d", &size);
    int arr[size];

    printf("\nEnter Values: \n");
    for (int i=0; i<size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Your Numbers are: ");
    for (int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nEnter X: ");
    scanf("%d", &x);
    for (int i=0;i<size;i++){ 
        if (arr[i]==x){
            count++;
        }
    }

    printf("Occurences: %d", count);
    return 0;
    
}