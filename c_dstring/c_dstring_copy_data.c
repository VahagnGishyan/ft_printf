#include "c_dstring.h"

void __c_dstring_constructor_copy_data(t_c_dstring* str)
{
    str->copy_chararray = c_dstring_copy_chararray;
    str->copy_c_dstring = c_dstring_copy_c_dstring;
}

void c_dstring_copy_chararray(t_c_dstring* str, char* arr, int size)
{
    if (str->m_capacity <= size)
	str->resize(str, (int)(size * 1.3));
    ft_strlcpy(str->m_array, arr, size);
    str->m_size = size;
}
void c_dstring_copy_c_dstring(t_c_dstring* str_main, t_c_dstring* str_other)
{
    if (str_main->m_capacity <= str_other->m_size)
	str_main->resize(str_main, (int)(str_other->m_size * 1.3));
    ft_strlcpy(str_main->m_array, str_other->m_array, str_other->m_size);
    str_main->m_size = str_other->m_size;
}
