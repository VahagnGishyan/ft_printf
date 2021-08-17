#include "c_vector_string.h"

void c_vector_string_tie_static_array(t_c_vector_string* obj, t_c_string* data, int capacity)
{
    obj->m_static_data = data;
    obj->m_size = 0;
    obj->m_static_capacity = capacity;
}

void c_vector_string_set_data(t_c_vector_string* obj, t_c_string* data, int size, int capacity)
{
    obj->m_static_data = data;
    obj->m_size = size;
    obj->m_static_capacity = capacity;
}

//void c_vector_string_set_data(t_c_vector_string* obj, t_c_string* data, int size, int capacity)
//{
//    int index;
//
//    if (!obj->resize(obj, size))
//	return;
//    index = -1;
//    while (++index < size)
//	c_string_copy_c_string(obj->m_data + index, data + index);
//    obj->m_size = size;
//}