#include "head.h"

static void	funcuint(unsigned int n, int base, int low, int *f)
{
	char	c;

	if (n >= base)
		funcuint(n / base, base, low, f);
	c = '0' + (n % base);
	if (n % base > 9 && low == 1)
		c = c + 39;
	if (n % base > 9 && low == 0)
		c = c + 7;
	*f = *f + 1;
	write(1, &c, 1);
}

int	ft_putuint_base(unsigned int n, int base, int low)
{
	int			f;


	f = 0;
	funcuint(n, base, low, &f);
	return (f);
}