from nonlinmeth.bisection import bisection
from nonlinmeth.secant import secant
from nonlinmeth.newton import newton


def print_result(func, x1, x2, iteration_num_x1, iteration_num_x2):
    print(f"\tЗначення знайдених коренів: x1 = {x1} за {iteration_num_x1} ітер., x2 = {x2} за {iteration_num_x2} ітер.")
    print(f"\tЗначення функції з цими значеннями: f(x1) = {func(x1)}, f(x2) = {func(x2)}")


def main():
    func = lambda x: (x ** 4) - 3 * (x ** 3) + (x ** 2) - 2 * x - 4
    iteration_num_x1, bisection_x1 = bisection(func, -1, 0)
    iteration_num_x2, bisection_x2 = bisection(func, 3, 4)
    print("Метод бісекції")
    print_result(func, bisection_x1, bisection_x2, iteration_num_x1, iteration_num_x2)

    iteration_num_x1, secant_x1 = secant(func, -1, 0)
    iteration_num_x2, secant_x2 = secant(func, 3, 4)
    print("Метод хорд")
    print_result(func, secant_x1, secant_x2, iteration_num_x1, iteration_num_x2)

    iteration_num_x1, newton_x1 = newton(func, -1)
    iteration_num_x2, newton_x2 = newton(func, 3)
    print("Метод дотичних")
    print_result(func, newton_x1, newton_x2, iteration_num_x1, iteration_num_x2)


if __name__ == '__main__':
    main()
