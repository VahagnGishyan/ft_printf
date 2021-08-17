#include "ft_printf.h"

bool	pf_is_valid_char(char c)
{
    return (ft_isalnum(c) || c == '_' || ce_isspace(c));
}

int	pf_is_valid_type(int c)
{
    return ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd') || (c == 'i')
	|| (c == 'u') || (c == 'x') || (c == 'X') || (c == '%'));
}

int	pf_get_message_count(const char* formath)
{
    int	    count;
    char    *ptr;

    count = 1;
    ptr = ft_strchr((char*)(formath), '%');
    while (ptr)
    {
	count += 2;
	ptr = ft_strchr(ptr + 1, '%');
    }
    return (count);
}