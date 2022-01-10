/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalactu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:03:29 by dgalactu          #+#    #+#             */
/*   Updated: 2021/12/04 16:03:31 by dgalactu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	gen_len_str(t_params *params, char *content)
{
	int	l;

	if (content)
	{
		l = ft_strlen(content);
		if (l > params->accuracy && params->accuracy >= 0)
			l = params->accuracy;
	}
	else if (params->accuracy >= 6 || params->accuracy < 0)
		l = 6;
	else
		l = 0;
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

static char	*add_str(t_params *params, char *content, int w, int l)
{
	char	*str;

	str = gen_str_str(params, w);
	if (content && params->min)
		str_n_move(str, content, l);
	else if (content && !params->min)
		str_n_move(str + (w - l), content, l);
	else if (!content && params->min && \
			(params->accuracy >= 6 || params->accuracy < 0))
		str_n_move(str, "(null)", l);
	else if (!content && !params->min && \
			(params->accuracy >= 6 || params->accuracy < 0))
		str_n_move(str + (w - l), "(null)", l);
	else if (!content && params->min && params->accuracy < 6)
		str_n_move(str, "", l);
	else if (!content && !params->min && params->accuracy < 6)
		str_n_move(str + (w - l), "", l);
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
	ft_putstr_fd(str, 1, w);
	free(str);
	return (w);
}
