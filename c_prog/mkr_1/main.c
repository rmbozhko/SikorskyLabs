#include "util.h"


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
	size_t	wordlen;

	i = 0;
	dec_matrix = (int*)malloc(sizeof(int) * MATRIX_LEN + 1);
	for (size_t j = 0; j < MATRIX_LEN; j++) {	
		temp = ft_strnew(INT_MAX_LEN);
		wordlen = get_wordlen(matrix + i, ' ');
		dec_matrix[j] = ft_atoi(ft_strncpy(temp, matrix + i, wordlen));
		i += wordlen + 1; // we increment i additionally to pass a space position
		free(temp);
	}
	return (dec_matrix);
}


int		main(const int argc, const char* argv[]) {
	char*	matrix = ft_strdup("1 4 3 9");
	char*	msg = ft_strdup("tt");

	int*	dec_matrix = get_decypher_matrix("0 0 0 0");
	for (size_t i = 0; i < MATRIX_LEN; i++)
		printf("i[%d]:%d\n", i, dec_matrix[i]);
}
