#ifndef HEAD_H
# define HEAD_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <math.h>


//tools
int		is_convs(char c);
int		get_width(char *str);
int		get_accuracy(char *str);
int		find_flag(char c, char *params);
char	*itoa_base(unsigned long int n, int base, char *res, int upper, int ac);
int		len_base(long long int n, int base);
void	str_move(char *str, char *content);
void 	fill_field(char *s, char *params, int w);


//libft
int		ft_strlen(const char *str);
int		ft_atoi(const char *s);
char	*ft_substr(char const *s, unsigned int start, unsigned int len);
void	ft_putstr_fd(char *s, int fd);


//prints
int print_int(char *params, int content);
int print_chr(char *params, unsigned char content);
int print_str(char *params, char *content);
int print_ptr(char *params, unsigned long int content);
int print_hex(char *params, unsigned int content);
int print_HEX(char *params, unsigned int content);
int print_prc();
int print_unt(char *params, unsigned int content);
int print_not(char *params);

int	ft_printf(const char *str, ...);

#endif