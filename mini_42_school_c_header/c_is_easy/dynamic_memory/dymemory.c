#include "dynamic memory.h"

bool	ce_dymemory(char **ptr, int length)
{
    if (*ptr != NULL)
    {
	free (*ptr);
	*ptr = NULL;
    }
    *ptr = (char*)malloc(length);
    return (*ptr == NULL);
}

void	ce_dyclear(char** ptr)
{
    if (*ptr == NULL)
		return;
    free(*ptr);
    *ptr = NULL;
}
