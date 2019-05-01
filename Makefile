.PHONY: all lem_in lib clean fclean re
CC		=	gcc
FLAGS   =   -Wall -Wextra -Werror
LIB_DIR =   libft/
NAME1	=	lem-in

SRCS_1	=   srcs/lem_in.c	\
			srcs/base_routes.c	\
			srcs/max_roads.c	\
			srcs/clean_map.c	\
			srcs/create_routes.c	\
			srcs/found_finish.c	\
			srcs/ft_find_conflict.c	\
			srcs/calc_grp.c	\
			srcs/comb_grp.c	\
			srcs/print_roads.c	\
			srcs/olapping_map.c \
			srcs/parsing.c	\
			srcs/malloc_fail.c	\
			srcs/group_tool.c \
			srcs/ft_check_conflict.c	\
			srcs/find_comb_grp.c	\
			srcs/tool_comb_grp.c	\
			srcs/create_routes_nnnode.c	\
			srcs/create_routes_tools.c	\
			srcs/create_routes_wroad.c	\
			srcs/parsing_island.c	\
			srcs/parsing_roads.c	\
			srcs/parsing_err.c	\
			srcs/transform_line.c	\
			srcs/get_pack.c

LIBFT	=	libft/libft.a

C_GREEN	=	"\033[32m"
C_BLUE	=	"\033[36m"
C_BASE	=	"\033[00m"
PRINTF=test $(VERBOSE)$(TRAVIS) || printf
OBJS1    =   $(SRCS_1:.c=.o)

all:	lib lem_in

lib:
	@make -C libft/
	@ @$(PRINTF) "Libft:	"
	@ @$(PRINTF) "\x1b[32m✔\x1b[0m\n\n"

lem_in: $(OBJS1)
	@ @echo $(C_GREEN)"----" $(C_BASE)
	@$(CC) $(FLAGS) $(OBJS1) -L libft/ -lft -o $(NAME1)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@ -I includes/
	@ @echo "file =" $(C_BLUE){ $< } $(C_BASE)

clean:
	@make -C libft/ clean
	@rm -f $(OBJS1)

fclean:     clean
	@rm -f $(NAME1) $(LIBFT)

re:         fclean all