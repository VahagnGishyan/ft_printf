#include "c_string.h"

void __c_string_constructor_push_pop(t_c_string* str)
{
    str->push_back = c_string_push_back;
    str->pop_back = c_string_pop_back;
}

void c_string_push_back(t_c_string *str, char symbol)
{
	printf("transmitted symbol = %c\n", symbol);
    c_string_resize(str, str->m_size + 1);
    if (str->m_size < str->m_static_capacity)
		str->m_static_array[str->m_size] = symbol;
    else
		str->m_dynamic_array[str->m_size] = symbol;
	printf("Copy symbol        = %c\n", str->m_dynamic_array[str->m_size]);
    ++str->m_size;
}

void c_string_pop_back(t_c_string* str)
{
    --str->m_size;
}