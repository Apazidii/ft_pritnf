#include "head.h"

void apply_flag_hex(char *res, char *params, int ind)
{
	if (find_flag('0', params) || find_flag('-', params))
		ind = 0;
	if (find_flag('#', params))
		str_move(&res[ind], "0x");
}

int print_hex(char *params, unsigned int content)
{
    int w;
    int l;
    char *str;
	
    l = len_base(content, 16);
	if (find_flag('#', params))
		l = l + 2;
    w = get_width(params);
    if (w < l)
        w = l;
    str = (char *)malloc(sizeof(char) * w + 1);
    str[w] = '\0';
    fill_field(str, params, w);
    apply_flag_hex(str, params, w - l);
	if (find_flag('-', params))
        itoa_base(content, 16, str + l - 1, 0, 0);
    else
		itoa_base(content, 16, str + w - 1, 0, 0);
	ft_putstr_fd(str, 1);
    return (ft_strlen(str));
}
