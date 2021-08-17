#include "supporting_functions.h"

/*int*/
int	int_max(int valueA, int valueB)
{
    return (valueA > valueB ? valueA : valueB);
}
int	int_min(int valueA, int valueB)
{
    return (valueA < valueB ? valueA : valueB);
}

bool	int_is_positive(int value)
{
    return (value > 0);
}
bool	int_is_negative(int value)
{
    return (value < 0);
}
bool	int_is_zero(int value)
{
    return (value == 0);
}