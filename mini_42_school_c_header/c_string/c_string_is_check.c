#include "c_string.h"

void __c_string_constructor_is_check(t_c_string* str)
{
    str->is_alpha = c_string_is_alpha;
    str->is_digit = c_string_is_digit;
    str->is_alnum = c_string_is_alnum;
    str->is_print = c_string_is_print;
}

bool c_string_is_alpha(t_c_string* str)
{
    int index;

    index = -1;
    while (++index != str->m_size)
	if (!ft_isalpha(*(str->at(str, index))))
	    return (false);
    return (true);
}
bool c_string_is_digit(t_c_string* str)
{
    int index;

    index = -1;
    while (++index != str->m_size)
	if (!ft_isdigit(*(str->at(str, index))))
	    return (false);
    return (true);
}
bool c_string_is_alnum(t_c_string* str)
{
    int index;

    index = -1;
    while (++index != str->m_size)
	if (!ft_isalnum(*(str->at(str, index))))
	    return (false);
    return (true);
}
bool c_string_is_print(t_c_string* str)
{
    int index;

    index = -1;
    while (++index != str->m_size)
	if (!ft_isprint(*(str->at(str, index))))
	    return (false);
    return (true);
}