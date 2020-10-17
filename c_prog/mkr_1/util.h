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
int		ft_is_whitespace(char c);
int		ft_isdigit(int c);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strdup(const char *s);
void	ft_intswap(int *ar1, int *ar2);
size_t	ft_strlen(const char *str);
#endif
