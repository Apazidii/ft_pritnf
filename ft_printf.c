#include "head.h"

int	def_to_types(char *params, char type, va_list m)
{
	if (type == 'd' || type == 'i')
		return (print_int(params, m));
	// else if (type == 'c')
	// 	return (print_chr(params, va_arg(m, int)));
	// else if (type == 's')
	// 	return (print_str(params, va_arg(m, char *)));
	// else if (type == 'p')
	// 	return (print_ptr(params, va_arg(m, unsigned long int)));
	else if (type == 'x')
		return (print_hex(params, m));
	else if (type == 'X')
		return (print_HEX(params, m));
	// else if (type == '%')
	// 	return (print_prc());
	// else if (type == 'u')
	// 	return (print_unt(params, va_arg(m, unsigned int)));
	// else
	// 	return (print_not(params));
	else
		return (1);
}

char	*print_arg(char *s, va_list m, int *l)
{
	int		i;
	char	*res;

	i = 0;
	while (!(is_convs(s[i])))
		i++;
	res = ft_substr(s, 0, i);
	*l = *l + def_to_types(res, s[i], m);
	free(res);

	return (&s[i + 1]);
}

int	ft_printf(const char *str, ...)
{
	char	*s = (char *)str;
	int		res;
	va_list	m;

	res = 0;
	va_start(m, str);
	while (*s != '\0')
	{
		if (*s == '%')
		{
			s++;
			s = print_arg(s, m, &res);
		}
		else
		{
			write(1, s, 1);
			res++;
			s++;
		}
	}
	va_end(m);
	return (res);
}
