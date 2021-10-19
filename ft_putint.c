#include "head.h"

static void	func(long int n, int base, int low, int *f)
{
	char	c;

	if (n >= base)
		func(n / base, base, low, f);
	c = '0' + (n % base);
	if (n % base > 9 && low == 1)
		c = c + 39;
	if (n % base > 9 && low == 0)
		c = c + 7;
	*f = *f + 1;
	write(1, &c, 1);
}

int	ft_putnbr_base(int n, int base, int low)
{
	int			f;
	long int	num;

	num = n;
	f = 0;
	if (num < 0)
	{
		num = num * -1;
		write(1, "-", 1);
		f++;
	}
	func(num, base, low, &f);
	return (f);
}