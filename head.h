#ifndef HEAD_H
# define HEAD_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <math.h>

typedef struct	s_params
{
	int	min;
	int	plus;
	int	space;
	int	hash;
	int	zero;
	int	width;
	int	accuracy;
}				t_params;

//tools
int		is_convs(char c);
int		is_format(char *s);

int		get_width(char *str, va_list m);
int		get_accuracy(char *str, va_list m);

int			find_flag(char c, char *params);
char		*itoa_base_low(unsigned long int n, int base, char *res, int ac);
char		*itoa_base_up(unsigned long int n, int base, char *res, int ac);
int			len_base(long long int n, int base);
void		str_move(char *str, char *content);
void		str_n_move(char *str, char *content, int l);
void		fill_field(char *s, t_params *params, int w);
void		clear_params(t_params *s);
t_params	*gen_params(char *params, va_list m);


char *str_add(char *s1, char *s2, int l1, int l2);
char *strr(int k, char *s);

//libft
int		ft_strlen(const char *str);
int		ft_atoi(const char *s);
char	*ft_substr(char const *s, unsigned int start, unsigned int len);
void	ft_putstr_fd(char *s, int fd, int l);


//prints
int print_int(char *p, va_list m);
int	print_hex(char *p, va_list m);
int	print_uph(char *p, va_list m);
int	print_ptr(char *p, va_list m);
int	print_unt(char *p, va_list m);
int	print_str(char *p, va_list m);
int	print_chr(char *p, va_list m);
int	print_prc(char *p, va_list m);
// int print_prc();
// int print_not(char *params);

int	ft_printf(const char *str, ...);

#endif