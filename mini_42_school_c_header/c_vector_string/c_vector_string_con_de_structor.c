#include "c_vector_string.h"

void c_vector_string_constructor(t_c_vector_string* obj)
{
    obj->m_size = 0;
    obj->m_static_data = 0;
    obj->m_static_capacity = 0;
    obj->m_dynamic_data = 0;
    obj->m_dynamic_capacity = 0;
}
void c_vector_string_destructor(t_c_vector_string* obj)
{
    c_vector_string_clear(obj);
}