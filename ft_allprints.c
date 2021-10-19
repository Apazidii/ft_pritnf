#include "head.h"


int	print_int(char *params, int content)
{
	int	w;
	int	res;

	// w = get_width(params);
	res = 0;
	// if (find_flag('+', params))
	// 	if (content >= 0)
	// 	{
	// 		write(1, "+", 1);
	// 		res++;
	// 	}
	// else if (find_flag(' ', params))
	// 	if (content >= 0)
	// 	{
	// 		write(1, " ", 1);
	// 		res++;
	// 	}
	res = res + (ft_putnbr_base(content, 10, 0));
	return (res);
}

int	print_uint(char *params, unsigned int content)
{
	return (ft_putuint_base(content, 10, 0));
}


int	print_hexadecimal(char *params, long long int content)
{
	return (ft_putllint_base(content, 16, 1));
}

int	print_Hexadecimal(char *params, long long int content)
{
	return (ft_putllint_base(content, 16, 0));
}

int	print_char(char *params, char content)
{
	write(1, &content, 1);
	return (1);
}

int	print_string(char *params, char *content)
{
	if (content == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	return (ft_putstr_l(content, 1));
}

int	print_pointer(char *params, unsigned long long int content)		//%p
{
	write(1, "0x", 2);
	// printf("\n#%llu\n", content);
	return (ft_putullint_base(content, 16, 1) + 2);
}

int	print_procent(char *params)
{
	write(1, "%", 1);
	return (1);
}	//%X


int	ft_putstr_l(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
	return (i);
}