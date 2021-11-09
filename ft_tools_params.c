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

int	is_flags(char c)
{
	if (c == '+' || c == '-' || \
		c == ' ' || c == '#' || \
		c == '0')
		return (1);
	return (0);
}

int	get_width(char *str, va_list m)
{
	while (is_flags(*str))
		str++;
	if (*str == '*')
		return (va_arg(m, int));
	return (ft_atoi(str));
}

int	get_accuracy(char *str, va_list m)
{
	while (*str != '.' && *str != '\0')
		str++;
	if (*str == '.')
	{
		if (*(str + 1) == '*')
			return (va_arg(m, int));
		return (ft_atoi(str + 1));
	}
	return (-1);
}
