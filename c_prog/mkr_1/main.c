#include <stdio.h>
#include <stdlib.h>

#define MATRIX_ROW_LEN 2
#define MATRIX_LEN (MATRIX_ROW_LEN * MATRIX_ROW_LEN)
#define INT_MAX_LEN 12

void		print_decrypted_msg(int* msg_vector, size_t len) {
	for (size_t i = 0; i < len; i++)
		putchar((char)(msg_vector[i] + 96));
	putchar('\n');
	free(msg_vector);
}

int*		get_decypher_matrix(const char* matrix) {
	size_t	i;
	int*	dec_matrix;
	char*	temp;

	i = 0;
	dec_matrix = (int*)malloc(sizeof(int) * MATRIX_LEN + 1);
	for (size_t j = 0; j < MATRIX_LEN; j++) {	
		temp = strnew(INT_MAX_LEN);
		wordlen = get_wordlen(matrix + i, ' ')
		dec_matrix[j] = atoi(strncpy(temp, matrix + i, wordlen));
		i += wordlen + 1; // we increment i additionally to pass a space position
		free(temp);
	}
	return (dec_matrix);
}


int		main(const int argc, const char* argv[]) {
	char*	matrix = (char*)strdup("1 4 3 9");
	char*	msg = (char*)strdup("tt");


}
