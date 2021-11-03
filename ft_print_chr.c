#include "head.h"

int print_chr(char *params, unsigned char content)
{
    int w;
    int l;
    char *str;
  
    l = 1;
    w = get_width(params);
    if (w < l)
        w = l;
    str = (char *)malloc(sizeof(char) * w + 1);
    str[w] = '\0';
    fill_field(str, "", w);
	if (find_flag('-', params))
		str[0] = content;
    else
		str[w -1] = content;
	ft_putstr_fd(str, 1);
	free(str);
    return (ft_strlen(str));
}