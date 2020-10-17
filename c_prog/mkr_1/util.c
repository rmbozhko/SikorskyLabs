void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	*ft_strnew(size_t size)
{
	char	*temp;

	return (((temp = (char*)malloc(size + 1)) == NULL) ? NULL :
			ft_memset(temp, 0, size + 1));
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

void		ft_print_iarr(int *arr, size_t len)
{
	size_t		i;

	i = 0;
	while (i < len)
	{
		ft_putnbrendl(arr[i]);
		i++;
	}
}
