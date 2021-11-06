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

int is_flags(char c)
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

int get_accuracy(char *str, va_list m)
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

void fill_field(char *s, t_params *params, int w)
{
    char c;

    if (params->zero && !(params->min))
        c = '0';
    else
        c = ' ';
    while (w != 0)
    {
        *s = c;
        w--;
        s++;
    }
}

int len_base(long long int n, int base)
{
    int    i;


    i = 0;
	if (n == 0)
		return (1);
    while (n != 0)
    {
        n = n / base;
        i++;
    }
    return (i);
}


void func_itoa(unsigned long int n, int base, char *res, int upper)
{
	char c;

    if (n >= (unsigned long int) base)
		func_itoa(n / base, base, res - 1, upper);
	if ((n % base) > 9)
	{
		if (upper)
			c = (n % base) - 10 + 'A';
		else
			c = (n % base) - 10 + 'a';
	}
	else
		c = (n % base) + '0';
    
	
	*res = (char) c;
}

void fill_zero(char *s, int n)
{
	int i = 0;

	while (i < n)
	{
		s[i] = '0';
		i++;
	}
}

char *itoa_base(unsigned long int n, int base, char *res, int upper, int ac)
{
	fill_zero(res - (ac - 1), ac);
	func_itoa(n, base, res, upper);
	return res;
}

void str_move(char *str, char *content)
{
	while (*content != '\0')
	{
		*str = *content;
		str++;
		content++;
	}
}
int	find_flag(char c, char *params)
{
    while ((!(*params > '0' && *params <= '9') && *params != '\0'))
	{
		if (*params == c)
			return (1);
		params++;
	}
	return (0);
}
void init_params(t_params *s)
{
	s->min = 0;
	s->plus = 0;
	s->space = 0;
	s->hash = 0;
	s->zero = 0;
	s->width = 0;
	s->accuracy = 0;
}

t_params *gen_params(char *params, va_list m)
{
	t_params	*res;

	res = (t_params *)malloc(sizeof(t_params) * 1);
	init_params(res);
	res->width = get_width(params, m);
	res->accuracy = get_accuracy(params, m);
	while ((!(*params > '0' && *params <= '9') && *params != '\0' && *params != '.'))
	{
		if (*params == '-')
			res->min = 1;
		if (*params == '+')
			res->plus = 1;
		if (*params == ' ')
			res->space = 1;
		if (*params == '#')
			res->hash = 1;
		if (*params == '0')
			res->zero = 1;
		params++;
	}
	if (res->accuracy > 0)
		res->zero = 0;
	return (res);
}