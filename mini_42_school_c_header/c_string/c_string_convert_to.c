#include "c_string.h"

void __c_string_constructor_convert_to(t_c_string* str)
{
    str->convert_to_int = c_string_convert_to_int;
    str->convert_to_chararray = c_string_convert_to_chararray;
    str->convert_to_dstring = c_string_convert_to_dstring;
}

void c_string_convert_to_int(t_c_string* str, int* value)
{
    if (!c_string_is_used_dynamic_memory(str))
    {
	*value = ft_atoi(str->m_static_array);
	return ;
    }

    t_c_dstring d_str;
    c_dstring_constructor(&d_str);
    
    c_string_convert_to_dstring(str, &d_str);
    d_str.convert_to_int(&d_str, value);
    
    c_dstring_destructor(&d_str);
}

void c_string_convert_to_chararray(t_c_string* str, char* arr)
{
    int index;
    t_c_dstring d_str;

    if (!c_string_is_used_dynamic_memory(str))
    {
	index = -1;
	while (++index < str->m_size)
	{
	    arr[index] = str->m_static_array[index];
	}
	arr[index] = '\0';
	return;
    }
    c_dstring_constructor(&d_str);
    c_string_convert_to_dstring(str, &d_str);
    d_str.convert_to_chararray(&d_str, arr);
    c_dstring_destructor(&d_str);
}

void  c_string_convert_to_dstring(t_c_string* str_main, void* str_other_ptr)
{
    int index;
    t_c_dstring* str_other;
    
    str_other = str_other_ptr;
    if (!str_main || !str_other_ptr)
	return;
    if (!str_main->m_size)
	return;
    if (!str_other->resize(str_other, str_main->m_size))
	return;
    index = -1;
    while (++index < str_main->m_size)
	*str_other->at(str_other, index) = *str_main->at(str_main, index);
    str_other->m_size = str_main->m_size;
}