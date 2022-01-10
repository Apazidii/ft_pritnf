/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalactu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:03:55 by dgalactu          #+#    #+#             */
/*   Updated: 2021/12/04 16:03:57 by dgalactu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	str_move(char *str, char *content)
{
	while (*content != '\0')
	{
		*str = *content;
		str++;
		content++;
	}
}

void	str_n_move(char *str, char *content, int l)
{
	int	i;

	i = 0;
	while (*content != '\0' && i < l)
	{
		i++;
		*str = *content;
		str++;
		content++;
	}
}

void	fill_field(char *s, t_params *params, int w)
{
	char	c;

	if (params->zero && !(params->min))
		c = '0';
	else
		c = ' ';
	while (w != 0)
	{
		*s = c;
		w--;
		s++;
	}
}
