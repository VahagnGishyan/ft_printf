#include "c_string.h"

void __c_string_constructor_is_check_memory(t_c_string* str)
{
    str->is_static_memory_null = c_string_is_static_memory_null;
    str->is_dynamic_memory_null = c_string_is_dynamic_memory_null;
    str->is_null = c_string_is_null;
    str->is_used_dynamic_memory = c_string_is_used_dynamic_memory;
}

bool  c_string_is_static_memory_null(t_c_string* str)
{
    return (str->m_static_array == NULL);
}
bool  c_string_is_dynamic_memory_null(t_c_string* str)
{
    return (str->m_dynamic_array == NULL);
}
bool  c_string_is_null(t_c_string* str)
{
    return ((str->m_static_array == NULL) && (str->m_dynamic_array == NULL));
}
bool  c_string_is_used_dynamic_memory(t_c_string* str)
{
    return (!(str->is_dynamic_memory_null(str))
	&& str->m_dynamic_capacity
	&& (str->m_size > str->m_static_capacity));
}
