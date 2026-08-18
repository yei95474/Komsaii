#include <stdio.h>

int main () {
    int n,c=0, flag, mc=0,ac=0, xc, x=0;
    char op[4];

    printf("Enter Size: ");
    scanf("%d", &n);

    
    while(n>0)
    {
    /*
        for (int i=0; i<3; i++)
    {
        op[i]=0;
    }
    */

    printf("Enter Operator: ");
    scanf(" %s", op);

    /*
    c=0;
    for (int i=0; op[i] !='\0'; i++)
    {
        c++;
    }
    if (c!=3)
    {
        printf("Invalid size!\n");
        continue;
    }
    */
    ac=0, mc=0, xc=0;
     for (int i=0; i<3 ; i++)
    {
        if (op[i]=='x' || op[i]=='X')
        {
            xc=1;
        }

        if (op[i]=='+')
        {
            ac++;
        }
        else if (op[i]=='-')
        {
            mc++;
        }
    }
    if (xc==0)
    {
        printf("X/x Only!\n");
        continue;
    }
    if (ac==mc)
    {
        printf("++/-- only!\n");
        continue;
    }

    if (ac==2 && xc==1)
    {
        x++;
    }
    else if (mc==2 && xc==1) 
    {
        x--;
    }
    n--;
    }
    printf("x = %d", x);
    return 0;
}