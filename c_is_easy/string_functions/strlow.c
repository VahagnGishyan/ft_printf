#include "string_functions.h"

char* ce_strlow(char* line, int length)
{
    int	    index;
    char* ptr;

    index = -1;
    ptr = (char*)malloc(length);
    if (ptr == NULL)
	return (NULL);
    while (++index < length)
	ptr[index] = ft_tolower(line[index]);
    return (line);
}