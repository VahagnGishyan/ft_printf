#include "string_functions.h"

bool	ce_isspace(char symbol)
{
    bool result;

    switch (symbol)
    {
    case ' ':
    case '\t':
    case '\n':
    case '\v':
    case '\r':
	result = true;
	break;
    default:
	result = false;
    }
    return (result);
}
