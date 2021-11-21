NAME	= libftprintf.a

FUNCS 	=	ft_print_chr_bonus.c		\
			ft_print_chr.c				\
			ft_printf_bonus.c			\
			ft_printf_bonus.h			\
			ft_printf.c					\
			ft_printf.h					\
			ft_print_hex_bonus.c		\
			ft_print_hex.c				\
			ft_print_int_bonus.c		\
			ft_print_int.c				\
			ft_print_prc_bonus.c		\
			ft_print_prc.c				\
			ft_print_ptr_bonus.c		\
			ft_print_ptr.c				\
			ft_print_str_bonus.c		\
			ft_print_str.c				\
			ft_print_unt_bonus.c		\
			ft_print_unt.c				\
			ft_print_uph_bonus.c		\
			ft_print_uph.c				\
			ft_tools_num_bonus.c		\
			ft_tools_num.c				\
			ft_tools_params_bonus.c		\
			ft_tools_params.c			\
			ft_tools_str_bonus.c		\
			ft_tools_str.c				\
			ft_tools_struct_bonus.c		\
			ft_tools_struct.c			\



FUNCSO = ${FUNCS:.c=.o}
GCC = gcc
CFLAGS = -c -Wall -Wextra -Werror
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