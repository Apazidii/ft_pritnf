#include "ft_printf.h"

static void	apply_flag_int(char *res, t_params *params,
							long int *content, int ind)
{
	char	c;

	c = 0;
	if (params->zero || params->min)
		ind = 0;
	if (*content < 0)
	{
		c = '-';
		*content = *content * -1;
	}
	else if (params->plus)
		c = '+';
	else if (params->space)
		c = ' ';
	if (c != 0)
		res[ind] = c;
}

static int	gen_len_int(t_params *params, long int content)
{
	int	l;

	l = len_base(content, 10);
	if (l < params->accuracy)
		l = params->accuracy;
	if (((params->plus || params->space) && content > 0) || content < 0)
		l++;
	return (l);
}

static char	*gen_str_int(t_params *params, long int *content, int w, int l)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * w + 1);
	str[w] = '\0';
	fill_field(str, params, w);
	apply_flag_int(str, params, content, w - l);
	return (str);
}

static char	*itoa_int(t_params *params, long int *content, int w, int l)
{
	char	*str;

	str = gen_str_int(params, content, w, l);
	if (!(params->accuracy == 0 && *content == 0))
	{
		if (params->min)
			itoa_base_low(*content, 10, str + l - 1, params->accuracy);
		else
			itoa_base_low(*content, 10, str + w - 1, params->accuracy);
	}
	return (str);
}

int	print_int(char *p, va_list m)
{
	int			w;
	int			l;
	char		*str;
	t_params	*params;
	long int	content;

	params = gen_params(p, m);
	content = va_arg(m, int);
	l = gen_len_int(params, content);
	w = params->width;
	if (w < l)
		w = l;
	str = itoa_int(params, &content, w, l);
	free(params);
	if (!(params->accuracy == 0 && params->width == 0 && content == 0))
	{
		ft_putstr_fd(str, 1, w);
		free(str);
		return (w);
	}
	free(str);
	return (0);
}
