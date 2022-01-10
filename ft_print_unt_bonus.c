/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalactu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:03:32 by dgalactu          #+#    #+#             */
/*   Updated: 2021/12/04 16:03:36 by dgalactu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	apply_flag_unt(char *res, t_params *params, int ind)
{
	char	c;

	c = 0;
	if (params->zero || params->min)
		ind = 0;
	if (c != 0)
		res[ind] = c;
}

static int	gen_len_unt(t_params *params, unsigned int content)
{
	int	l;

	l = len_base(content, 10);
	if (l < params->accuracy)
		l = params->accuracy;
	return (l);
}

static char	*gen_str_unt(t_params *params, int w, int l)
{
	char	*str;

	str = (char *) malloc(sizeof(char) * w + 1);
	if (str == NULL)
		return (NULL);
	str[w] = '\0';
	fill_field(str, params, w);
	apply_flag_unt(str, params, w - l);
	return (str);
}

static char	*itoa_unt(t_params *params, unsigned int *content, int w, int l)
{
	char	*str;

	str = gen_str_unt(params, w, l);
	if (str == NULL)
		return (NULL);
	if (!(params->accuracy == 0 && *content == 0))
	{
		if (params->min)
			itoa_base_low(*content, 10, str + l - 1, params->accuracy);
		else
			itoa_base_low(*content, 10, str + w - 1, params->accuracy);
	}
	return (str);
}

int	print_unt(char *p, va_list m)
{
	int				w;
	int				l;
	char			*str;
	t_params		*params;
	unsigned int	content;

	params = gen_params(p, m);
	if (params == NULL)
		return (0);
	content = va_arg(m, unsigned int);
	l = gen_len_unt(params, content);
	w = params->width;
	if (w < l)
		w = l;
	str = itoa_unt(params, &content, w, l);
	if (str == NULL)
		free(params);
	if (str == NULL)
		return (0);
	w = push(params, str, w, content);
	return (w);
}