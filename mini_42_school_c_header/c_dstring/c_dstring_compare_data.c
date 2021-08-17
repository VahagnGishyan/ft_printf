#include "c_dstring.h"

void __c_dstring_constructor_compare_data(t_c_dstring* str)
{
    str->compare_chararray = c_dstring_compare_chararray;
    str->compare_c_dstring = c_dstring_compare_c_dstring;
}

int imax(int a, int b)
{
	if(a > b)
		return (a);
	return (b);
}

int c_dstring_compare_chararray(t_c_dstring* str, char* arr, int size)
{
    return(ft_strncmp(str->m_array, arr, size));
}
int c_dstring_compare_c_dstring(t_c_dstring* str_main, t_c_dstring* str_other)
{
    return(ft_strncmp(str_main->m_array, str_other->m_array, imax(str_main->m_size, str_other->m_size)));
}