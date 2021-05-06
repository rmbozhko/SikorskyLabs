#include <stdlib.h>
#include <stdio.h>

#define SIZE 8

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

void pop(int** arr, const int index) {
	if (index >= 0 && index < SIZE) {
		shift_elements(arr, index);
	}
}

void pop_start(int** arr) {
	shift_elements(arr, 0);
}

int print_arr(int** arr, const int len, FILE* fptr) {
  int   write_code;

	for (int i = 0; i < len; ++i) {
		fprintf(fptr, "|%2d|", *arr[i]);
	}
	write_code = fprintf(fptr, "\n");
}

int print_bidarr(int** arr, const int len, FILE* fptr) {
  int   write_code;

	for (int i = 0; i < len; ++i) {
		for (int j = 0; j < SIZE; ++j) {
    		write_code = fprintf(fptr, "|%2d|", arr[i][j]);
    	}
    write_code = fprintf(fptr, "\n");
	}
}


int main(int argc, char const *argv[])
{
  
	int**		arr;
	FILE*		fptr;

	fptr = fopen("data.txt", "a");
	arr = (int**)malloc(sizeof(int*) * SIZE);
	for (int i = 0; i < SIZE; ++i) {
    arr[i] = (int*)malloc(sizeof(int));
		*arr[i] = rand() % 50;
	}
	print_arr(arr, SIZE, fptr);

	const int index = find_odd(arr);
	pop(arr, index);
  
	if (index != -1) {
		print_arr(arr, SIZE - 1, fptr);
	} else {
		print_arr(arr, SIZE, fptr);
	}

	int**		bid_arr;

	bid_arr = (int**)malloc(sizeof(int*) * SIZE);
	for (int i = 0; i < SIZE; ++i) {
    	bid_arr[i] = (int*)malloc(sizeof(int) * SIZE);
    	for (int j = 0; j < SIZE; ++j) {
    		bid_arr[i][j] = rand() % 50;
    	}
	}
	print_bidarr(bid_arr, SIZE, fptr);
	pop_start(bid_arr);
  print_bidarr(bid_arr, SIZE - 5, fptr);
	fclose(fptr);
	return 0;
}