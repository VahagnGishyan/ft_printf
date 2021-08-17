#include "c_vector_string.h"

bool  c_vector_string_is_static_memory_null(t_c_vector_string* obj)
{
    return (obj->m_static_data == NULL);
}

bool  c_vector_string_is_dynamic_memory_null(t_c_vector_string* obj)
{
    return (obj->m_dynamic_data == NULL);
}

bool  c_vector_string_is_null(t_c_vector_string* obj)
{
    return(obj->m_static_data == NULL && obj->m_dynamic_data == NULL);
}

bool  c_vector_string_is_used_dynamic_memory(t_c_vector_string* obj)
{
    return ((obj->m_dynamic_data == NULL) 
	    && (obj->m_dynamic_capacity) 
	    && (obj->m_size > obj->m_static_capacity));
}

