#include "../ft_printf/ft_printf.h"

void	pf_command_pointer(t_c_string* line, unsigned long long value)
{
    char* ptr;

    ptr = pf_change_base(value, HEX_BASE);
    c_string_concatenation_chararray(line, ptr, ce_strlen(ptr));
    free(ptr);
}