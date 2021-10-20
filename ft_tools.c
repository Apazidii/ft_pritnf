#include "head.h"

int	is_convs(char c)
{
	if (c == 'd' || c == 'i' || c == 'o' || \
		c == 'u' || c == 'x' || c == 'X' || \
		c == 'e' || c == 'E' || c == 'f' || \
		c == 'F' || c == 'g' || c == 'G' || \
		c == 'a' || c == 'A' || c == 'c' || \
		c == 's' || c == 'p' || c == 'n' || \
		c == '%')
		return (c);
	return (0);
}

int len_base(long long int n, int base)
{
	int	i;

	if (n < 0)
		i = 1;
	else 
		i = 0;
	while (n != 0)
	{
		n = n / base;
		i++;
	}
	return (i);
}
// int (*f)(void *)

int	len_int(void *n)
{
	int	k;

	k = *((int *)n);
	return (len_base(k, 10));
}

int len_chr(void *n)
{
	(void)n;
	return (1);
}

int	len_str(void *n)
{
	return (ft_strlen(*((char **)n)));
}

int	len_hex(void *n)
{
	int	k;

	k = *((long int *)n);
	return (len_base(k, 16));
}
