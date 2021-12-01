import numpy as np
from sklearn.metrics import mean_squared_error
from prettytable import PrettyTable

ITERATION_LIMIT = 100
A = np.array([
        [5.68, 1.12, 0.95, 1.32, 0.83],
        [0, -20.21600, -10.9776, -1.7592, -4.2392],
        [0, -10.9776, -36.7559, -6.0732, -8.1291],
        [0, -1.7592, -6.0732, -21.3752, -6.0044],
        [0, -4.2392, -8.1291, -6.0044, -31.7439]])
b = np.array([6.89, -10.516, -13.788, -26.405, -26.373])
m = 6
computational_error = 1e-8
#A_initial = np.array([[5.68, 1.12, 0.95, 1.32, 0.83], [1.12, 3.78, 2.12, 0.57, 0.91], [0.95, 2.12, 6.63, 1.29, 1.57], [1.32, 0.57, 1.29, 4.07, 1.25], [0.83, 0.91, 1.57, 1.25, 5.71]])
#b_initial = np.array([6.89, 3.21, 3.58, 6.25, 5.65])


def generate_table(title, field_names, rows):
    table = PrettyTable()
    table.title = title
    for column in field_names:
        table.float_format[column] = "." + str(m)
    table.field_names = field_names
    table.add_rows(rows)
    return table


def print_results(results_table_rows, residual_vector_row, x):
    np.set_printoptions(precision=m)
    subscripts = str.maketrans("0123456789", "₀₁₂₃₄₅₆₇₈₉")
    table_head = ["x{}".format(i).translate(subscripts) for i in range(1, A.shape[0] + 1)]
    table_head.insert(0, "Номер ітерації")
    results_table = generate_table("Корені системи", table_head, results_table_rows)
    residual_table = generate_table("Вектори нев\'язки", table_head, residual_vector_row)
    print(results_table)
    print(residual_table)
    print("Корені рівнянь: {0}".format(x))
    print("Вектор нев\'язки: {0}".format(b - A.dot(x)))
    mse = mean_squared_error(x, np.linalg.solve(A, b))
    print("Середньоквадратична похибка: {0}".format(mse))
