#include "util.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	*ft_strnew(size_t size)
{
	char	*temp;

	return (((temp = (char*)malloc(size + 1)) == NULL) ? NULL : ft_memset(temp, 0, size + 1));
}

size_t		get_wordlen(const char *s, char c)
{
	size_t len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		s++;
		len++;
	}
	return (len);
}

int		ft_atoi(char *str)
{
	size_t				i;
	int					sign;
	unsigned long int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (ft_is_whitespace(str[i]))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while ((str[i] != '\0') && ft_isdigit(str[i]))
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return ((int)(result * sign));
}

char	*ft_strncpy(char *dest, const char *src, size_t num)
{
	char *temp;

	temp = dest;
	while (*src && num > 0)
	{
		*temp++ = *src++;
		num--;
	}
	while (num-- > 0)
		*temp++ = 0;
	return (dest);
}

int		ft_is_whitespace(char c)
{
	return ((c == ' ' || c == '\t' || c == '\n' ||
		c == '\v' || c == '\f' || c == '\r') ? (1) : (0));
}

int		ft_isdigit(int c)
{
	return ((c >= 48 && c <= 57) ? (1) : (0));
}

void	*ft_memset(void *b, int c, size_t len)
{
	int i;

	i = 0;
	while (len-- != 0)
		((unsigned char *)b)[i++] = (unsigned char)c;
	return (b);
}

char	*ft_strdup(const char *s)
{
	char	*temp;
	int		i;

	temp = (char*)malloc((sizeof(char) * ft_strlen(s)) + 1);
	if (temp == NULL)
		return (NULL);
	else
	{
		i = 0;
		while (s[i] != '\0')
		{
			temp[i] = s[i];
			i++;
		}
		temp[i] = '\0';
	}
	return (temp);
}

void	ft_intswap(int *ar1, int *ar2)
{
	int		temp;

	temp = *ar1;
	*ar1 = *ar2;
	*ar2 = temp;
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while(str[i] != '\0')
		i++;
	return (i);
}

bool	ft_is_integer(double val)
{
	int	truncated;

	truncated = (int)val;
	return (val == truncated);
}
