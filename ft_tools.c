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

int len_int(long long int n)
{
	int	i;

	if (n < 0)
		i = 1;
	else 
		i = 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}