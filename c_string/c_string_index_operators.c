#include "c_string.h"

void __c_string_constructor_index_operators(t_c_string* str)
{
    str->at = c_string_at;
    str->front = c_string_front;
    str->back = c_string_back;
}

char* c_string_at(t_c_string* str, int index)
{
    if (index < str->m_static_capacity)
	return (&str->m_static_array[index]);
    return(&str->m_dynamic_array[index - str->m_static_capacity]);
}
char* c_string_front(t_c_string* str)
{
    if (c_string_is_null(str))
	return (NULL);
    if (!c_string_is_static_memory_null(str))
	return (&str->m_static_array[0]);
    if (!c_string_is_dynamic_memory_null(str))
	return (&str->m_dynamic_array[0]);
    return (NULL);
}
char* c_string_back(t_c_string* str)
{
    if (c_string_is_null(str))
	return (NULL);
    if (c_string_is_dynamic_memory_null(str))
	return (&str->m_static_array[str->m_size - 1]);
    return (&str->m_dynamic_array[str->m_size - 1]);
}