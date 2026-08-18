#include <stdio.h>

int main () 
{
    int size, n, ctr, temp=0, o=0, flag;

    do
    {
    printf("Enter Size: ");
    scanf("%d", &size);
    if (size>10)
        printf("Can support 10 problems only\n");
    } while (size>10);

    while (size>0) 
    {
        printf("Enter Value/s: ");
        scanf("%d", &n);
        int nc=n, c=0;
        flag=0;
    
    
        while (nc>0)
        {                //check if the input is 3 digits
            nc/=10;
            c++;
        }

        if (c!=3 && nc!=000 && nc!=010 && nc!=011) 
        {
            printf("3 digits only\n");
            continue;
        }
        

        
        ctr=0;
        while (n>0)
        {
            temp=n%10;
            n/=10;
            if (temp==1 || temp==0) 
            {
                if (temp==1)
                {
                ctr++;
                }
            }
            else
            {
                printf("1/0 only\n");
                flag=1;
                break;

            }
        }
        if (flag) 
        {
            continue;
        }

        if (ctr>=2) 
        {
            o++;
        }
        size--;
    }
    printf("%d", o);
    return 0;
}