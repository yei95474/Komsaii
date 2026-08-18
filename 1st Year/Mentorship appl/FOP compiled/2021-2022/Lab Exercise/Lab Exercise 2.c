#include <stdio.h>
#include <math.h>

int main() { 
    //Problem 1
    float x, p_in;
    printf("Enter x: ");
    scanf("%f", &x);
    p_in=29.29*exp(-0.2*x);
    float p_mm=p_in*25.44;
    printf("p_in= %.4f\n", p_in);
    printf("p_mm= %.4f\n", p_mm); 
    
    //problem 2
    float t, I;
    printf("Enter t: ");
    scanf("%f", &t);
    I=-0.2*pow(t, 3) + 3*pow(t,2) + 100;
    printf("I= %.4f", I); 
    
    //prob 3
    int totalSeconds;
    int hours, minutes, seconds;
    printf("Enter time in seconds: ");
    scanf("%d", &totalSeconds);

    hours = totalSeconds / 3600;
    minutes = (totalSeconds % 3600) / 60;
    seconds = totalSeconds % 60;

    printf("%d second(s) = %d hour(s), %d minute(s), %d second(s)\n",totalSeconds, hours, minutes, seconds);

    return 0; 
}