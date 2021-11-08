#include "head.h"

static int	gen_len_str(t_params *params, char *content)
{
	int	l;

	l = ft_strlen(content);
	if (l > params->accuracy && params->accuracy >= 0)
		l = params->accuracy;
	return (l);
}

static char	*gen_str_str(t_params *params, int w)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * w + 1);
	str[w] = '\0';
	fill_field(str, params, w);
	return (str);
}
//void		str_n_move(char *str, char *content, int l);
static char	*add_str(t_params *params, char  *content, int w, int l)
{
	char	*str;

	str = gen_str_str(params, w);
	if (params->min)
		str_n_move(str, content, l);
	else
		str_n_move(str + (w - l), content, l);
	return (str);
}

int	print_str(char *p, va_list m)
{
	int			w;
	int			l;
	char		*str;
	t_params	*params;
	char		*content;

	params = gen_params(p, m);
	clear_params(params);
	content = va_arg(m, char *);
	l = gen_len_str(params, content);
	w = params->width;
	if (w < l)
		w = l;
	str = add_str(params, content, w, l);
	free(params);
	ft_putstr_fd(str, 1);
	free(str);
	return (w);
}
