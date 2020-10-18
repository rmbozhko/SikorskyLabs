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
	long double	temp;
	bool		cond;

	cond = ((*matrix_elem < 0 || *matrix_elem > 0)&& determinant < 0);

	//if ((*matrix_elem < 0 || *matrix_elem > 0)&& determinant < 0)
	//{
	//	temp = ((-1) * (*matrix_elem) + (26 * k));
	//	temp /= ((-1) * determinant);
	//}
	//else
		temp = (((cond) ? (-1) : (1)) * (*matrix_elem) + (26 * k));
		temp /= ((cond) ? (-1) : (1)) * determinant;
	printf("det:%d, k:%d\n", determinant, k);
	printf("mat_elem:%d, temp:%Lf\n", *matrix_elem, temp);
	if (temp < 0.0 || !ft_is_integer(temp)) // need to test recursion
		normalize_elem(matrix_elem, k + 1, determinant);
	else
		*matrix_elem = temp;
}

void		increment_elem(int* matrix_elem, size_t k) {
	if ((*matrix_elem + 26 * k)> 0) {
		*matrix_elem += 26 * k;
		return ;
	}
	increment_elem(matrix_elem, k + 1);	
}

void		normalize_matrix_elems(int* inv_matrix, int determinant) {
	for (size_t i = 0; i < MATRIX_LEN; i++) {
		printf("elem:%d\n", inv_matrix[i]);
		if ((inv_matrix[i] % determinant) == 0) {
			inv_matrix[i] /= determinant;
			(inv_matrix[i] < 0) ? increment_elem(&inv_matrix[i], 1) : 0;
		}
		else
			normalize_elem(&inv_matrix[i], 1, determinant);			
	}
	for (size_t i = 0; i < MATRIX_LEN; i++)
		printf("inv_mat[%d]:%d\n", i, inv_matrix[i]);
	exit(0);
}

int*		get_inverse_matrix(int* dec_matrix) {
	int	determinant;
	int*	adj_matrix;

	determinant = get_matrix_determinant(dec_matrix);
	if (determinant	== 0) {
		printf("Передана матриця - вироджена");
		free(dec_matrix);
		exit(1);
	}
	//printf("%d\n", determinant);
	adj_matrix = get_adj_matrix(dec_matrix);
	transpose_matrix(adj_matrix);
	for (size_t i = 0; i < MATRIX_LEN; i++)
		printf("i[%d]:%d\n", i, adj_matrix[i]);
	normalize_matrix_elems(adj_matrix, determinant);	
	for (size_t i = 0; i < MATRIX_LEN; i++)
		printf("inv[%d]:%d\n", i, adj_matrix[i]);
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
	//for (size_t i = 0; i < MATRIX_LEN; i++)
	//	printf("i[%d]:%d\n", i, dec_matrix[i]);
	int*	inv_matrix = get_inverse_matrix(dec_matrix);
	for (size_t i = 0; i < MATRIX_LEN; i++)
		printf("inverted[%d]:%d\n", i, inv_matrix[i]);
	int*	dec_msg = get_encoded_msg("tt");
	multiply_matrices(inv_matrix, dec_msg);
	print_decrypted_msg(dec_msg);
	for (size_t i = 0; i < MSG_LEN; i++)
		printf("msg[%d]:%d\n", i, dec_msg[i]);
	free(dec_msg);
	free(dec_matrix);
}
