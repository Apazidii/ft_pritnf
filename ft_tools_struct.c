#include "head.h"

void	init_params(t_params *s)
{
	s->min = 0;
	s->plus = 0;
	s->space = 0;
	s->hash = 0;
	s->zero = 0;
	s->width = 0;
	s->accuracy = 0;
}

void	detect_flags(t_params *res, char *params)
{
	while ((!(*params > '0' && *params <= '9') && \
			*params != '\0' && *params != '.'))
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
}

t_params	*gen_params(char *params, va_list m)
{
	t_params	*res;

	res = (t_params *)malloc(sizeof(t_params) * 1);
	init_params(res);
	res->width = get_width(params, m);
	res->accuracy = get_accuracy(params, m);
	detect_flags(res, params);
	if (res->accuracy >= 0)
		res->zero = 0;
	if (res->width < 0)
	{
		res->width = res->width * -1;
		res->min = 1;
	}
	return (res);
}

void	clear_params(t_params *s)
{
	s->plus = 0;
	s->space = 0;
	s->hash = 0;
	s->zero = 0;
}
