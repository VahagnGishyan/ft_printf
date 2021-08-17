#include "c_dstring.h"

void __c_dstring_constructor_search(t_c_dstring* str)
{
    str->search_char = c_dstring_search_char;
    str->search_chararray = c_dstring_search_chararray;
    str->search_c_dstring = c_dstring_search_c_dstring;
}

char* c_dstring_search_char(t_c_dstring* str, char symbol)
{
    return (ft_strchr(str->m_array, symbol));
}
char* c_dstring_search_chararray(t_c_dstring* str, char* arr, int size)
{
    return (ft_strnstr(str->m_array, arr, size));
}
char* c_dstring_search_c_dstring(t_c_dstring* str_main, t_c_dstring* str_other)
{
    return (ft_strnstr(str_main->m_array, str_other->m_array, str_other->m_size));
}