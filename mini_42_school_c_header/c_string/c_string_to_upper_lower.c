#include "c_string.h"

void __c_string_constructor_to_upper_lower(t_c_string* str)
{
    str->to_upper_chararray = c_string_to_upper_chararray;
    str->to_upper_c_string = c_string_to_upper_c_string;
    str->to_lower_chararray = c_string_to_lower_chararray;
    str->to_lower_c_string = c_string_to_lower_c_string;
}

void c_string_to_upper_chararray(t_c_string* str, char* arr)
{
    int index;

    index = -1;
    while (++index != str->m_size)
	arr[index] = ft_toupper(*str->at(str, index));
    arr[index] = '\0';
}
void c_string_to_upper_c_string(t_c_string* str_main, t_c_string* str_other)
{
    int index;

    index = -1;
    while (++index != str_main->m_size)
	*str_other->at(str_other, index) = ft_toupper(*str_main->at(str_main, index));
}
void c_string_to_lower_chararray(t_c_string* str, char* arr)
{
    int index;

    index = -1;
    while (++index != str->m_size)
	arr[index] = ft_tolower(*str->at(str, index));
    arr[index] = '\0';
}
void c_string_to_lower_c_string(t_c_string* str_main, t_c_string* str_other)
{
    int index;

    index = -1;
    while (++index != str_main->m_size)
	*str_other->at(str_other, index) = ft_tolower(*str_main->at(str_main, index));
}