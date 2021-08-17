#include "../ft_printf/ft_printf.h"

void	pf_command_percent(t_c_string* line, unsigned long value)
{
    c_string_push_back(line, value);
}