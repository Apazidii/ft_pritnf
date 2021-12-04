#include "head.h"

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

char *str_add(char *s1, char *s2, int l1, int l2)
{
	char	*res;
	int		i;
	int		ii;

	res = (char *)malloc(sizeof(char) * (l1 + l2 + 1));
	res[l1 + l2] = 0;
	i = 0;
	while (s1 != 0 && i < l1)
	{
		res[i] = s1[i];
		i++;
	}
	ii = 0;
	while (ii < l2)
	{
		res[i + ii] = s2[ii];
		ii++;
	}
	free(s1);
	free(s2);
	return (res);
}

char *strr(int k, char *s)
{
  char *res;
  int   i;
  
  res = (char *)malloc(sizeof(char) * (k + 1));
  res[k]  = 0;
  i = 0;
  while (i < k)
  {
    res[i] = s[i];
    i++;
  }
  return (res);
}