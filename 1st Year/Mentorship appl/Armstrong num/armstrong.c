#include <stdio.h>
#include <math.h>

int main () {
int num = 153;
 int original = num;
 int sum = 0;
 int digits = 0;
 int temp = num;

 // Count number of digits
 while (temp>0) {
 digits++;
 temp =temp/10;
 }

 temp = num;
 while (temp>0) {
 int digit =pow((temp%10),digits);
 sum += digit;
 temp = temp/10;
 }

 if (sum==num) {
 printf("%d is an Armstrong number", original);
 } else {
 printf("%d is not an Armstrong number", original);
 }
 }
