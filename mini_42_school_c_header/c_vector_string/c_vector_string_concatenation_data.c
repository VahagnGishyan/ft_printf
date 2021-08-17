#include "c_vector_string.h"

void c_vector_string_concatenation_string_array(t_c_vector_string* obj, t_c_string* arr, int size)
{
    int index;

    if (!c_vector_string_reserve(obj, c_vector_string_size(obj) + size))
	return;
    index = -1;
    while (++index < size)
	c_string_copy_c_string(c_vector_string_at(obj, index + obj->m_size), arr + index);
    obj->m_size += size;
}
void c_vector_string_concatenation_c_vector_string(t_c_vector_string* obj, t_c_vector_string* arrint)
{
    int index;

    if (!c_vector_string_reserve(obj, c_vector_string_size(obj) + c_vector_string_size(arrint)))
	return;
    index = -1;
    while (++index < c_vector_string_size(arrint))
	c_string_copy_c_string(c_vector_string_at(obj, index + obj->m_size), c_vector_string_at(arrint, index));
    obj->m_size += arrint->m_size;
}