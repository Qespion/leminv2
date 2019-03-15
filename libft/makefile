CC          =     gcc
AR          =   ar
ARFLAGS     =     rc
CFLAGS      =     -Wall -Wextra -Werror
NAME        =     libft.a
SRC         =     srcs/ft_printf.c	\
				  srcs/tools.c		\
				  srcs/ft_printable.c	\
				  srcs/ft_strlen.c	\
				  srcs/ft_putstr.c	\
				  srcs/ft_putchar.c	\
				  srcs/ft_strdel.c	\
				  srcs/ft_atoi.c	\
				  srcs/ft_putstrn.c	\
				  srcs/printable_adv.c	\
				  srcs/ft_putcharn.c	\
				  srcs/ft_putnbr.c		\
				  srcs/ft_abs.c			\
				  srcs/printnb.c		\
				  srcs/ft_convert_base.c\
				  srcs/printhexa.c		\
				  srcs/ft_toupper.c		\
				  srcs/ft_printaddress.c\
				  srcs/printunicode.c	\
				  srcs/printunsigned.c	\
				  srcs/nb_p_and_w.c		\
				  srcs/printbinary.c	\
				  srcs/ft_strjoin.c		\
				  srcs/ft_bzero.c		\
				  srcs/ft_strcat.c		\
				  srcs/printlstring.c	\
				  srcs/lstring_tools.c	\
				  srcs/printf_tools.c	\
				  srcs/get_next_line.c	\
				  srcs/ft_strsub.c		\
				  srcs/ft_strfjoin.c	\
				  srcs/ft_strnew.c		\
				  srcs/ft_lstaddone.c	\
				  srcs/ft_lstnew.c		\
				  srcs/get_next_line.c	\
				  srcs/ft_memmove.c		\
				  srcs/ft_lstdelone.c	\
				  srcs/ft_insert_one.c	\
				  srcs/ft_memdel.c		\
				  srcs/ft_lstdel.c		\
				  srcs/ft_putstr_fd.c	\
				  srcs/ft_strcmp.c		\
				  srcs/ft_itoa.c		\
				  srcs/ft_strdup.c		\
				  srcs/ft_len_list.c	\
				  srcs/ft_strtrimfirst.c\
				  srcs/ft_strstr.c		\
				  srcs/ft_strchr.c


C_GREEN	=	"\033[32m"
C_BLUE	=	"\033[36m"
C_BASE	=	"\033[00m"

OBJ=$(SRC:.c=.o)
.SUFFIXES:
all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(ARFLAGS) $(NAME) $(OBJ)
	@ranlib $(NAME)
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I includes/
clean:
	@rm -f $(OBJ)
	@echo $(C_GREEN)"[CLEAN]" $(C_BASE)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
