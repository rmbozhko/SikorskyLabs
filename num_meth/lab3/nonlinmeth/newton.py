def derivative(f, x, dx=1e-6):
    df = f(x + dx) - f(x - dx)
    df /= (2 * dx)
    return df


def newton(f, x_0, tol=1e-20, iterations_num=100):
    x = x_0
    f_x = f(x)

    iteration = None
    for iteration in range(iterations_num):
        if abs(f_x) < tol:
            break
        func_derivative = derivative(f, x)
        if abs(func_derivative) < tol:
            break
        x = x - (f_x / func_derivative)
        f_x = f(x)

    return iteration, x
