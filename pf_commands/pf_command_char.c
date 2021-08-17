#include "../ft_printf/ft_printf.h"

void	pf_command_char(t_c_string* line, int symbol)
{
    c_string_push_back(line, symbol);
}