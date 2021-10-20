#include "head.h"


int	print_int(char *params, int content)
{
	int	res;
	int	w;

	res = 0;
	res = res + fill_width(params, &content, len_int);
	res = res + (ft_putnbr_base(content, 10, 0));
	return (res);
}

int	print_uint(char *params, unsigned int content)
{
	int	res;
	int	w;

	res = 0;

	res = res + (ft_putuint_base(content, 10, 0));
	return (res);
}


int	print_hexadecimal(char *params, long long int content)
{
	int	res;
	int	w;

	res = 0;

	res = res + (ft_putllint_base(content, 16, 1));
	return (res);
}

int	print_Hexadecimal(char *params, long long int content)
{
	int	res;
	int	w;

	res = 0;

	res = res + (ft_putllint_base(content, 16, 0));
	return (res);
}

int	print_char(char *params, char content)
{
	int	res;
	int	w;

	res = 0;

	res++;
	write(1, &content, 1);
	return (res);
}

int	print_string(char *params, char *content)
{
		int	res;
	int	w;

	res = 0;
	w = get_width(params);
	w = w - ft_strlen(content);
	if (w > 0)
		res = res + fill_c(' ', w);

	if (content == NULL)
	{
		write(1, "(null)", 6);
		return (res + 6);
	}
	return (ft_putstr_l(content, 1) + res);
}

int	print_pointer(char *params, unsigned long long int content)		//%p
{
	int	res;
	int	w;

	res = 0;

	write(1, "0x", 2);
	res = res + (ft_putullint_base(content, 16, 1) + 2);
	return (res);
	write(1, "0x", 2);
	// printf("\n#%llu\n", content);
	return (ft_putullint_base(content, 16, 1) + 2);
}

int	print_procent(char *params)
{
	(void)params;
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