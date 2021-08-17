#include "c_dstring.h"

void __c_dstring_constructor_get_free_dymemory(t_c_dstring* str)
{
    str->resize = c_dstring_resize;
    str->clear = c_dstring_clear;
}

bool get_dymemory(char** ptr, int size)
{
    ptr[0] = (char*)malloc(size);
    return(ptr == NULL);
}

bool c_dstring_resize(t_c_dstring* str, int length)
{
    char* newstring;
    int size;

    if (str->m_capacity >= length)
	return true;
    newstring = NULL;
    if (get_dymemory(&newstring, length))
	return false;
    ft_strlcpy(newstring, str->m_array, str->m_size);
    size = str->m_size;
    str->clear(str);
    str->m_array = newstring;
    str->m_size = size;
    str->m_capacity = length;
    return true;
}

void c_dstring_clear(t_c_dstring* str)
{
    if (c_dstring_is_null(str))
	return;
    free(str->m_array);
    str->m_array = NULL;
    str->m_size = 0;
    str->m_capacity = 0;
}

