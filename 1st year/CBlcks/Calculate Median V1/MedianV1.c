#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int size, m=0;
    float median;
    printf("Enter Size: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter Values:\n");
    for(int i=0;i<size;i++){
        scanf("%d", &arr[i]);
    }
    printf("Your Numbers are: ");
    for(int i=0;i<size;i++){
        printf("%d ", arr[i]);
    }

    if ((size%2)== 0) {
        m = (((size/2)+((size-1)/2))/2);
        median = (((float)arr[m]+((float)arr[m]+1))/2);
        printf("Median : %.2f" , median);
        
    }
    else if ((size%2)!=0) {
        m = ((size)/2);
        printf("Median : %d" ,arr[m]);
    }
    return 0;
}