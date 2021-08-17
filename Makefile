SRCS	= ft_printf.c \
		main.c \
		${wildcard ./ft_printf/*.c} \
		${wildcard ./mini_42_school_c_header/c_dstring/*.c} \
		${wildcard ./mini_42_school_c_header/c_is_easy/dynamic_memory/*.c} \
		${wildcard ./mini_42_school_c_header/c_is_easy/string_functions/*.c} \
		${wildcard ./mini_42_school_c_header/c_is_easy/supporting_functions/*.c} \
		${wildcard ./mini_42_school_c_header/c_string/*.c} \
		${wildcard ./mini_42_school_c_header/c_vector_string/*.c} \
		${wildcard ./mini_42_school_c_header/libft/*.c} \
		${wildcard ./pf_commands/*.c} 

OBJS	= $(SRCS:.c=.o)

RM		= rm -f

CC		= cc

NAME	= libftprintf.a

TMP		= print
          #delete
CFLAGS	= -Wall -Wextra 

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJS)
			ar rcs $(NAME) $(OBJS)				
			$(CC) -o $(TMP) $(OBJS) -L. -lftprintf   
            #delete
clean:
			$(RM) $(OBJS)

fclean:			clean
			$(RM) $(NAME)
			$(RM) $(TMP)
            #delete
re:			fclean all

.PHONY:			all clean fclean re

#gcc -o print *.o -L. -lftprintf
