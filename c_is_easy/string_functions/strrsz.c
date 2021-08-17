#include "string_functions.h"

bool ce_strrsz(char** str, int length)
{
    char* newstring;
    int		newsize;

    if (!str)
	return false;
    newstring = NULL;
    newstring = (char*)malloc(length + 1);
    if (newstring == NULL)
		return (false);
    ce_strlcpy(newstring, *str, ce_strlen(*str) + 1);
    newsize = ce_strlen(*str);
    if (*str != NULL)
    {
		free(*str);
		*str = NULL;
    }
    *str = newstring;
    (*str)[newsize] = '\0';
	return (true);
}