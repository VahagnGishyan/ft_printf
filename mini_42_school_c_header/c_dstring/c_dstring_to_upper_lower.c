#include "c_dstring.h"

void __c_dstring_constructor_to_upper_lower(t_c_dstring* str)
{
    str->to_upper_chararray = c_dstring_to_upper_chararray;
    str->to_upper_c_dstring = c_dstring_to_upper_c_dstring;
    str->to_lower_chararray = c_dstring_to_lower_chararray;
    str->to_lower_c_dstring = c_dstring_to_lower_c_dstring;
}

void c_dstring_to_upper_chararray(t_c_dstring* str, char* arr)
{
    int index;

    index = 0;
    while (index != str->m_size)
    {
	arr[index] = ft_toupper(str->m_array[index]);
	++index;
    }
    arr[index] = '\0';
}
void c_dstring_to_upper_c_dstring(t_c_dstring* str_main, t_c_dstring* str_other)
{
    int index;

    index = 0;
    while (index != str_main->m_size)
    {
	*str_other->at(str_other, index) = ft_toupper(str_main->m_array[index]);
	++index;
    }
}
void c_dstring_to_lower_chararray(t_c_dstring* str, char* arr)
{
    int index;

    index = 0;
    while (index != str->m_size)
    {
	arr[index] = ft_tolower(str->m_array[index]);
	++index;
    }
    arr[index] = '\0';
}
void c_dstring_to_lower_c_dstring(t_c_dstring* str_main, t_c_dstring* str_other)
{
    int index;

    index = 0;
    while (index != str_main->m_size)
    {
	*str_other->at(str_other, index) = ft_tolower(str_main->m_array[index]);
	++index;
    }
}