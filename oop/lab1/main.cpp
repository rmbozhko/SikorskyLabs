#include <cmath>
#include <iostream>
#include <cstdlib>
#include <cfloat>
#include <random>
#include <algorithm>

#define TRANSFORMATION_CONST -10

void drawRow(double a, double b);
void drawRow(const char *a, const char *b);
void drawRow(double a);

void drawHeaderRow(int column_number);
void drawFooterRow(int column_number);
void drawRawFloor(int column_number);

int transformFunction(double, double);

class FuncParams {
private:
    int a;
    int b;
    double dx;
    double x1;
    double x2;
    double *values;

public:
    FuncParams() = default;

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

    int getA() const { return a; }

    int getB() const { return b; }

    double getDX() const { return dx; }

    double getX1() const { return x1; }

    double getX2() const { return x2; }

    double getValue(int i) { return values[i]; }

    void setA(int a_) { this->a = a_; }

    void setB(int b_) { this->b = b_; }

    void setDX(double dx_) { this->dx = dx_; }

    void setX1(double x1_) { this->x1 = x1_; }

    void setX2(double x2_) { this->x2 = x2_; }

    int getFuncArrayLength() {
        int length;
        if ((x2 < 0 && x1 < 0) || (x2 > 0 && x1 > 0))  {
            length = (x2 < x1) ? x1 - x2 : x2 - x1;
        } else if (x2 < 0 && x1 > 0) {
            length = x1 - x2;
        } else if (x2 > 0 && x1 < 0) {
            length = x2 - x1;
        } else {
            length = fabs(x2 - x1);
        }
        return ((++length) / dx) - 2;
    }

    void funcValues() {
        int i = 0;
        int length = getFuncArrayLength();
        double *values = new double[length];
        for (double x = x1; x <= x2; x += dx, i++) {
            values[i] = func(x);
            drawRow(x, values[i]);
            if (i < length) drawRawFloor(2);
        }
        drawFooterRow(2);
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

    double *getValues() {
        return values;
    }
};

FuncParams *ReadPar() {
    auto *params = new FuncParams();
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

void printNTimes(const std::string& str, size_t times) {
    for (int i = 0; i < times; i++) {
        std::cout << str;
    }
}

void Tab(FuncParams *params) {
    drawHeaderRow(2);
    drawRow("x", "f(x)");
    drawRawFloor(2);
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

    std::cout << std::endl;
    drawHeaderRow(1);
    drawRow(s1);
    drawRawFloor(1);
    drawRow(s2);
    drawRawFloor(1);

    std::mt19937 gen(time(0));
    std::uniform_real_distribution<> urd(sMin, sMax);

    rnd[0] = urd(gen);
    for (int i = 1; i < size; i++) {
        urd = std::uniform_real_distribution<>(rnd[i - 1] + step, sMax);
        rnd[i] = urd(gen);
        drawRow(rnd[i]);
        if (i + 1 == size) {
            drawFooterRow(1);
        } else {
            drawRawFloor(1);
        }
    }
    return rnd;
}

void drawFooterRow(int column_number) {
    if (column_number == 1) {
        std::string box_horizontal_line = "\u2550";
        std::cout << "\u255A";
        printNTimes(box_horizontal_line, 5);
        std::cout << "\u255D" << std::endl;
    } else {
        std::string box_horizontal_line = "\u2550";
        std::cout << "\u255A";
        printNTimes(box_horizontal_line, 6);
        std::cout << "\u2569";
        printNTimes(box_horizontal_line, 7);
        std::cout << "\u255D" << std::endl;
    }
}

void drawHeaderRow(int column_number) {
    if (column_number == 1) {
        std::cout << "\u2554";
        std::string box_horizontal_line = "\u2550";
        printNTimes(box_horizontal_line, 5);
        std::cout << "\u2557" << std::endl;
    } else {
        std::cout << "\u2554";
        std::string box_horizontal_line = "\u2550";
        printNTimes(box_horizontal_line, 6);
        std::cout << "\u2566";
        printNTimes(box_horizontal_line, 7);
        std::cout << "\u2557" << std::endl;
    }
}

void Print(FuncParams *params) {
    std::cout << "\n\n\nY\n^" << std::endl;
    int size = params->getFuncArrayLength();
    int max = 0;
    double *min = std::max_element(params->getValues(), params->getValues() + params->getFuncArrayLength());
    for (int i = 0; i < size; i++) {

        int spaces_len = transformFunction(params->getValue(i), *min);
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

int transformFunction(double value, double minValue) {
    return (int) ((value - minValue) * (TRANSFORMATION_CONST));
}

void drawRow(double a, double b) {
    std::cout << "\u2551";
    printf("%5.3f", a);
    std::cout << "\u2551";
    printf("%5.4f", b);
    std::cout << "\u2551" << std::endl;
}

void drawRow(const char *a, const char *b) {
    std::cout << "\u2502";
    printf("%4s%2s", a, "");
    std::cout << "\u2502";
    printf("%6s%1s", b, "");
    std::cout << "\u2502" << std::endl;
}

void drawRow(double a) {
    std::cout << "\u2551";
    printf("%5.2f", a);
    std::cout << "\u2551" << std::endl;
}

void drawRawFloor(int column_number) {
    if (column_number == 1) {
        std::cout << "\u2560";
        std::string box_horizontal_line = "\u2550";
        printNTimes(box_horizontal_line, 5);
        std::cout << "\u2563" << std::endl;
    } else {
        std::cout << "\u2560";
        std::string box_horizontal_line = "\u2550";
        printNTimes(box_horizontal_line, 6);
        std::cout << "\u256C";
        printNTimes(box_horizontal_line, 7);
        std::cout << "\u2563" << std::endl;
    }
}

int main() {
    try {
        auto *params = new FuncParams(1, 5, 0.0792, -2, -0.1);

        FuncParams* test = ReadPar();
        Tab(params);
        rand(params);
        Print(params);
    } catch (char const *error) {
        std::cerr << "Помилка: " << error << std::endl;
    }
    return (0);
}