#ifndef HEAD_H
# define HEAD_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <math.h>

typedef	struct	s_prarg
{
	char	type;
	char	*params;
	void	*content;
}				t_prarg;

//libft
char	*ft_substr(char const *s, unsigned int start, unsigned int len);
int		ft_strlen(const char *str);
int		ft_atoi(const char *s);


//tools
int		is_convs(char c);
int		len_int(long long int n);
int		find_flag(char c, char *params);
int		fill_c(char c, int k);

//params
int	get_width(char *str);

//ft_put
int	ft_putnbr_base(int n, int base, int low);
int	ft_putstr_l(char *s, int fd);
int	ft_putullint_base(unsigned long long int n, int base, int low);
int	ft_putuint_base(unsigned int n, int base, int low);
int	ft_putllint_base(long long int n, int base, int low);

//prints
int	print_char(char *params, char content);			//%c
int	print_string(char *params, char *content);		//%s
int	print_pointer(char *params, unsigned long long int content);		//%p
int	print_int(char *params, int content); 			//%i %d
int	print_uint(char *params, unsigned int content);
int	print_hexadecimal(char *params, long long int content);
int	print_Hexadecimal(char *params, long long int content);
int	print_procent(char *params);	//%X
int			ft_atoi(const char *s);

//res
int	ft_printf(const char *str, ...);

#endif