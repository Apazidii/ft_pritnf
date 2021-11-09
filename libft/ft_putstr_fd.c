#include "../head.h"

void	ft_putstr_fd(char *s, int fd, int l)
{
	int	i;

	if (s)
	{
		i = 0;
		while (i < l)
		{
			write(fd, s, 1);
			s++;
			i++;
		}
	}
}
