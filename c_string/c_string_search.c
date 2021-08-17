#include "c_string.h"

void __c_string_constructor_search(t_c_string* str)
{
    str->search_char = c_string_search_char;
    str->search_chararray = c_string_search_chararray;
    str->search_c_string = c_string_search_c_string;
}

char* c_string_search_char(t_c_string* str, char symbol)
{
    int index;

    index = -1;
    while (++index < str->m_size)
    {
	if (*c_string_at(str, index) == symbol)
	    return (c_string_at(str, index));
    }
    return (NULL);
}
char* c_string_search_chararray(t_c_string* str, char* arr, int size)
{
    int start;
    int index;

    start = -1;
    index = 0;
    while (++start < str->m_size)
    {
	if (*c_string_at(str, start) == arr[index])
	{
	    ++index;
	    while (*c_string_at(str, start + index) == arr[index] && (start + index) < str->m_size && index < size)
	    {
		++index;
	    }
	    if (index == size)
		return(c_string_at(str, start));
	    index = 0;
	}
    }
    return (NULL);
}
char* c_string_search_c_string(t_c_string* str_main, t_c_string* str_other)
{
    int start;
    int index;

    start = -1;
    index = 0;
    while (++start < str_main->m_size)
    {
	if (*c_string_at(str_main, start) == *c_string_at(str_other, index))
	{
	    ++index;
	    while (*c_string_at(str_main, start + index) == *c_string_at(str_other, index) 
		&& (start + index) < str_main->m_size && index < str_other->m_size)
	    {
		++index;
	    }
	    if (index == str_other->m_size)
		return(c_string_at(str_main, start));
	    index = 0;
	}
    }
    return (NULL);
}