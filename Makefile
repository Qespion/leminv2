.PHONY: all lem_in lib clean fclean re
CC		=	gcc
FLAGS   =   -Wall -Wextra -Werror
LIB_DIR =   libft/
NAME1	=	lem-in
NAME2	=	visu

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

SRCS_2	=	srcs/visu.c \
			srcs/visu_get_result.c \
			srcs/visu_room.c \
			srcs/visu_fill_map.c \
			srcs/visu_get_tube.c \
			srcs/visu_link.c \
			srcs/visu_bresenham.c \
			srcs/visu_pixel.c \
			srcs/visu_mlx.c \
			srcs/visu_place_party.c \
			srcs/visu_draw_element.c \
			srcs/visu_get_reponse.c \
			srcs/ft_strsplit.c \
			srcs/visu_place_ants.c \
			srcs/visu_move.c \
			srcs/visu_bresenmove.c \
			srcs/visu_move_ant.c \
			srcs/visu_start_ants.c \
			srcs/visu_make_a_move.c \
			srcs/visu_draw_ants.c \
			srcs/visu_free.c \
			srcs/visu_fill_circle.c \
			srcs/visu_draw_circle.c \
			srcs/visu_handle_key.c \
			srcs/visu_parse.c \
			srcs/visu_print_ath.c \
			srcs/visu_map_input.c \

LIBFT	=	libft/libft.a
MLX 	=	mlx/ -lmlx -framework OpenGL -framework AppKit

C_GREEN	=	"\033[32m"
C_BLUE	=	"\033[36m"
C_BASE	=	"\033[00m"
PRINTF=test $(VERBOSE)$(TRAVIS) || printf
OBJS1    =   $(SRCS_1:.c=.o)
OBJS2    =   $(SRCS_2:.c=.o)

all:	lib lem_in visu

lib:
	@make -C libft/
	@ @$(PRINTF) "Libft:	"
	@ @$(PRINTF) "\x1b[32m✔\x1b[0m\n\n"

lem_in: $(OBJS1) $(OBJS2)
	@ @echo $(C_GREEN)"----" $(C_BASE)
	@$(CC) $(FLAGS) $(OBJS1) -L libft/ -lft -o $(NAME1)
	@$(CC) $(FLAGS) $(OBJS2) -L $(MLX) -L libft/ -lft -o $(NAME2)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@ -I includes/
	@ @echo "file =" $(C_BLUE){ $< } $(C_BASE)

clean:
	@make -C libft/ clean
	@rm -f $(OBJS1) $(OBJS2)

fclean:     clean
	@rm -f $(NAME1) $(NAME2) $(LIBFT)

re:         fclean all