#include "c_vector_string.h"

void c_vector_string_copy_string_array(t_c_vector_string* obj, t_c_string* arr, int size)
{
    int index;

    c_vector_string_clear(obj);
    if (!c_vector_string_reserve(obj, size))
	return;
    index = -1;
    while (++index < size)
	c_vector_string_push_back(obj, arr + index);
}
void c_vector_string_copy_c_vector_string(t_c_vector_string* obj, t_c_vector_string* arrstring)
{
    int index;

    c_vector_string_clear(obj);
    if (!c_vector_string_reserve(obj, arrstring->m_size))
	return;
    index = -1;
    while (++index < c_vector_string_size(arrstring))
	c_vector_string_push_back(obj, c_vector_string_at(arrstring, index));
}