#include "ft_printf.h"

int pf_mmesslen(t_c_vector_string* message)
{
    int index;
    int	l_length;
    int	s_length;

    index = -1;
    l_length = c_vector_string_size(message);
    s_length = 0;
    while (++index < l_length)
	s_length += (c_string_size
	(c_vector_string_at(message, index)));
    return (s_length);
}