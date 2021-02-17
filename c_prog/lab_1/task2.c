#include <stdlib.h>
#include <stdio.h>

#define SIZE 10

int	find_odd(int** arr) {
	for (int i = 0; i < SIZE; ++i) {
		if (*arr[i] % 2 != 0) {
			return i;
		}
	}
	return -1;
}

void shift_elements(int** arr, const int index) {
	if (index == SIZE - 1) {
		free(arr[index]);
		return ;
	} else {
		*arr[index] = *arr[index + 1];
	}
	shift_elements(arr, index + 1);
}

void pop(int** arr) {
	shift_elements(arr, 0);
}

void print_arr(int** arr, const int len) {
	printf("{ ");
	for (int i = 0; i < len; ++i) {
		for (int j = 0; j < SIZE; ++j) {
    		printf("%d ", *arr[i][j]);
    	}
	}
	printf("}\n");
}

int main(int argc, char const *argv[])
{
  
	int**		arr;

	arr = (int**)malloc(sizeof(int*) * SIZE);
	for (int i = 0; i < SIZE; ++i) {
    	arr[i] = (int*)malloc(sizeof(int) * SIZE);
    	for (int j = 0; j < SIZE; ++j) {
    		*arr[i][j] = rand() % 50;
    	}
	}
  	printf("Initial array: ");
	print_arr(arr, SIZE);

	pop(arr);
  
  	printf("Modified array: ");
	print_arr(arr, SIZE - 5);
	
	return 0;
}