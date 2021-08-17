#include "c_string.h"

void __c_string_constructor_concatenation(t_c_string* str)
{
    str->concatenation_chararray = c_string_concatenation_chararray;
    str->concatenation_c_string = c_string_concatenation_c_string;
}

void c_string_concatenation_chararray(t_c_string* str, const char* arr, int size)
{
    t_c_dstring d_str;
    
    c_dstring_constructor(&d_str);
    c_string_convert_to_dstring(str, &d_str);
    d_str.concatenation_chararray(&d_str, arr, size);
    c_string_copy_c_dstring(str, &d_str);
    c_dstring_destructor(&d_str);
}
void c_string_concatenation_c_string(t_c_string* str_main, t_c_string* str_other)
{
    t_c_dstring d_str_main;
    t_c_dstring d_str_other;

    c_dstring_constructor(&d_str_main);
    c_dstring_constructor(&d_str_other);
    c_string_convert_to_dstring(str_main, &d_str_main);
    c_string_convert_to_dstring(str_other, &d_str_other);
    c_dstring_concatenation_c_dstring(&d_str_main, &d_str_other);
    c_string_copy_c_dstring(str_main, &d_str_main);
    c_dstring_destructor(&d_str_main);
    c_dstring_destructor(&d_str_other);
}
