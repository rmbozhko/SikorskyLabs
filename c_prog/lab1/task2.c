#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(const int argc, const char* argv[]) {

 double  var_y;
 double  param_a;
 double  param_b;
 double  var_x;
 double  temp;
 
 printf("Роман Божко ТР-02, що робить прога\n");
 if (argc == 4) {
   // If passed value more than can be stored in memory cell -> Undefined behavior
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

 temp = param_a + var_x;
 if (temp <= 0) {
    printf("The argument passed to lg function is less then zero or equals to it.\n");
    return 1;
  }
  temp = param_a * var_x * temp;
  if (temp < 0) {
    printf("The argument passed to sqrt function is less then zero.\n");
    return 1;
  }
  var_y = param_b * param_a * sqrt(temp) + exp(param_a * var_x);
   
  printf("|Value of y|\n|%10lf|\n", var_y);

 return 0;
}