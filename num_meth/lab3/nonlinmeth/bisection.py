def bisection(f, a, b, tol=1e-20, iterations_num=100):
    f_a = f(a)
    if abs(f_a) < tol:
        return a

    f_b = f(b)
    if abs(f_b) < tol:
        return b

    c = None
    iteration = None
    for iteration in range(iterations_num):
        c = (a + b) / 2
        f_c = f(c)

        if (b - a) < tol:
            break
        if abs(f_c) < tol:
            break
        elif f_a * f_c > 0:
            a, f_a = c, f_c
        elif f_b * f_c > 0:
            b, f_b = c, f_c

    return iteration, c
