
/*Given an array of n length. Calculate its mean (average).*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double n;
    double mean;
    int size;
    printf("Enter size\n");
    scanf("%d", &size);
    double arr[size];

    printf("Enter Values:\n");
    for (int i=0; i<size; i++) {
        scanf("%lf", &arr[i]);
        n = n + arr[i];
    }

    mean= n/(double)size;
    printf("%.2lf", mean);


return 0;
}

