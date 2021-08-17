
#include "../ft_printf/ft_printf/ft_printf.h"

bool pf_check_arguments(const char* format)
{
    if (ce_strlen(format) == 0)
		return (true);
    if (ft_strchr(format, '%') == NULL)
		return (true);
    // ...
    return (false);
}

void pf_split_by_message(const char *format, va_list* args, t_c_vector_string* arg_message)
{
    int	index;
    int	length;
    int	start;

    index = -1;
    length = ce_strlen(format);
    start = 0;
    c_vector_string_resize(arg_message, pf_get_message_count(format));
    while (++index < length)
    {
	char symbol = format[index];
	//if (pf_is_valid_char(symbol))
	//{
	//    c_string_push_back(c_vector_string_at(arg_message, start), symbol);
	//    continue ;
	//}
	if (symbol == '%')
	{
	    ++start;
	    ++index; // no flag
	    pf_add_mesige_value(c_vector_string_at(arg_message, start), format[index], args);
	    ++start;
	    continue ;
	}
	else
	    c_string_push_back(c_vector_string_at(arg_message, start), symbol);
    }
    pf_shrink_to_fit(arg_message);
}

char* pf_combine_main_message(t_c_vector_string* arg_message)
{
    t_c_string main_message;
    char*   result;
    int	    index;
    int	    length;

    result = NULL;
    c_string_constructor(&main_message);
    if (!c_string_resize(&main_message, (pf_mmesslen(arg_message) * 1.3)))
	return (NULL);
    index = -1;
    length = c_vector_string_size(arg_message);
    while (++index < length)
	c_string_concatenation_c_string(&main_message, c_vector_string_at(arg_message, index));
    ce_strrsz(&result, c_string_size(&main_message) * 1.3 + 1);
    c_string_convert_to_chararray(&main_message, result);
    c_string_destructor(&main_message);
    return (result);
}

int pf_get_count(char* main_message)
{
    return (ce_strlen(main_message));
}

int			ft_printf(const char * format, ...)
{
	va_list		    args;
	t_c_vector_string   arg_message;
	char*		    main_message;
	int count;

	count = 0;
	va_start(args, format);

	if (pf_check_arguments(format))
	    return (ce_strlen(format));

	c_vector_string_constructor(&arg_message);
	//arg_message.m_dynamic_data = (t_c_string*)malloc(sizeof(t_c_string));
	//c_string_constructor(arg_message.m_dynamic_data);

	pf_split_by_message(format, &args, &arg_message);

	main_message = pf_combine_main_message(&arg_message);

	count = pf_get_count(main_message);
	write(1, main_message, ce_strlen(main_message));
	free(main_message);	

	va_end(args);
	c_vector_string_destructor(&arg_message);
	return (count);
}
