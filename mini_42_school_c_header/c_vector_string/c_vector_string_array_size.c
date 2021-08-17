#include "c_vector_string.h"

int  c_vector_string_size(t_c_vector_string* obj)
{
    return(obj->m_size);
}
int  c_vector_string_static_capacity(t_c_vector_string* obj)
{
    return(obj->m_static_capacity);
}
int  c_vector_string_dynamic_capacity(t_c_vector_string* obj)
{
    return(obj->m_dynamic_capacity);
}
int  c_vector_string_capacity(t_c_vector_string* obj)
{
    return(obj->m_static_capacity + obj->m_dynamic_capacity);
}
bool c_vector_string_is_empty(t_c_vector_string* obj)
{
    return(obj->m_size == 0);
}