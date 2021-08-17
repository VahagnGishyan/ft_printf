#include "c_vector_string.h"

t_c_string* c_vector_string_search_string(t_c_vector_string* data, t_c_string* obj)
{
    int index;

    index = -1;
    while (++index < c_vector_string_size(data))
	if (!c_string_compare_c_string(c_vector_string_at(data, index), obj))
	    return (c_vector_string_at(data, index));
    return (NULL);
}

int   c_vector_string_search_string_index(t_c_vector_string* data, t_c_string* obj)
{
    int index;

    index = -1;
    while (++index < c_vector_string_size(data))
	if (!c_string_compare_c_string(c_vector_string_at(data, index), obj))
	    return (index);
    return (-1);
}
