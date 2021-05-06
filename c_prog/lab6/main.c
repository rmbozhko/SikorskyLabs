#include <stdio.h>
#include <math.h>

#define PRECISION 0.0001

unsigned int   num_len(long int temp) {
  unsigned int  width;

  width = 0;
  while (temp != 0) {
    temp /= 10;
    width++;
  }
  return (width);
}

double tg(double x) {
  long double sin=x, cos=1, tan=0, a=1;
	int n=1;
	while (fabs((sin/cos) - tan) > PRECISION) {
		tan = sin/cos;
		a *= -x * x / (double)((2*n - 1) * (2*n));
		cos += a;
		sin += a * x / (double)(2*n + 1);
		n++;
	}
	tan = sin/cos;
	return tan;
}
 
int main(void)
{
    double        x;

    printf("Enter tg function argument value in angles (-90, 90): ");
    scanf("%lf", &x);
    x /= 180;
    x *= M_PI;
    printf("Entered value in radians: %lf\n", x);

    if (x > -(M_PI_2) && x < (M_PI_2)) {
      unsigned int  width;

      width = num_len(tan(x) * 100000);
      printf("|%*s|%*s|\n%.5f|%.5f\n", width, "tg(x)", width, "tan(x)", tg(x), tan(x));
    } else return (1);
    return (0);
}