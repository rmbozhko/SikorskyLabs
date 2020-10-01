#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(const int argc, const char* argv[]) {

 double  var_y;
 double  param_a;
 double  param_b;
 double  var_x;
 double  temp;
 
 printf("Роман Божко ТР-02, програма виводить значення кусково-заданої функції\n");
 if (argc == 4) {
   param_a = atof(argv[1]);
   param_b = atof(argv[2]);
   var_x = atof(argv[3]); 
 }
 else {
   printf("Enter a parameter A: ");
   scanf("%lf", &param_a);
   printf("Enter a parameter B: ");
   scanf("%lf", &param_b);
   printf("Enter a value for variable X: ");
   scanf("%lf", &var_x);
 }
 
 if (var_x < 3) {
   var_y = param_a * var_x;
 } else if (var_x == 3) {
   var_y = exp(2 * var_x);
 } else if (var_x > 3) {
   temp = param_a * param_b * var_x;
   if (temp <= 0) {
     printf("The argument passed to lg function is less then zero.");
     return 1;
   }
   var_y = log(temp);
 }
 printf("Value of y: %lf\n", var_y);

 return 0;
}