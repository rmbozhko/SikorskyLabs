#include <cmath>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <float.h>

void drawRow(double a, double b);
void drawRow(const char *a, const char *b);
void drawRow(double a);

class FuncParams {
private:
    int a;
    int b;
    double dx;
    double x1;
    double x2;
    double *values;

public:
    FuncParams() {}

    FuncParams(int a, int b, double dx, double x1, double x2) {
        if ((dx < DBL_MAX && dx > -DBL_MAX) &&
            (x1 < DBL_MAX && x1 > -DBL_MAX) &&
            (x2 < DBL_MAX && x2 > -DBL_MAX) &&
            ((x1 < x2 && dx > 0) ||
             (x1 > x2 && dx < 0))) {
            this->a = a;
            this->b = b;
            this->dx = dx;
            this->x1 = (x1 < x2) ? x1 : x2;
            this->x2 = (x1 < x2) ? x2 : x1;
        } else {
            throw "Невірні параметри\n";
        }
    }

    int getA() { return a; }

    int getB() { return b; }

    double getDX() { return dx; }

    double getX1() { return x1; }

    double getX2() { return x2; }

    double getValue(int i) { return values[i]; }

    void setA(int a) { this->a = a; }

    void setB(int b) { this->b = b; }

    void setDX(double dx) { this->dx = dx; }

    void setX1(double x1) { this->x1 = x1; }

    void setX2(double x2) { this->x2 = x2; }

    int getFuncArrayLength() { return round(fabs(fabs(x2) - fabs(x1)) / dx); }

    void funcValues() {
        int i = 0;
        double *values = new double[getFuncArrayLength()];
        for (double x = x1; x <= x2; x += dx, i++) {
            values[i] = func(x);
            drawRow(x, values[i]);
        }
        this->values = values;
    }

    double func(double arg) {
        if (arg <= -0.7) {
            return (-this->a) * pow(arg, 2.0);
        }
        return (this->a - arg) / (this->b * arg);
    }

    double findMinElemWithStep(int step, double min) {
        int size = this->getFuncArrayLength();
        for (int i = step - 1; i < size; i += step) {
            if (this->values[i] < min) {
                min = this->values[i];
            }
        }
        return min;
    }
};

FuncParams *ReadPar() {
    FuncParams *params = new FuncParams();
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

void printNTimes(std::string str, size_t times) {
    for (int i = 0; i < times; i++) {
        std::cout << str;
    }
}

void Tab(FuncParams *params) {
    drawRow("x", "f(x)");
    params->funcValues();
}


double *rand(FuncParams *params) {
    int size = params->getFuncArrayLength();
    double s1 = params->findMinElemWithStep(2, params->getValue(1));
    double s2 = params->findMinElemWithStep(1, params->getValue(0));
    auto *rnd = new double[size];
    double sMax = (s1 > s2) ? s1 : s2;
    double sMin = (s1 < s2) ? s1 : s2;
    double delta = 0.03;
    double step = delta * ((sMax + sMin) / 2);

    printf("\n");
    drawRow(s1);
    drawRow(s2);
    rnd[0] = (rand() % (int) sMax) + sMin;
    for (int i = 1; i < size; i++) {
        rnd[i] = (rand() % (int) sMax) + rnd[i - 1] + step;
        drawRow(rnd[i]);
    }
    return rnd;
}

void Print(FuncParams *params) {
    std::cout << "\n\n\nY\n^" << std::endl;
    int size = params->getFuncArrayLength();
    int max = 0;
    for (int i = 0; i < size; i++) {
        int spaces_len = (int) (params->getValue(i) * (-10));
        if (spaces_len > max) {
            max = spaces_len;
        }
        std::cout << "|";
        while (spaces_len--) {
            std::cout << " ";
        }
        std::cout << "*" << std::endl;
    }
    while (max--) {
        std::cout << "-";
    }
    std::cout << "> X" << std::endl;
}

void drawRow(double a, double b) {
    std::cout << "\u2554";
    std::string box_horizontal_line = "\u2550";
    printNTimes(box_horizontal_line, 6);
    std::cout << "\u2566";
    printNTimes(box_horizontal_line, 7);
    std::cout << "\u2557" << std::endl;

    std::cout << "\u2551";
    printf("%5.3f", a);
    std::cout << "\u2551";
    printf("%5.4f", b);
    std::cout << "\u2551" << std::endl;

    std::cout << "\u255A";
    printNTimes(box_horizontal_line, 6);
    std::cout << "\u2569";
    printNTimes(box_horizontal_line, 7);
    std::cout << "\u255D" << std::endl;
}

void drawRow(const char *a, const char *b) {
    std::cout << "\u2554";
    std::string box_horizontal_line = "\u2550";
    printNTimes(box_horizontal_line, 6);
    std::cout << "\u2566";
    printNTimes(box_horizontal_line, 7);
    std::cout << "\u2557" << std::endl;

    std::cout << "\u2551";
    printf("%4s%2s", a, "");
    std::cout << "\u2551";
    printf("%6s%1s", b, "");
    std::cout << "\u2551" << std::endl;

    std::cout << "\u255A";
    printNTimes(box_horizontal_line, 6);
    std::cout << "\u2569";
    printNTimes(box_horizontal_line, 7);
    std::cout << "\u255D" << std::endl;
}

void drawRow(double a) {
    std::cout << "\u2554";
    std::string box_horizontal_line = "\u2550";
    printNTimes(box_horizontal_line, 5);
    std::cout << "\u2557" << std::endl;

    std::cout << "\u2551";
    printf("%5.2f", a);
    std::cout << "\u2551" << std::endl;

    std::cout << "\u255A";
    printNTimes(box_horizontal_line, 5);
    std::cout << "\u255D" << std::endl;

}

int main(void) {
    try {
        FuncParams *params = new FuncParams(1, 5, 0.0792, -2, -0.1);

        FuncParams* test = ReadPar();
        Tab(params);
        rand(params);
        Print(params);
    } catch (char const *error) {
        std::cerr << "Помилка: " << error << std::endl;
    }
    return (0);
}