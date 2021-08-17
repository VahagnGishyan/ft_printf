#include "string_functions.h"

size_t	ce_strlcpy(char* dest, const char* sorc, size_t dstsize)
{
    size_t	index;

    if (dest == NULL || sorc == NULL)
	return (0);
    if (!dstsize)
	return (ce_strlen(sorc));
    index = 0;
    while (sorc[index] != '\0' && index < (dstsize - 1))
    {
	dest[index] = sorc[index];
	++index;
    }
    dest[index] = '\0';
    return ((size_t)ce_strlen(sorc));
}
