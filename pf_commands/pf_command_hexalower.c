#include "../ft_printf/ft_printf.h"

void	pf_command_hexalower(t_c_string* line, unsigned long value)
{
    char* ptr;
    char* low_ptr;

    ptr = NULL;
    low_ptr = NULL;
    ptr = pf_change_base((unsigned long long)value, HEX_BASE);
    low_ptr = ce_strlow(ptr, ce_strlen(ptr));
    c_string_concatenation_chararray(line, ptr, ce_strlen(low_ptr));
    free(ptr);
    free(low_ptr);
}
