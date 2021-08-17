#include "string_functions.h"

int	ce_strlen(const char* line)
{
    if (line == NULL)
	return (0);
    return (ft_strlen(line));
}
