#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(const int argc, const char* argv[]) {

  int   choice_id;

  printf("Please, type the number of equation to be computed: ");
  scanf("%d", &choice_id);

  if (choice_id == 0) {
    double  var_y;
    double  param_a;
    double  param_b;
    double  var_x;
    double  temp;

    printf("Роман Божко ТР-02, програма виводить значення кусково-заданої функції\n");

    printf("Enter a parameter A: ");
    scanf("%lf", &param_a);
    printf("Enter a parameter B: ");
    scanf("%lf", &param_b);
    printf("Enter a value for variable X: ");
    scanf("%lf", &var_x);


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
  } else if (choice_id == 1) {
    double  var_y;
    double  param_a;
    double  param_b;
    double  var_x;
    double  temp;

    printf("Роман Божко ТР-02, програма виводить результат функції у вигляді таблиці\n");

    printf("Enter a parameter A: ");
    scanf("%lf", &param_a);
    printf("Enter a parameter B: ");
    scanf("%lf", &param_b);
    printf("Enter a value for variable X: ");
    scanf("%lf", &var_x);

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
  } else if (choice_id == 2) {
    double  var_y;
    float   var_x;
    const float  power_val = 3.0;
    
    printf("Роман Божко ТР-02, програма виводить значення функції у вигяді таблиці, якщо x змінюється на інтервалі [-1; +1] з кроком 0.1\n");
    var_y = 0.0;
    var_x = -1;
    printf("|Value of y|Value of x|\n");
    while (var_x <= 1.1) {
      var_y = exp((-1) * pow((var_x - 0.5), power_val));
      printf("|%10lf|%10lf|\n", var_y, var_x);
      var_x += 0.1;
    }
  }
  
  return 0;
}