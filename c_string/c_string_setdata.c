#include "c_string.h"

void __c_string_constructor_setdata(t_c_string* str)
{
    str->setdata = c_string_setdata;
    str->tie_static_array = c_string_tie_static_array;
}

void  c_string_setdata(t_c_string* str, char* arr, int size, int length)
{
    str->m_static_array = arr;
    str->m_size = size;
    str->m_static_capacity = length;
    if (str->m_size > 1)
	if (str->m_static_array[str->m_size - 1] == '\0')
	    str->pop_back(str);
}

void  c_string_tie_static_array(t_c_string* str, char* arr, int length)
{
    int index;

    str->setdata(str, arr, 0, length);


    if (str->is_dynamic_memory_null(str))
    {
		return;
    }
    index = -1;
    while (++index < str->m_size && index < length)
    {
		str->m_static_array[index] = str->m_dynamic_array[index];
    }
    if (length >= str->m_size)
    {
		if (str->m_dynamic_array != NULL)
			free(str->m_dynamic_array);
		return;
    }
    index = - 1;
    while (index < str->m_size)
    {
		str->m_dynamic_array[index] = str->m_dynamic_array[index + length];
    }
}