#include "head.h"

int	print_prc(char *p, va_list m)
{
	(void)p;
	(void)m;
	write(1, "%", 1);
	return (1);
}
