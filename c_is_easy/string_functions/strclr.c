#include "string_functions.h"

void	ce_strclr(char** line)
{
    if (line == NULL || *line == NULL)
	return;
    free(*line);
    *line = NULL;
}