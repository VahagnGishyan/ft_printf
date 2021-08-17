#include "c_string.h"

void __c_string_constructor_get_free_dymemory(t_c_string* str)
{
    str->resize = c_string_resize;
    str->clear = c_string_clear;
}

bool c_string_resize(t_c_string* str, int length)
{
    char* newstring;
    int size;

    if (str->m_static_capacity >= length || length <= 0)
	return true;
    newstring = NULL;
    if ((newstring = (char*)malloc((size_t)(length - str->m_static_capacity)*1.3)) == NULL)
	return false;
    ft_strlcpy(newstring, str->m_dynamic_array, str->m_size);
    size = str->m_size;
    str->clear(str);
    str->m_dynamic_array = newstring;
    str->m_size = size;
    str->m_dynamic_capacity = (size_t)(length - str->m_static_capacity) * 1.3;
    return true;
}

void c_string_clear(t_c_string* str)
{
    str->m_size = 0;
    if (str->is_dynamic_memory_null(str))
	return;
    free(str->m_dynamic_array);
    str->m_dynamic_array = NULL;
    str->m_dynamic_capacity = 0;
}

