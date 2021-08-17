
#include "../ft_printf/ft_printf/ft_printf.h"

bool pf_check_arguments(const char* format, int* count)
{
    if (ce_strlen(format) == 0)
    {
	*count = 0;
	return (true);
    }
    if (ft_strchr(format, '%') == NULL)
    {
	*count = ce_strlen(format);
	write(1, format, *count);
	return (true);
    }
    // ...
    return (false);
}

void pf_split_by_message(const char *format, va_list* args, t_c_vector_string* arg_message)
{
    int	index;
    int	length;
    int	start;


		printf("Check pf_split_by_message :: 1\n");
		printf("Format = %s\n", format);
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

		printf("Check pf_split_by_message :: 2\n");
		printf("Format = %s\n", format);

	printf("Start message print\n");
	
	printf("Message count = %d\n", c_vector_string_size(arg_message));
	for(int index = 0; index < c_vector_string_size(arg_message); ++index)
	{
		printf("Message %d :: ", index);
		char* ptr;
		t_c_string* str;
		str = c_vector_string_at(arg_message, index);

		ptr = (char*)malloc(c_string_size(str));
		c_string_convert_to_chararray(str, ptr);
		printf("%s\n",ptr);
		
		free(ptr);
	}
	printf("Exit message print\n");

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
	va_list				args;
	t_c_vector_string	arg_message;
	char*		    main_message;
	int		    count;

	count = 0;
	va_start(args, format);
		printf("Check ft_printf :: 1\n");
		printf("Format = %s\n", format);
	if (pf_check_arguments(format, &count))
	    return (count);

		printf("Check ft_printf :: 2\n");
		printf("Format = %s\n", format);
	c_vector_string_constructor(&arg_message);
	//arg_message.m_dynamic_data = (t_c_string*)malloc(sizeof(t_c_string));
	//c_string_constructor(arg_message.m_dynamic_data);
		
		printf("Check ft_printf :: 3\n");
		printf("Format = %s\n", format);
	pf_split_by_message(format, &args, &arg_message);
		
		printf("Check ft_printf :: 4\n");
		printf("Format = %s\n", format);
	main_message = pf_combine_main_message(&arg_message);

		printf("Check ft_printf :: 5\n");
		printf("Format = %s\n", format);
	count = pf_get_count(main_message);
	write(1, main_message, ce_strlen(main_message));
	free(main_message);	

		printf("Check ft_printf :: 6\n");
		printf("Format = %s\n", format);
	va_end(args);
	c_vector_string_destructor(&arg_message);
	return (count);
}
