#include <stdio.h>
#include <math.h>

int main(const int argc, const char* argv[]) {

 double  var_y;
 float   var_x;
 const float  power_val = 3.0;
 
 printf("Роман Божко ТР-02, програма виводить значення функції у вигяді таблиці, якщо x змінюється на інтервалі [-1; +1] з кроком 0.1\n");
 var_y = 0.0;
 var_x = -1;
 printf("|Value of y|Value of x|\n");
 while (var_x <= 1.1)
 {
   var_y = exp((-1) * pow((var_x - 0.5), power_val));
   printf("|%10lf|%10lf|\n", var_y, var_x);
   var_x += 0.1;
 }
 return 0;
}