#include "head.h"

static char	*gen_str_chr(t_params *params, int w)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * w + 1);
	if (!str)
		return (NULL);
	str[w] = '\0';
	fill_field(str, params, w);
	return (str);
}

static char	*add_chr(t_params *params, unsigned char content, int w, int l)
{
	char	*str;

	str = gen_str_chr(params, w);
	if (!str)
		return (NULL);
	if (params->min)
		str[0] = content;
	else
		str[w - l] = content;
	return (str);
}

int	print_chr(char *p, va_list m)
{
	int				w;
	int				l;
	char			*str;
	t_params		*params;
	unsigned char	content;

	params = gen_params(p, m);
	clear_params(params);
	content = va_arg(m, int);
	l = 1;
	w = params->width;
	if (w < l)
		w = l;
	str = add_chr(params, content, w, l);
	if (!str)
		return (0);
	free(params);
	ft_putstr_fd(str, 1, w);
	free(str);
	return (w);
}
