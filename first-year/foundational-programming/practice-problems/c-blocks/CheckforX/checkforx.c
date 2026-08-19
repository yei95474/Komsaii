#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int size, x, count=0;
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
    
    printf("Enter X: ");
    scanf("%d", &x);
    
    for(int i=0; i<size; i++) {
    }

    for(int i=0; i<size; i++) {
        if (x==arr[i]) {
            count += 1 ;
        }
    }
    if (count>=1) {
        printf("YES");
    }
    else {
        printf("NO");
    }
    
    
    return 0;
}