NAME	= libftprintf.a

FUNCS 	=	ft_printf.c					\
			ft_tools.c				\
			libft/ft_substr.c		\
			libft/ft_strlen.c		\
			libft/ft_atoi.c			\
			libft/ft_putstr_fd.c	\
			ft_print_int.c			\
			ft_print_chr.c			\
			ft_print_str.c			\
			ft_print_ptr.c			\
			ft_print_hex.c			\
			ft_print_HEX.c			\
			ft_print_prc.c			\
			ft_print_unt.c			\
			ft_print_not.c		
FUNCSO = ${FUNCS:.c=.o}
GCC = gcc
CFLAGS = -c -Wextra -Wall -Werror
HDRS = head.h

all:		${NAME}

${NAME}:	${FUNCSO} ${HDRS} 
			ar rc ${NAME} ${FUNCSO}
			
.c.o:		
			${GCC} ${CFLAGS} $< -o ${<:.c=.o} 

bonus: re

re: fclean all

clean:
		rm -f ${FUNCSO}

fclean:	clean
		rm -f ${NAME}

.PHONY:	all clean fclean