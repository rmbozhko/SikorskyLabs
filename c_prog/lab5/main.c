#include <stdlib.h>
#include <stdio.h>
#include <math.h>

# define SIZE 20

void		print_arr(const double* arr) {
	printf("[");
	for (size_t i = 0; i < SIZE; i++) {
		printf("%f", arr[i]);
		(i + 1 < SIZE) ? printf(", ") : printf("]\n");
	}
}

void		init_array(double* arr) {
	size_t		i;

	i = 0;
	for (double x = 1.0; x < 3.1; x += 0.1, i++) {
		arr[i] = x + sin(2 * x);
	}	
}	

void		swap_double(double* a, double* b) {
	double		temp;

	temp = *a;
	*a = *b;
	*b = temp;
}	

void		bubble_sort(double* arr) {
	for (size_t i = 0; i < SIZE - 1; i++) {
		for (size_t j = 0; j < SIZE - i - 1; j++) {
			if (arr[j] < arr[j + 1])
				swap_double(&arr[j], &arr[j + 1]);
		}
	}
}

void		sort(double* arr, void (*f)(double* arr)) {
	f(arr);
}

int		main(void) {
	double		*arr;

	arr = (double*)malloc(sizeof(double) * SIZE);
	init_array(arr);
	printf("Initial array: ");
	print_arr(arr);
	sort(arr, bubble_sort);
	printf("Sorted array: ");
	print_arr(arr);
  free(arr);
	return (0);
}
