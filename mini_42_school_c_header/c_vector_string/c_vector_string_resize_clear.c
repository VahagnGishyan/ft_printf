#include "c_vector_string.h"

bool c_vector_string_reserve(t_c_vector_string* obj, int length)
{
    t_c_string* newarr;
    int		newlength;
    int		size;

    if (length < 0)
    {
	c_vector_string_clear(obj);
	return (false);
    }
    if (c_vector_string_capacity(obj) >= length)
	return true;

    newlength = (int)((length - obj->m_static_capacity) * 1.3 + 1);
    if ((newarr = (t_c_string*)malloc(newlength * sizeof(t_c_string))) == NULL)
	return (false);

    c_string_array_constructor(newarr, newlength);
    c_string_array_copy_c_string_array(newarr, obj->m_dynamic_data, obj->m_size - obj->m_static_capacity);
    size = obj->m_size;
    c_vector_string_clear(obj);

    obj->m_dynamic_data = newarr;
    obj->m_size = size;
    obj->m_dynamic_capacity = newlength;
    return (true);
}

bool c_vector_string_resize(t_c_vector_string* obj, int length)
{
    if (!c_vector_string_reserve(obj, length))
	return (false);
    obj->m_size = length;
    return (true);
}

void c_vector_string_clear(t_c_vector_string* obj)
{
    int index;

    if (c_vector_string_is_null(obj))
	return;
    index = -1;
    while (++index < obj->m_dynamic_capacity)
	 c_string_clear(&obj->m_dynamic_data[index]);
    c_string_array_destructor(obj->m_dynamic_data, obj->m_dynamic_capacity);
    free(obj->m_dynamic_data);
    obj->m_dynamic_data = NULL;
    obj->m_size = 0;
    obj->m_dynamic_capacity = 0;
}

void c_vector_string_disconnect(t_c_vector_string* obj)
{
    if (c_vector_string_is_null(obj))
	return;

    c_vector_string_clear(obj);
    obj->m_static_data = NULL;
    obj->m_static_capacity = 0;
}

//bool c_vector_string_reserve(t_c_vector_string* obj, int length)
//{
//    return (length >= 0 && length <= obj->m_capacity);
//}
//
//bool c_vector_string_resize(t_c_vector_string* obj, int length)
//{
//    return (length >= 0 && length <= obj->m_capacity);
//}
//
//void c_vector_string_clear(t_c_vector_string* obj)
//{
//    if (m_data == NULL)
//	return;
//    c_string_array_destructor(m_data, obj->m_size);
//    obj->m_size = 0;
//}
//
//void c_vector_string_disconnect(t_c_vector_string* obj)
//{
//    if (m_data == NULL)
//	return;
//
//    obj->clear(obj);
//    obj->m_data = NULL;
//    obj->m_capacity = 0;
//}