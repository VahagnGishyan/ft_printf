#include "../ft_printf/ft_printf.h"

void	pf_command_hexa(t_c_string* line, unsigned long value)
{
    char* ptr;

    ptr = NULL;
    ptr = pf_change_base((unsigned long long)value, HEX_BASE);
    c_string_concatenation_chararray(line, ptr, ce_strlen(ptr));
    free(ptr);
}
