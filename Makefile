NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f
MAKE = Makefile

FUNCS		=		ft_print_chr.c          ft_print_hex.c          ft_print_int.c          ft_print_prc.c          ft_print_ptr.c          ft_print_str.c          ft_print_unt.c       \
					ft_print_uph.c          ft_printf.c             ft_tools_num.c          ft_tools_params.c       ft_tools_str.c          ft_tools_struct.c		libft/ft_atoi.c       libft/ft_putstr_fd.c  libft/ft_strlen.c     libft/ft_substr.c
FUNCS_B		=		ft_print_chr_bonus.c    ft_print_int_bonus.c    ft_print_ptr_bonus.c    ft_print_unt_bonus.c    ft_printf_bonus.c       ft_tools_num_bonus.c    ft_tools_str_bonus.c \
                    ft_print_hex_bonus.c    ft_print_prc_bonus.c    ft_print_str_bonus.c    ft_print_uph_bonus.c    ft_tools_params_bonus.c ft_tools_struct_bonus.c libft/ft_atoi_bonus.c       libft/ft_putstr_fd_bonus.c  libft/ft_strlen_bonus.c     libft/ft_substr_bonus.c


FUNCS_O		=		$(FUNCS:.c=.o)
FUNCS_O_B	=		$(FUNCS_B:.c=.o)

HDR			=		ft_printf.h
HDR_B		=		ft_printf_bonus.h

.c.o: $(FUNCS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(FUNCS_O)
	$(AR) $@ $^

$(FUNCS_O): $(HDR) $(MAKE)

$(FUNCS_O_B): $(HDR_B) $(MAKE)

bonus: re

rebonus: fclean bonus

all: $(NAME)

clean:
	$(RM) $(FUNCS_O) $(FUNCS_O_B)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: bonus all clean fclean re rebonus