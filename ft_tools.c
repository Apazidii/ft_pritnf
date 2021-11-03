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

int	get_width(char *str)
{
	while (is_flags(*str))
		str++;
	return (ft_atoi(str));
} 

int get_accuracy(char *str)
{
    while (*str != '.' && *str != '\0')
        str++;
    if (*str == '.')
        return (ft_atoi(str + 1));
    return (0);
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

void fill_field(char *s, char *params, int w)
{
    char c;

    if (find_flag('0', params) && !(find_flag('-', params)))
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
	while (n > 0)
	{
		*s = '0';
		s--;
		n--;
	}
}

char *itoa_base(unsigned long int n, int base, char *res, int upper, int ac)
{
	fill_zero(res, ac);
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

char *del_flag(char *str, char c)
{
	
}