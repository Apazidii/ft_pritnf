NAME	= printf
FUNCS 	=	main.c					\
			ft_tools.c				\
			ft_allprints.c			\
			ft_putullint.c			\
			ft_putint.c				\
			ft_putuint.c			\
			ft_putllint.c			\
			ft_params.c				\
			libft/ft_atoi.c			\
			libft/ft_substr.c		\
			libft/ft_strlen.c		
FUNCSO = ${FUNCS:.c=.o}
GCC = gcc
CFLAGS = -c
HDRS = head.h

all:		${NAME}
			make clean
			clear
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
