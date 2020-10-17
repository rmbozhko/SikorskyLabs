#ifndef UTIL_H_
# define UTIL_H_

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MATRIX_ROW_LEN 2
#define MATRIX_LEN (MATRIX_ROW_LEN * MATRIX_ROW_LEN)
#define INT_MAX_LEN 12

void	ft_putchar(char c);
char	*ft_strnew(size_t size);
size_t	get_wordlen(const char *s, char c);
int	ft_atoi(char *str);
char	*ft_strncpy(char *dest, const char *src, size_t num);
void	ft_print_iarr(int *arr, size_t len);
#endif
