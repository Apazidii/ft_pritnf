#include "head.h"





// void apply_flag_unt(char *res, char *params, unsigned int *content, int ind)
// {
// 	char	c;

// 	c = 0;
// 	if (find_flag('0', params) || find_flag('-', params))
// 		ind = 0;
// 	if (*content < 0)
// 	{
// 		c = '-';
// 		*content = *content * -1;
// 	}
// 	else if (find_flag('+', params))
// 		c = '+';
// 	else if (find_flag(' ', params))
// 		c = ' ';
	
// 	if (c != 0)
// 		res[ind] = c;
// }

int print_unt(char *params, unsigned int content)
{
    int w;
    int l;
    char *str;
  
    l = len_base(content, 10);
    w = get_width(params);
    if (w < l)
        w = l;
    str = (char *)malloc(sizeof(char) * w + 1);
    str[w] = '\0';
    fill_field(str, params, w);
    // apply_flag_unt(str, params, &content, w - l);
	if (find_flag('-', params))
        itoa_base(content, 10, str + l - 1, 0, 0);
    else
		itoa_base(content, 10, str + w - 1, 0, 0);
	ft_putstr_fd(str, 1);
    return (ft_strlen(str));
}
