#pragma once
#include "../c_string/c_string.h"
#include "../c_is_easy/supporting_functions/supporting_functions.h"

typedef struct c_vector_string t_c_vector_string;

struct c_vector_string
{
    int		m_size;
    t_c_string*	m_static_data;
    int		m_static_capacity;
    t_c_string* m_dynamic_data;
    int		m_dynamic_capacity;
};

void c_vector_string_constructor(t_c_vector_string* obj);
void c_vector_string_destructor(t_c_vector_string* obj);

//Set data
void c_vector_string_tie_static_array(t_c_vector_string* obj, t_c_string* data, int capacity);
void c_vector_string_set_data(t_c_vector_string* obj, t_c_string* data, int size, int capacity);

//ResizeClear
//bool reserve(t_c_vector_string* obj, int length);
bool c_vector_string_reserve(t_c_vector_string* obj, int length);
bool c_vector_string_resize(t_c_vector_string* obj, int length);
void c_vector_string_clear(t_c_vector_string* obj);
void c_vector_string_disconnect(t_c_vector_string* obj);

//ArraySize
int  c_vector_string_size(t_c_vector_string* obj);
int  c_vector_string_static_capacity(t_c_vector_string* obj);
int  c_vector_string_dynamic_capacity(t_c_vector_string* obj);
int  c_vector_string_capacity(t_c_vector_string* obj);
bool c_vector_string_is_empty(t_c_vector_string* obj);

//IndexOperators
t_c_string* c_vector_string_at(t_c_vector_string* obj, int index);
t_c_string* c_vector_string_front(t_c_vector_string* obj);
t_c_string* c_vector_string_back(t_c_vector_string* obj);

//PushPopBack
void c_vector_string_push_back(t_c_vector_string* obj, t_c_string* value);
void c_vector_string_pop_back(t_c_vector_string* obj);

//CopyData
void c_vector_string_copy_string_array(t_c_vector_string* obj, t_c_string* arr, int size);
void c_vector_string_copy_c_vector_string(t_c_vector_string* obj, t_c_vector_string* arrstring);

//Concatenation
void c_vector_string_concatenation_string_array(t_c_vector_string* obj, t_c_string* arr, int size);
void c_vector_string_concatenation_c_vector_string(t_c_vector_string* obj, t_c_vector_string* arrint);

//Search
t_c_string* c_vector_string_search_string(t_c_vector_string* data, t_c_string* obj);
int   c_vector_string_search_string_index(t_c_vector_string* data, t_c_string* obj);

//ConvertToString
void  c_vector_string_convert_to_string_array(t_c_vector_string* obj, t_c_string* arrstring);

//is memory check
bool  c_vector_string_is_static_memory_null(t_c_vector_string* obj);
bool  c_vector_string_is_dynamic_memory_null(t_c_vector_string* obj);
bool  c_vector_string_is_null(t_c_vector_string* obj);
bool  c_vector_string_is_used_dynamic_memory(t_c_vector_string* obj);