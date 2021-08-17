#include "c_dstring.h"

void __c_dstring_constructor_setdata(t_c_dstring* str)
{
    str->setdata = c_dstring_setdata;
}

void  c_dstring_setdata(t_c_dstring* str, const char* arr, int length)
{
    int index;

    if (!str->resize(str, (int)(length * 1.3)))
	return;
    index = 0;
    while (index < length)
    {
	*str->at(str, index) = arr[index];
	++index;
    }
    str->m_size = length;
}
