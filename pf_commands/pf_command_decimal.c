#include "../ft_printf/ft_printf.h"

void	pf_command_decimal(t_c_string* line, int value)
{
    char* ptr;
    
    ptr = ft_itoa(value);
    c_string_concatenation_chararray(line, ptr, ce_strlen(ptr));
    free (ptr);
}