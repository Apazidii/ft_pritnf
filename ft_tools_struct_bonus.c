/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalactu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:03:57 by dgalactu          #+#    #+#             */
/*   Updated: 2021/12/04 16:03:59 by dgalactu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	if (res == NULL)
		return (NULL);
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

int	push(t_params *params, char *str, int w, long int content)
{
	if (!(params->accuracy == 0 && params->width == 0 && content == 0))
		ft_putstr_fd(str, 1, w);
	else
		w = 0;
	free(params);
	free(str);
	return (w);
}
