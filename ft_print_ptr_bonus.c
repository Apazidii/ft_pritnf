/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalactu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:03:26 by dgalactu          #+#    #+#             */
/*   Updated: 2022/01/08 17:40:18 by dgalactu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	apply_flag_ptr(char *res, t_params *params, int ind)
{
	char	c;

	c = 0;
	if (params->zero || params->min)
		ind = 0;
	if (params->plus)
		c = '+';
	else if (params->space)
		c = ' ';
	if (c != 0)
	{
		res[ind] = c;
		ind++;
	}
	str_move(&res[ind], "0x");
}

static int	gen_len_ptr(t_params *params, unsigned long int content)
{
	int	l;

	l = len_ptr(content, 16);
	if (l < params->accuracy)
		l = params->accuracy;
	if (((params->plus || params->space) && content > 0))
		l++;
	l = l + 2;
	return (l);
}

static char	*gen_str_ptr(t_params *params, int w, int l)
{
	char	*str;

	str = (char *) malloc(sizeof(char) * w + 1);
	if (str == NULL)
		return (0);
	str[w] = '\0';
	fill_field(str, params, w);
	apply_flag_ptr(str, params, w - l);
	return (str);
}

static char	*itoa_ptr(t_params *params, unsigned long int *content, \
						int w, int l)
{
	char	*str;

	str = gen_str_ptr(params, w, l);
	if (str == NULL)
		return (NULL);
	if (params->min)
		itoa_base_low(*content, 16, str + l - 1, params->accuracy);
	else
		itoa_base_low(*content, 16, str + w - 1, params->accuracy);
	return (str);
}

int	print_ptr(char *p, va_list m)
{
	int					w;
	int					l;
	char				*str;
	t_params			*params;
	unsigned long int	content;

	params = gen_params(p, m);
	if (params == NULL)
		return (0);
	content = va_arg(m, unsigned long int);
	l = gen_len_ptr(params, content);
	w = params->width;
	if (w < l)
		w = l;
	str = itoa_ptr(params, &content, w, l);
	if (str == NULL)
		free(params);
	if (str == NULL)
		return (0);
	if (!(params->accuracy == 0 && params->width == 0 && content == 0))
		ft_putstr_fd(str, 1, w);
	free(params);
	free(str);
	return (w);
}