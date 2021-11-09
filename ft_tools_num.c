#include "head.h"

void	func_itoa(unsigned long int n, int base, char *res, int upper)
{
	char	c;

	if (n >= (unsigned long int) base)
		func_itoa(n / base, base, res - 1, upper);
	if ((n % base) > 9)
	{
		if (upper)
			c = (n % base) - 10 + 'A';
		else
			c = (n % base) - 10 + 'a';
	}
	else
		c = (n % base) + '0';
	*res = (char) c;
}

void	fill_zero(char *s, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		s[i] = '0';
		i++;
	}
}

char	*itoa_base_low(unsigned long int n, int base, char *res, int ac)
{
	fill_zero(res - (ac - 1), ac);
	func_itoa(n, base, res, 0);
	return (res);
}

char	*itoa_base_up(unsigned long int n, int base, char *res, int ac)
{
	fill_zero(res - (ac - 1), ac);
	func_itoa(n, base, res, 1);
	return (res);
}

int	len_base(long long int n, int base)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / base;
		i++;
	}
	return (i);
}
