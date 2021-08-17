#include "c_dstring.h"

void __c_dstring_constructor_index_operators(t_c_dstring* str)
{
    str->at = c_dstring_at;
    str->front = c_dstring_front;
    str->back = c_dstring_back;
}

char* c_dstring_at(t_c_dstring* str, int index)
{
    return (&str->m_array[index]);
}
char* c_dstring_front(t_c_dstring* str)
{
    return (&str->m_array[0]);
}
char* c_dstring_back(t_c_dstring* str)
{
    return (&str->m_array[str->m_size - 1]);
}