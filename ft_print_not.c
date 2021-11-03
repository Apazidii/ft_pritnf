#include "head.h"

int print_not(char *params)
{
	write(1, "%", 1);
    ft_putstr_fd(params, 1);
    return (ft_strlen(params) + 1);
}