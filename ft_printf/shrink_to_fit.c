#include "ft_printf.h"

void	pf_shrink_to_fit(t_c_vector_string* message)
{
    while (c_string_is_empty(c_vector_string_back(message)))
	c_vector_string_pop_back(message);
}
