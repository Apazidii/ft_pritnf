#include "head.h"

int	def_to_types(char *params, char type, va_list m)
{
	int	w;

	w = get_width(params);
	w = apply_half_params(params, w);
	if (type == 'd' || type == 'i')
		return (print_int(params, va_arg(m, int)));
	else if (type == 'c')
		return (print_char(params, va_arg(m, int)));
	else if (type == 's')
		return (print_string(params, va_arg(m, char *)));
	else if (type == 'p')
		return (print_pointer(params, va_arg(m, unsigned long long int)));
	else if (type == 'x')
		return (print_hexadecimal(params, va_arg(m, long long int)));
	else if (type == 'X')
		return (print_Hexadecimal(params, va_arg(m, long long int)));
	else if (type == '%')
		return (print_procent(params));
	else if (type == 'u')
		return (print_uint(params, va_arg(m, unsigned int)));
	else
		return (print_int(params, va_arg(m, int)));
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

int main()
{
	// int k = 1234;
	// printf("%d\n", len_int(&k));
	ft_printf("_%6d_", -1234);

// https://github.com/paulo-santana/ft_printf_tester.git
}


