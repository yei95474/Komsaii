#include <stdio.h>

int main() {
    int rev, num=998001;
    while (1) {
         rev=0;
        int t=num;
        while(t>0) {
            int temp=t%10;
            rev= rev*10+temp;
            t/=10;
        }
        
        if (rev == num) {
            break;
        }
        num--;
        continue;
    }
    printf("%d == %d\n", rev, num);
    
    int x=999, y=999, flag=0;
    
    while(x>=100) {
        y=999;
        while(y>=100){
            if(x*y!=num){
                 y--;
                continue;
            }
            flag=1;
            break;
           
        }
        if(flag==1) {
            break;
        }
        x--;
    }
    if(x*y!=num){
        printf("No factosr");
    }
    

    return 0;
}