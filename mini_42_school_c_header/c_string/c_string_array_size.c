#include "c_string.h"

void __c_string_constructor_array_size(t_c_string* str)
{
    str->size = c_string_size;
    str->capacity = c_string_capacity;
    str->is_empty = c_string_is_empty;
}

int c_string_size(t_c_string* str)
{
    return (str->m_size);
}
int c_string_capacity(t_c_string* str)
{
    return (str->m_static_capacity + str->m_dynamic_capacity);
}
bool c_string_is_empty(t_c_string * str)
{
    return (str->m_size == 0);
}