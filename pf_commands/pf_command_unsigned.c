#include "../ft_printf/ft_printf.h"

void	pf_command_unsigned(t_c_string* line, unsigned long value)
{
    char* ptr;

    ptr = ft_itoa(value);
    c_string_concatenation_chararray(line, ptr, ce_strlen(ptr));
    free(ptr);
}