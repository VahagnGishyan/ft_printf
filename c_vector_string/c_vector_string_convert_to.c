#include "c_vector_string.h"

void  c_vector_string_convert_to_string_array(t_c_vector_string* data, t_c_string* arrstring)
{
    int index;

    index = -1;
    while (++index < c_vector_string_size(data))
	c_string_copy_c_string(arrstring + index, c_vector_string_at(data, index));
}