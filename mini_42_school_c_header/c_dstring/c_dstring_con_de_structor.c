#include "c_dstring.h"

void c_dstring_constructor(t_c_dstring* str)
{
    str->m_array = 0;
    str->m_capacity = 0;
    str->m_size = 0;
    __c_dstring_constructor_array_size(str);
    __c_dstring_constructor_compare_data(str);
    __c_dstring_constructor_concatenation(str);
    __c_dstring_constructor_convert_to(str);
    __c_dstring_constructor_copy_data(str);
    __c_dstring_constructor_get_free_dymemory(str);
    __c_dstring_constructor_index_operators(str);
    __c_dstring_constructor_is_check(str);
    __c_dstring_constructor_push_pop(str);
    __c_dstring_constructor_search(str);
    __c_dstring_constructor_to_upper_lower(str);
    __c_dstring_constructor_setdata(str);
}

void c_dstring_destructor(t_c_dstring* str)
{
    str->clear(str);
}