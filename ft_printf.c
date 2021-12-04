#include "head.h"

int	def_to_types(char *params, char type, va_list m)
{
	if (type == 'd' || type == 'i')
		return (print_int(params, m));
	else if (type == 'c')
		return (print_chr(params, m));
	else if (type == 's')
		return (print_str(params, m));
	else if (type == 'p')
		return (print_ptr(params, m));
	else if (type == 'x')
		return (print_hex(params, m));
	else if (type == 'X')
		return (print_uph(params, m));
	else if (type == '%')
		return (print_prc(params, m));
	else if (type == 'u')
		return (print_unt(params, m));
	else
		return (0);
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
	//сюда вставишь добавление строки с параметром к основной строке
	free(res);
	return (&s[i + 1]);
}

int	ft_printf(const char *str, ...)
{
	char	*s;
	int		res_n;
	char 	*res_s;
	va_list	m;
	int		i;

	res_s = NULL;
	res = 0;
	i = 0;
	s = (char *)str;
	va_start(m, str);
	while (*s != '\0')
	{
		if (is_format(s))
		{
			res_s = str_add(res_s, strr(i, s - i), res_n, i);
			s = print_arg(++s, m, &res_n);
			res_n = res_n + i;
			i = 0;
		}
		else
		{
			write(1, s, 1);
			res_n++;
			s++;
			i++;
		}
	}
	va_end(m);
	return (res);
}

// int i = 0;
//   char *res;
//   res = NULL;
//   while (*s != 0)
//   {
//     if (is_format(s))
//     {
//       res = str_add(res, strr(i, s - i));
//       res = str_add(res, strr(4, "1234")); 
//       i = 0;
//     }
//     else
//       i++;
      
//     s++;
//   }
//   res = str_add(res, strr(i, s - i)); 