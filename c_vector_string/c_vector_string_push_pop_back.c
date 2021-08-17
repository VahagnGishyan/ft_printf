#include "c_vector_string.h"

void c_vector_string_push_back(t_c_vector_string* obj, t_c_string* value)
{
    if (!c_vector_string_reserve(obj, obj->m_size + 1))
	return;
    c_vector_string_at(obj, obj->m_size)->copy_c_string(c_vector_string_at(obj, obj->m_size), value);
    ++obj->m_size;
}

void c_vector_string_pop_back(t_c_vector_string* obj)
{
    --obj->m_size;
}

//void c_vector_string_push_back(t_c_vector_string* obj, t_c_string* value)
//{
//    if (!obj->resize(obj, obj->m_size + 1))
//	return;
//    c_string_constructor(obj->at(obj, obj->m_size));
//    obj->at(obj, obj->m_size)->copy_c_string(obj->at(obj, obj->m_size), value);
//    ++obj->m_size;
//}
//
//void c_vector_string_pop_back(t_c_vector_string* obj)
//{
//    --obj->m_size;
//    c_string_destructor(obj->at(obj, obj->m_size));
//}