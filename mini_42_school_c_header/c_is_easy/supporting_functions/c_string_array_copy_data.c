#include "supporting_functions.h"

void c_string_array_copy_c_string_array(t_c_string* str_main, t_c_string* str_other, int size)
{
    int index;
    
    index = -1;
    while (++index < size)
	c_string_copy_c_string(str_main + index, str_other + index);
}