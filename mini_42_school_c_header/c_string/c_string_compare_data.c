#include "c_string.h"

void __c_string_constructor_compare_data(t_c_string* str)
{
    str->compare_chararray = c_string_compare_chararray;
    str->compare_c_string = c_string_compare_c_string;
}

int c_string_compare_chararray(t_c_string* str, char* arr, int size)
{
    int result;
    t_c_dstring d_str;

    c_dstring_constructor(&d_str);
    if (!c_string_is_used_dynamic_memory(str) || (str->m_size + size) < str->m_static_capacity)
    {
	return(ft_strncmp(str->m_static_array, arr, size));
    }
    c_string_convert_to_dstring(str, &d_str);
    result = d_str.compare_chararray(&d_str, arr, size);
    c_string_copy_c_dstring(str, &d_str);
    c_dstring_destructor(&d_str);
    return(result);
}
int c_string_compare_c_string(t_c_string* str_main, t_c_string* str_other)
{
    int result;
    t_c_dstring d_str_main;
    t_c_dstring d_str_other;

    c_dstring_constructor(&d_str_main);
    c_dstring_constructor(&d_str_other);
    c_string_convert_to_dstring(str_main, &d_str_main);
    c_string_convert_to_dstring(str_other, &d_str_other);
    result = d_str_main.compare_c_dstring(&d_str_main, &d_str_other);
    d_str_other.clear(&d_str_other);
    c_dstring_destructor(&d_str_other);
    c_dstring_destructor(&d_str_main);
    return(result);
}