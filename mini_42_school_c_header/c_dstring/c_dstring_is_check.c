#include "c_dstring.h"

void __c_dstring_constructor_is_check(t_c_dstring* str)
{
    str->is_alpha = c_dstring_is_alpha;
    str->is_digit = c_dstring_is_digit;
    str->is_alnum = c_dstring_is_alnum;
    str->is_print = c_dstring_is_print;
}

bool c_dstring_is_alpha(t_c_dstring* str)
{
    int index;

    index = 0;
    while (index != str->m_size)
    {
	if (!ft_isalpha(str->m_array[index]))
	    return (false);
	++index;
    }
    return (true);
}
bool c_dstring_is_digit(t_c_dstring* str)
{
    int index;

    index = 0;
    while (index != str->m_size)
    {
	if (!ft_isdigit(str->m_array[index]))
	    return (false);
	++index;
    }
    return (true);
}
bool c_dstring_is_alnum(t_c_dstring* str)
{
    int index;

    index = 0;
    while (index != str->m_size)
    {
	if (!ft_isalnum(str->m_array[index]))
	    return (false);
	++index;
    }
    return (true);
}
bool c_dstring_is_print(t_c_dstring* str)
{
    int index;

    index = 0;
    while (index != str->m_size)
    {
	if (!ft_isprint(str->m_array[index]))
	    return (false);
	++index;
    }
    return (true);
}