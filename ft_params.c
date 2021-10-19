#include "head.h"

int is_flags(char c)
{
	if (c == '+' || c == '-' || \
		c == ' ' || c == '#' || \
		c == '0')
		return (1);
	return (0);
}

int	get_width(char *str)
{
	while (is_flags(*str))
		str++;
	return (ft_atoi(str));
}

int	find_flag(char c, char *params)
{
    while (!(*params > '0' && *params <= '9'))
	{
		if (*params == c)
			return (1);
		params++;
	}
	return (0);
}

int	fill_c(char c, int k)
{
	while (k > 0)
	{
		write(1, &c, 1);
		k--;
	}
}