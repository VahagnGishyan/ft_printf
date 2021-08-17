
#include "ft_printf.h"

void	pf_add_mesige_value(t_c_string* line, char symbol, va_list *args)
{
    switch (symbol)
    {
    case 'c':
	pf_command_char(line, va_arg(*args, int));
	break;
    case 's':
	pf_command_str(line, va_arg(*args, const char*));
	break;
    case 'p':
	pf_command_pointer(line, va_arg(*args, unsigned long long));
	break;
    case 'i':
    case 'd':
	pf_command_decimal(line, va_arg(*args, int));
	break;
    case 'u':
	pf_command_unsigned(line, va_arg(*args, unsigned long));
	break;
    case 'x':
	pf_command_hexalower(line, va_arg(*args, unsigned long));
	break;
    case 'X':
	pf_command_hexa(line, va_arg(*args, unsigned long));
	break;
    case '%':
	pf_command_percent(line, va_arg(*args, unsigned long));
	break;
    default:
	line->push_back(line, symbol);
	break;
    }
}
