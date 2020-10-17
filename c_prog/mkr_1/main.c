#include "util.h"

/*
 *Message manipulation functions
 */
void		print_decrypted_msg(int* msg_vector) {
	for (size_t i = 0; i < MSG_LEN; i++)
		putchar((char)(msg_vector[i] + 96));
	putchar('\n');
}

int*		get_encoded_msg(const char* msg) {
	int*	dec_msg;

	dec_msg = (int*)malloc(sizeof(int) * MSG_LEN);
	for (size_t i = 0; i < MSG_LEN; i++) {
		dec_msg[i] = ((int)msg[i] - 96);
	}
	return (dec_msg);
}

/*
 *Converting matrix from char* to int arr
 */
int*		get_decypher_matrix(const char* matrix) {
	size_t	i;
	int*	dec_matrix;
	char*	temp;
	size_t	wordlen;

	i = 0;
	dec_matrix = (int*)malloc(sizeof(int) * MATRIX_LEN);
	for (size_t j = 0; j < MATRIX_LEN; j++) {	
		temp = ft_strnew(INT_MAX_LEN);
		wordlen = get_wordlen(matrix + i, ' ');
		dec_matrix[j] = ft_atoi(ft_strncpy(temp, matrix + i, wordlen));
		i += wordlen + 1; // we increment i additionally to pass a space position
		free(temp);
	}
	return (dec_matrix);
}

/*
 *Matrices manipulation functions
 */
int		get_matrix_determinant(const int* dec_matrix) {

	return ((dec_matrix[0] * dec_matrix[3]) - (dec_matrix[1] * dec_matrix[2]));
}


int*		get_adj_matrix(int* dec_matrix) {	
	ft_intswap(&dec_matrix[0], &dec_matrix[3]);	
	ft_intswap(&dec_matrix[1], &dec_matrix[2]);
	dec_matrix[1] = (-1) * dec_matrix[1];	
	dec_matrix[2] = (-1) * dec_matrix[2];

	return (dec_matrix);	
}

void		transpose_matrix(int* adj_matrix) {	
	ft_intswap(&adj_matrix[1], &adj_matrix[2]);
}

void		normalize_elem(int* matrix_elem, size_t k, int determinant) {
	int	temp;

	temp = (*matrix_elem + (26 * k)) / determinant;
	if (*matrix_elem < 0 || !ft_is_integer(*matrix_elem / determinant))
		normalize_elem(matrix_elem, k + 1, determinant);
	else {
		*matrix_elem += (26 * k);
		return ;
	}

}

void		normalize_matrix_elems(int* inv_matrix, int determinant) {
	int	temp;

	for (size_t i = 0; i < MATRIX_LEN; i++) {
		if (inv_matrix[i] < 0 || !ft_is_integer(inv_matrix[i] / determinant))
			normalize_elem(&inv_matrix[i], 1, determinant);
		inv_matrix[i] /= determinant;
	}
}

int*		get_inverse_matrix(int* dec_matrix) {
	int	determinant;
	int*	adj_matrix;

	determinant = get_matrix_determinant(dec_matrix);
	if (determinant	== 0){
		printf("Передана матриця - вироджена");
		free(dec_matrix);
		exit(1);
	}
		
	adj_matrix = get_adj_matrix(dec_matrix);
	transpose_matrix(adj_matrix);
	normalize_matrix_elems(adj_matrix, determinant);	
}


void		multiply_matrices(int* dec_msg, const int* inv_matrix) {
	int	temp0;
	int	temp1;

	temp0 = inv_matrix[0] * dec_msg[0] + inv_matrix[1] * dec_msg[1];
	temp1 = inv_matrix[2] * dec_msg[0] + inv_matrix[3] * dec_msg[1];
	dec_msg[0] = temp0;
	dec_msg[1] = temp1;
}

int		main(const int argc, const char* argv[]) {
	int*	dec_matrix = get_decypher_matrix("1 4 3 9");
	int*	inv_matrix = get_inverse_matrix(dec_matrix);
	int*	dec_msg = get_encoded_msg("tt");
	multiply_matrices(inv_matrix, dec_msg);
	print_decrypted_msg(dec_msg);
	for (size_t i = 0; i < MATRIX_LEN; i++)
		printf("i[%d]:%d\n", i, dec_matrix[i]);
	for (size_t i = 0; i < MSG_LEN; i++)
		printf("i[%d]:%d\n", i, dec_msg[i]);
	free(dec_msg);
	free(dec_matrix);
}
