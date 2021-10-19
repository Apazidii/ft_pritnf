#include "head.h"

static void	funcullint(unsigned long long int n, int base, int low, int *f)
{
	char	c;

	if (n >= base)
		funcullint(n / base, base, low, f);
	c = '0' + (n % base);
	if (n % base > 9 && low == 1)
		c = c + 39;
	if (n % base > 9 && low == 0)
		c = c + 7;
	*f = *f + 1;
	write(1, &c, 1);
}

int	ft_putullint_base(unsigned long long int n, int base, int low)
{
	int			f;

	f = 0;
	funcullint(n, base, low, &f);
	return (f);
}