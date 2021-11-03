#include "head.h"

int print_str(char *params, char *content)
{
    int w;
    int l;
    char *str;
  
    l = ft_strlen(content);
    w = get_width(params);
    if (w < l)
        w = l;
    str = (char *)malloc(sizeof(char) * w + 1);
    str[w] = '\0';
    fill_field(str, "", w);
	if (find_flag('-', params))
        str_move(str, content);
    else
		str_move(str + w - l, content);
	ft_putstr_fd(str, 1);
	// free(str);
    return (ft_strlen(str));
}