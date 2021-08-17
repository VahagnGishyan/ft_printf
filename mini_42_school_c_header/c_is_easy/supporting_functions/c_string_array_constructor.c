#include "supporting_functions.h"

void c_string_array_constructor(t_c_string* strs, int size)
{
    for (int index = 0; index < size; ++index)
	c_string_constructor(strs + index);
}