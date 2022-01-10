/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalactu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 17:48:04 by dgalactu          #+#    #+#             */
/*   Updated: 2022/01/08 17:53:41 by dgalactu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <math.h>

typedef struct s_params
{
	int	min;
	int	plus;
	int	space;
	int	hash;
	int	zero;
	int	width;
	int	accuracy;
}				t_params;

int			is_convs(char c);
int			push(t_params *params, char *str, int w, long int content);
int			get_width(char *str, va_list m);
int			get_accuracy(char *str, va_list m);
int			find_flag(char c, char *params);
char		*itoa_base_low(unsigned long int n, int base, char *res, int ac);
char		*itoa_base_up(unsigned long int n, int base, char *res, int ac);
int			len_base(long long int n, int base);
void		str_move(char *str, char *content);
void		str_n_move(char *str, char *content, int l);
void		fill_field(char *s, t_params *params, int w);
void		clear_params(t_params *s);
t_params	*gen_params(char *params, va_list m);
int			len_ptr(unsigned long int n, int base);
int			ft_strlen(const char *str);
int			ft_atoi(const char *s);
char		*ft_substr(char const *s, unsigned int start, unsigned int len);
void		ft_putstr_fd(char *s, int fd, int l);
int			print_int(char *p, va_list m);
int			print_hex(char *p, va_list m);
int			print_uph(char *p, va_list m);
int			print_ptr(char *p, va_list m);
int			print_unt(char *p, va_list m);
int			print_str(char *p, va_list m);
int			print_chr(char *p, va_list m);
int			print_prc(char *p, va_list m);
int			ft_printf(const char *str, ...);

#endif
