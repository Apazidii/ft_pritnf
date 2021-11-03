#include "head.h"

void apply_flag_ptr(char *res, char *params, int ind)
{
	char	c;

	c = 0;
	if (find_flag('0', params) || find_flag('-', params))
		ind = 0;
	if (find_flag('+', params))
		c = '+';
	else if (find_flag(' ', params))
		c = ' ';
	
	if (c != 0)
	{
		res[ind] = c;
		str_move(&res[ind + 1], "0x");
	}
	else
		str_move(&res[ind], "0x");

	
}

int print_ptr(char *params, unsigned long int content)
{
    int w;
    int l;
    char *str;
  
    l = len_base(content, 16) + 2;
    if ((find_flag('+', params) || find_flag(' ', params)) && content > 0)
        l++;
    w = get_width(params);
    if (w < l)
        w = l;
    str = (char *)malloc(sizeof(char) * w + 1);
    str[w] = '\0';
    fill_field(str, params, w);
    apply_flag_ptr(str, params, w - l);
	if (find_flag('-', params))
        itoa_base(content, 16, str + l - 1, 0, 0);
    else
		itoa_base(content, 16, str + w - 1, 0, 0);
	ft_putstr_fd(str, 1);
    return (ft_strlen(str));
}
