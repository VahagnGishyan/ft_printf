#include "../ft_printf/ft_printf.h"

void	pf_command_str(t_c_string* line, const char* str)
{
    c_string_concatenation_chararray(line, str, ce_strlen(str));
}