
#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include "../mini_42_school_c_header/header/c_header.h"
#include "../mini_42_school_c_header/header/mini_42_school_c_header.h"

# define HEX_BASE 16

int	ft_printf(const char *input, ...);

<<<<<<< HEAD
bool	pf_check_arguments(const char *format, int* value);
=======
bool	pf_check_arguments(const char *format, int *value);
>>>>>>> bd60d693229af996fbbd7f385abec4e5403ba511
void	pf_split_by_message(const char* format, va_list* args, t_c_vector_string* arg_message);
char	*pf_combine_main_message(t_c_vector_string *arg_message);
int	pf_get_count(char* main_message);

bool	pf_is_valid_char(char c);
int		pf_is_valid_type(int c);
int		pf_get_message_count(const char* formath);

char	*pf_change_base(unsigned long long ull, int base);

void	pf_add_mesige_value(t_c_string* line, char symbol,  va_list* args);

void	pf_shrink_to_fit(t_c_vector_string* message);
int		pf_mmesslen(t_c_vector_string* message);

void	pf_command_char(t_c_string* line, int symbol);
void	pf_command_str(t_c_string* line, const char *str);
void	pf_command_decimal(t_c_string* line, int value);
void	pf_command_pointer(t_c_string* line, unsigned long long ptr);
void	pf_command_unsigned(t_c_string* line, unsigned long value);
void	pf_command_hexalower(t_c_string* line, unsigned long value);
void	pf_command_hexa(t_c_string* line, unsigned long value);
void	pf_command_percent(t_c_string* line, unsigned long value);


#endif //FT_PRINTF_H
