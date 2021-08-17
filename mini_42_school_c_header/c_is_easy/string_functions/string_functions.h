#pragma once

#include "../../header/c_header.h"
#include "../../libft/Libft.h"

/*char array*/
void	ce_strclr(char** line);
int		ce_strlen(const char* line);
size_t	ce_strlcpy(char* dest, const char* sorc, size_t dstsize);
bool	ce_strrsz(char** str, int length);

char*	ce_strlow(char* line, int length);
bool	ce_isspace(char symbol);