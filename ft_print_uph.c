#include "head.h"

static void	apply_flag_uph(char *res, t_params *params, int ind)
{
	char	c;

	c = 0;
	if (params->zero || params->min)
		ind = 0;
	if (params->hash)
		c++;
	if (c != 0)
		str_move(&res[ind], "0X");
}

static int	gen_len_uph(t_params *params, unsigned int content)
{
	int	l;

	l = len_base(content, 16);
	if (l < params->accuracy)
		l = params->accuracy;
	if (params->hash)
		l = l + 2;
	return (l);
}

static char	*gen_str_uph(t_params *params, int w, int l)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * w + 1);
	str[w] = '\0';
	fill_field(str, params, w);
	apply_flag_uph(str, params, w - l);
	return (str);
}

static char	*itoa_uph(t_params *params, unsigned int *content, int w, int l)
{
	char	*str;

	str = gen_str_uph(params, w, l);
	if (!(params->accuracy == 0 && *content == 0))
	{
		if (params->min)
			itoa_base_up(*content, 16, str + l - 1, params->accuracy);
		else
			itoa_base_up(*content, 16, str + w - 1, params->accuracy);
	}
	return (str);
}

int	print_uph(char *p, va_list m)
{
	int				w;
	int				l;
	char			*str;
	t_params		*params;
	unsigned int	content;

	params = gen_params(p, m);
	content = va_arg(m, unsigned int);
	l = gen_len_uph(params, content);
	w = params->width;
	if (w < l)
		w = l;
	str = itoa_uph(params, &content, w, l);
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
