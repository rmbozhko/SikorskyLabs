#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

void  	ft_swap(int *a, int *b) {
  int   temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

int   	**initialize_matrix(void) {
  int  **bi_iarr;
  int   temp;

  bi_iarr = (int**)malloc(sizeof(int) * SIZE);
  for (int i = 0; i < SIZE; i++) {
    bi_iarr[i] = (int*)malloc(sizeof(int) * SIZE);
    for (int j = 0; j < SIZE; j++) {
      printf("Enter value for matrix[%d][%d]: ", i, j);
      scanf("%d", &temp);
      bi_iarr[i][j] = temp;
    }
  }
  return (bi_iarr);
}


void  	rotate_matrix(int **bi_iarr) {
  for (int i = 0; i < SIZE; i++) {
    ft_swap(&bi_iarr[i][0], &bi_iarr[i][2]);
  }
}

void  	print_matrix(int **bi_iarr) {
  for (int i = 0; i < SIZE; i++) {
    printf("|%d %d %d|\n", bi_iarr[i][0], bi_iarr[i][1], bi_iarr[i][2]);
  }
}

void	free_matrix(int	**bi_iarr) {
  for (int i = 0; i < SIZE; i++) {
    free(bi_iarr[i]);
  }
  free(bi_iarr);
}

int   	main(void) {
  int   **bi_iarr;
  
  bi_iarr = initialize_matrix();
  print_matrix(bi_iarr);
  rotate_matrix(bi_iarr);
  printf("\nMatrix was rotated vertically through its center\n\n");
  print_matrix(bi_iarr);
  free_matrix(bi_iarr);
}
