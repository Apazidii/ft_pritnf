#include "head.h"

static void	funcllint(unsigned long long int n, int base, int low, int *f)
{
	char	c;

	if (n >= base)
		funcllint(n / base, base, low, f);
	c = '0' + (n % base);
	if (n % base > 9 && low == 1)
		c = c + 39;
	if (n % base > 9 && low == 0)
		c = c + 7;
	*f = *f + 1;
	write(1, &c, 1);
}

int	ft_putllint_base(long long int n, int base, int low)
{
	int			f;
	unsigned long long int num;


	f = 0;
	if (n < 0)
	{
		num = n;
		write(1, "-", 1);
		f++;
	}
	funcllint(n, base, low, &f);
	return (f);
}