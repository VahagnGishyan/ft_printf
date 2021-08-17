#include "c_dstring.h"

void __c_dstring_constructor_concatenation(t_c_dstring* str)
{
    str->concatenation_chararray = c_dstring_concatenation_chararray;
    str->concatenation_c_dstring = c_dstring_concatenation_c_dstring;
}

void c_dstring_concatenation_chararray(t_c_dstring* str, const char* arr, int size)
{
    int index;

    if (str->m_capacity <= size + str->m_size)
		str->resize(str, (int)((size + str->m_size) * 1.3));
    index = 0;
    while (index != size && arr[index] != '\0')
    {
		str->push_back(str, arr[index]);
		++index;
    }
}
void c_dstring_concatenation_c_dstring(t_c_dstring* str_main, t_c_dstring* str_other)
{
    int index;

    if (str_main->m_capacity <= str_other->m_size + str_main->m_size)
	str_main->resize(str_main, (int)((str_other->m_size + str_main->m_size) * 1.3));
    index = 0;
    while (index != str_other->m_size && (*str_other->at(str_other, index) != '\0'))
    {
	str_main->push_back(str_main, *str_other->at(str_other, index));
	++index;
    }
}
