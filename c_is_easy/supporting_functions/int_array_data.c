#include "supporting_functions.h"

void int_array_set_default_number(int* arr_main, int size, int number)
{
    int index;

    if (size <= 0)
	return;
    index = -1;
    while (++index < size)
	arr_main[index] = number;
}

void int_array_copy_int_array(int* arr_main, int* arr_other, int size)
{
    int index;

    if (size <= 0)
	return;
    index = -1;
    while (++index < size)
	arr_main[index] = arr_other[index];
}