#include "c_dstring.h"

void __c_dstring_constructor_array_size(t_c_dstring* str)
{
    str->size = c_dstring_size;
    str->capacity = c_dstring_capacity;
    str->is_empty = c_dstring_is_empty;
    str->is_null = c_dstring_is_null;
}

int c_dstring_size(t_c_dstring* str)
{
    return (str->m_size);
}
int c_dstring_capacity(t_c_dstring* str)
{
    return (str->m_capacity);
}
bool c_dstring_is_empty(t_c_dstring* str)
{
    return (str->m_size == 0);
}
bool c_dstring_is_null(t_c_dstring* str)
{
    return (str->m_array == NULL);
}