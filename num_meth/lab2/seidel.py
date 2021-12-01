import itertools
from util import *


def main():
    results_table_rows = []
    residual_vector_table_rows = []
    x = np.zeros(b.shape[0])

    for iteration in range(1, ITERATION_LIMIT):
        # keeping data for table output
        results_row = [[iteration], x.tolist()]
        results_table_rows.append(list(itertools.chain(*results_row)))
        residual_vector_row = [[iteration], b - A.dot(x)]
        residual_vector_table_rows.append(list(itertools.chain(*residual_vector_row)))

        temp = np.zeros(x.shape[0])
        for i in range(A.shape[0]):
            temp[i] = (b[i] - np.dot(A[i, :i], temp[:i]) - np.dot(A[i, i + 1:], x[i + 1:])) / A[i, i]
        if np.allclose(x, temp, rtol=computational_error):
            break
        x = temp
    print_results(results_table_rows, residual_vector_table_rows, x)


if __name__ == '__main__':
    main()
