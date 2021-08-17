#pragma once

#include "../header/c_header.h"
#include "../libft/Libft.h"
#include "../c_dstring/c_dstring.h"

# define END_OF_LINE '\0'
# define NEW_LINE '\n'

typedef struct c_string t_c_string;

struct c_string
{
    int			    m_size;
    char*                   m_static_array;
    int                     m_static_capacity;
    char*                   m_dynamic_array;
    int                     m_dynamic_capacity;

    void  (*tie_static_array)(t_c_string* str, char* arr, int length);
    void  (*setdata)(t_c_string* str, char* arr, int size, int length);
    bool  (*resize)(t_c_string* str, int length);
    void  (*clear)(t_c_string* str);

    int   (*size)(t_c_string* str);
    int   (*capacity)(t_c_string* str);
    bool  (*is_empty)(t_c_string* str);

    char* (*at)(t_c_string* str, int index);
    char* (*front)(t_c_string* str);
    char* (*back)(t_c_string* str);

    void  (*push_back)(t_c_string* str, char symbol);
    void  (*pop_back)(t_c_string* str);

    void  (*copy_chararray)(t_c_string* str, const char* arr, int size);
    void  (*copy_c_string)(t_c_string* str_main, t_c_string* str_other);
    void  (*copy_c_dstring)(t_c_string* str_main, void* str_other);

    void  (*concatenation_chararray)(t_c_string* str, const char* arr, int size);
    void  (*concatenation_c_string)(t_c_string* str_main, t_c_string* str_other);

    int   (*compare_chararray)(t_c_string*, char* arr, int size);
    int   (*compare_c_string)(t_c_string* str_main, t_c_string* str_other);

    char* (*search_char)(t_c_string* str, char symbol);
    char* (*search_chararray)(t_c_string* str, char* arr, int size);
    char* (*search_c_string)(t_c_string* str_main, t_c_string* str_other);

    bool  (*is_alpha)(t_c_string* str);
    bool  (*is_digit)(t_c_string* str);
    bool  (*is_alnum)(t_c_string* str);
    bool  (*is_print)(t_c_string* str);

    bool  (*is_static_memory_null)(t_c_string* str);
    bool  (*is_dynamic_memory_null)(t_c_string* str);
    bool  (*is_used_dynamic_memory)(t_c_string* str);
    bool  (*is_null)(t_c_string* str);

    void  (*to_upper_chararray)(t_c_string* str, char* arr);
    void  (*to_upper_c_string)(t_c_string* str_main, t_c_string* str_other);
    void  (*to_lower_chararray)(t_c_string* str, char* arr);
    void  (*to_lower_c_string)(t_c_string* str_main, t_c_string* str_other);

    void  (*convert_to_int)(t_c_string*, int* value);
    void  (*convert_to_chararray)(t_c_string*, char* arr);
    void  (*convert_to_dstring)(t_c_string* str_main, void* str_other);
};

void c_string_constructor(t_c_string* str);
void __c_string_constructor_array_size(t_c_string* str);
void __c_string_constructor_compare_data(t_c_string* str);
void __c_string_constructor_concatenation(t_c_string* str);
void __c_string_constructor_convert_to(t_c_string* str);
void __c_string_constructor_copy_data(t_c_string* str);
void __c_string_constructor_get_free_dymemory(t_c_string* str);
void __c_string_constructor_index_operators(t_c_string* str);
void __c_string_constructor_is_check(t_c_string* str);
void __c_string_constructor_is_check_memory(t_c_string* str);
void __c_string_constructor_push_pop(t_c_string* str);
void __c_string_constructor_search(t_c_string* str);
void __c_string_constructor_setdata(t_c_string* str);
void __c_string_constructor_to_upper_lower(t_c_string* str);

void c_string_destructor(t_c_string* str);

void  c_string_tie_static_array(t_c_string* str, char* arr, int length);
void  c_string_setdata(t_c_string* str, char* arr, int size, int length);

bool  c_string_resize(t_c_string* str, int length);
void  c_string_clear(t_c_string* str);

int   c_string_size(t_c_string* str);
int   c_string_capacity(t_c_string* str);
bool  c_string_is_empty(t_c_string* str);

char* c_string_at(t_c_string* str, int index);
char* c_string_front(t_c_string* str);
char* c_string_back(t_c_string* str);

void  c_string_push_back(t_c_string* str, char symbol);
void  c_string_pop_back(t_c_string* str);

void  c_string_copy_chararray(t_c_string* str, const char* arr, int size);
void  c_string_copy_c_string(t_c_string* str_main, t_c_string* str_other);
void  c_string_copy_c_dstring(t_c_string* str_main, void* str_other);

void  c_string_concatenation_chararray(t_c_string* str, const char* arr, int size);
void  c_string_concatenation_c_string(t_c_string* str_main, t_c_string* str_other);

int   c_string_compare_chararray(t_c_string* str, char* arr, int size);
int   c_string_compare_c_string(t_c_string* str_main, t_c_string* str_other);

char* c_string_search_char(t_c_string* str, char symbol);
char* c_string_search_chararray(t_c_string* str, char* arr, int size);
char* c_string_search_c_string(t_c_string* str_main, t_c_string* str_other);

bool  c_string_is_alpha(t_c_string* str);
bool  c_string_is_digit(t_c_string* str);
bool  c_string_is_alnum(t_c_string* str);
bool  c_string_is_print(t_c_string* str);

bool  c_string_is_static_memory_null(t_c_string* str);
bool  c_string_is_dynamic_memory_null(t_c_string* str);
bool  c_string_is_null(t_c_string* str);
bool  c_string_is_used_dynamic_memory(t_c_string* str);

void  c_string_to_upper_chararray(t_c_string* str, char* arr);
void  c_string_to_upper_c_string(t_c_string* str_main, t_c_string* str_other);
void  c_string_to_lower_chararray(t_c_string* str, char* arr);
void  c_string_to_lower_c_string(t_c_string* str_main, t_c_string* str_other);

void  c_string_convert_to_int(t_c_string*, int* value);
void  c_string_convert_to_chararray(t_c_string*, char* arr);
void  c_string_convert_to_dstring(t_c_string* str_main, void* str_other);
