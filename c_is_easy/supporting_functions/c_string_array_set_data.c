#include "supporting_functions.h"

void c_string_array_set_char_array(t_c_string* strs, int strs_size, const char* arr, int arr_size)
{
    for (int index = 0; index < strs_size; ++index)
	c_string_copy_chararray(strs + index, arr, arr_size);
}

void c_string_array_set_c_string(t_c_string* strs, int strs_size, t_c_string* str)
{
    for (int index = 0; index < strs_size; ++index)
	c_string_copy_c_string(strs + index, str);
}

