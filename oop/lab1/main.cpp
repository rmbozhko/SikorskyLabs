#include <cmath>
#include <iostream>

class FuncParams {
  private:
    int a;
    int b;
    double dx;
    double x1;
    double x2;
    double* values;

  public:
    FuncParams() {}
    FuncParams(int a, int b, double dx, double x1, double x2) {
      if ((x1 < x2 && dx > 0) || 
          (x1 > x2 && dx < 0)) {
            this->a = a;
            this->b = b;
            this->dx = dx;
            this->x1 = (x1 < x2) ? x1 : x2;
            this->x2 = (x1 < x2) ? x2 : x1;
      } else {
        throw "Invalid arguments";
      }
    }

    int getA() { return a; }
    int getB() { return b; }
    double getDX() { return dx; }
    double getX1() { return x1; }
    double getX2() { return x2; }

    int setA(int a) { this->a = a; }
    int setB(int b) { this->b = b; }
    double setDX(double dx) { this->dx = dx; }
    double setX1(double x1) { this->x1 = x1; }
    double setX2(double x2) { this->x2 = x2; }

    int getFuncArrayLength() { return (abs(abs(x2) - abs(x1)) / dx);}

    void funcValues() {
      int i = 0;
      double* values = new double[getFuncArrayLength()];
      for (double x = x1; x <= x2; x += dx, i++) {
        values[i] = func(x);
        std::cout << i << ":" << values[i] << std::endl;
      }
      this->values = values;
    }

    double  func(double arg) {
      if (arg <= -0.7) {
        return -this->a * pow(arg, 2.0);
      }
      return (this->a - arg)/(this->b * arg);
    }

    double  findMinElemWithStep(int step) {
      double min = this->values[0];
      int size = this->getFuncArrayLength();
      
      for (int i = 0; i < size; i += step) {
        if (this->values[i] < min) {
          min = this->values[i];
        }
      }
      return min;
    }
};

FuncParams* ReadPar() {
  FuncParams* params = new FuncParams();
  int int_temp;
  double double_temp;
  std::cout << "Введіть значення параметру a: ";
  scanf("%d", &int_temp);
  params->setA(int_temp);
  std::cout << "Введіть значення параметру b: ";
  scanf("%d", &int_temp);
  params->setB(int_temp);
  std::cout << "Введіть значення параметру dx: ";
  scanf("%lf", &double_temp);
  params->setDX(double_temp);
  std::cout << "Введіть значення параметру x1: ";
  scanf("%lf", &double_temp);
  params->setX1(double_temp);
  std::cout << "Введіть значення параметру x2: ";
  scanf("%lf", &double_temp);
  params->setX2(double_temp);
  return params;
}

int main(void) {
  FuncParams* params = new FuncParams(1, 5, 0.0792, -2, -0.1);
  params->funcValues();

  //FuncParams* test = new FuncParams(1, 6, 0.2083, 0.5, 5.5);
  //test->funcValues();

  //FuncParams* test = ReadPar();
  //test->funcValues();
  
  std::cout << "S1: " << params->findMinElemWithStep(2) << std::endl;
  std::cout << "S2: " << params->findMinElemWithStep(1) << std::endl;
}