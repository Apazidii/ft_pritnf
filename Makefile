NAME	= printf
FUNCS 	=	ft_printf.c				\
			ft_tools_num.c			\
			ft_tools_struct.c		\
			ft_tools_str.c			\
			ft_tools_params.c		\
			main.c					\
			libft/ft_substr.c		\
			libft/ft_strlen.c		\
			libft/ft_atoi.c			\
			libft/ft_putstr_fd.c	\
			ft_print_int.c			\
			ft_print_hex.c			\
			ft_print_uph.c			\
			ft_print_ptr.c			\
			ft_print_unt.c			\
			ft_print_str.c			\
			ft_print_chr.c			\
			ft_print_prc.c			\
			

FUNCSO = ${FUNCS:.c=.o}
GCC = gcc
CFLAGS = -c 
HDRS = head.h

all:		${NAME}
			make clean
			#clear
			./${NAME}
			

${NAME}:	${FUNCSO} ${HDRS} 
			${GCC} ${FUNCSO} -o ${NAME}
			
.c.o:		
			${GCC} ${CFLAGS} $< -o ${<:.c=.o} 

clean:
		rm -f ${FUNCSO}

fclean:	clean
		rm -f ${NAME}

.PHONY:	all clean fclean