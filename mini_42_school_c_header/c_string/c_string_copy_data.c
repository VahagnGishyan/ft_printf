#include "c_string.h"

void __c_string_constructor_copy_data(t_c_string* str)
{
    str->copy_chararray = c_string_copy_chararray;
    str->copy_c_string = c_string_copy_c_string;
    str->copy_c_dstring = c_string_copy_c_dstring;
}

void c_string_copy_chararray(t_c_string* str, const char* arr, int size)
{
    int index;

    index = -1;
    c_string_resize(str, size);
    while (++index < size)
	*str->at(str, index) = arr[index];
    str->m_size = size;
}

void c_string_copy_c_string(t_c_string* str_main, t_c_string* str_other)
{
    int index;

    index = -1;
    c_string_resize(str_main, str_other->m_size);
    while (++index < str_other->m_size)
	*str_main->at(str_main, index) = *str_other->at(str_other, index);
    str_main->m_size = str_other->m_size;
}

void  c_string_copy_c_dstring(t_c_string* str_main, void* str_other_ptr)
{
    int index;
    t_c_dstring* str_other;

    str_other = str_other_ptr;
    index = -1;
    c_string_resize(str_main, str_other->m_size);
    while (++index < str_other->m_size)
	*str_main->at(str_main, index) = *str_other->at(str_other, index);
    str_main->m_size = str_other->m_size;
}