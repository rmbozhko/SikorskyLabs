#include <stdlib.h>
#include <stdio.h>

#define SIZE 10

int	find_odd(const int* arr) {
	for (int i = 0; i < SIZE; ++i) {
		if (arr[i] % 2 != 0) {
			return i;
		}
	}
	return -1;
}

void shift_elements(int* arr, const int index) {
	if (index == SIZE - 1) {
		free(arr[index]);
		return ;
	} else {
		arr[index] = index[index + 1]
	}
	shift_elements(arr, index + 1);
}

void pop(int* arr, const int index) {
	if (index >= 0 && index < SIZE) {
		shift_elements(arr, index);
	}
}

void print_arr(int* arr, const int len) {
	printf("{");
	for (int i = 0; i < len; ++i) {
		printf("%d ", arr[i]);
	}
	printf("}\n");
}

int main(int argc, char const *argv[])
{
	int*		arr;

	arr = (int*)malloc(int * SIZE);
	for (int i = 0; i < SIZE; ++i) {
		arr[i] = rand() % 50;
	}

	print_arr(arr, SIZE);

	const int index = find_odd(arr);
	pop(arr, index);

	if (index != -1) {
		print_arr(arr, SIZE - 1);
	} else {
		print_arr(arr, SIZE);
	}
	
	return 0;
}