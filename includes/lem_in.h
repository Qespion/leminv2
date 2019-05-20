/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 16:27:53 by oespion           #+#    #+#             */
/*   Updated: 2019/05/20 20:13:52 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "struct.h"
# include <mlx.h>

# define MAXROADS		(1U << 0U)
# define FIRSTROADS		(1U << 1U)
# define NBWORKING		(1U << 2U)
# define GRAPH			(1U << 3U)
# define ROADGESTION	(1U << 4U)
# define LINENB			(1U << 5U)
# define WIDTH			2560
# define HEIGHT			1390
# define BACKSCREEN		0x51556C
# define ROOM			0xffffff
# define ROOM_COLOR		0x00b9f7
# define ANT			0xff0000
# define NAME			0x000000
# define START			0x08ff00
# define END			0xff004c

int		get_max_roads(t_map *map);
t_solve	*create_base_routes(t_map *map);
void	ft_clean_map(t_map *map);
t_solve	*create_routes(t_map *map, int max_roads, t_solve *routes);
int		enough_wroad(t_wroad *wroad, t_map *map, int turn, int max_roads);
t_wroad	*found_finish_line(t_solve *solution, t_map *map, t_wroad *wroad);
void	ft_create_group(t_wroad *wroad, t_map *map);
int		*bt_grp(int **tab, int len, int ants);
void	get_best_road(int *line, int ants, t_wroad *wroad);
t_solve	*epur_map(t_solve *solve);
t_map	*nget_file();
void	malloc_fail_base(t_map *map, t_solve *solution);
int		is_valid(t_map *map);
void	free_road(t_road *road);
int		ft_wroad_len(t_wroad *wroad);
int		*ft_get_turn(t_wroad *wroad, t_wroad *current, t_map *map, int len);
t_wroad	*check_conflict(t_wroad *wroad, t_map *map);
t_wroad	*ft_find_conflict(t_wroad *wroad, t_map *map);
void	ft_print_line(int *line, int len);
int		*create_malloc_line(int *line, int len);
int		*copy_tmp_line(int *try_line, int *tmp_line, int len);
int		*ft_solution(int *try, int len, int **tab, int r);
int		check_lines(int *l_one, int *l_two, int len);
int		calc_nb_turn(int *line, int ants, int len);
int		check_loop(t_node *dest, t_road *road);
t_wroad	*ft_garbage_wroad(t_wroad *wroad);
t_solve	*ft_garbage(t_solve *routes);
t_road	*duplicate_road(t_road *old);
t_solve	*add_routes(t_solve *new_routes, t_solve *tmp, t_map *map);
int		len_wroad(t_wroad *wroad);
int		len_road(t_solve *routes);
void	init_wroad(t_wroad **wroad, t_solve **routes, t_map *map);
t_map	*get_ants(char *str, t_map *map);
void	double_end(int which_end);
t_map	*error_case(t_map *map, int *start, int *end, t_node *new_node);
int		error_road(char *name1, char *name2, t_node **tmp, t_node **tmp2);
void	link_wo_island(t_map *map);
void	check_valid_island(char *str);
t_map	*get_island(char *str, t_map *map);
t_map	*add_line(char *str, t_map *map, int turn);
int		check_turn(char *str, int turn, t_map *map);
void	check_double_road(t_node *tmp, t_link *last_link, t_map *map);
int		find_del(char *str);
int		*transform_line(int *line, int ants, int len);
int		*create_base(int len);
void	send_player(t_pack **start, t_pack **np, t_pack **lt, t_journey **play);
t_pack	*remove_from_field(t_pack *start, t_pack *rm);

/*
**	visu
*/

t_room	*get_room_by_name(t_visu *visu, char *name);
t_rstep	*get_rstep(int step, t_rstep *rstep);
t_room	*get_start_room(t_visu *visu);
char	**ft_strsplit(const char *str, char c);
int		put_line(t_point *point1, t_point *point2, t_mlx *mlx, int color);
int		ft_put_pixel(t_mlx *mlx, int x, int y, int color);
int		get_result(t_visu *visu);
int		quit_visu(t_party *party);
int		init_mlx(t_visu *visu, t_party *party);
int		draw(t_party *party, t_visu *visu);
int		handle_key(int key, t_party *party);
int		draw_link(t_party *party, t_room *last, t_tube *tube);
int		print_lines(t_point *point1, t_point *point2, t_mlx *mlx, int color);
int		add_room(t_visu *visu, char *str, int special);
int		draw_room(t_party *party, t_room *last);
int		add_reponse(t_visu *visu, char *str);
int		add_move(t_rstep *rstep, int x, int y);
int		add_link(t_visu *visu, t_room *room, char *name);
void	fill_map(t_visu *visu, char *str);
void	get_link(t_visu *visu, char *str);
void	vertical_limit(t_point *point1, t_point *point2, t_mlx *mlx, int color);
void	place_party(t_visu *visu, t_party *party);
void	put_square(t_party *party, t_point corner, int x, int y);
void	draw_circle(t_party *party, int *centre_xy, int radius, int color);
void	fill_circle(t_party *party, int *centre_xy, int radius, int color);
void	color_room(t_party *party, t_room *last);
void	add_ant(t_visu *visu, int i);
int		place_ants(t_visu *visu, t_party *party);
void	get_move(t_ant **ant, t_room *dest, int step);
void	bresenmove(t_point *point1, t_point *point2, t_rstep *rstep);
void	make_a_move(t_visu *visu, t_party *party);
void	vertical_move(t_point *point1, t_point *point2, t_rstep *rstep);
void	add_name(t_visu *visu, t_party *party);
int		handle_mouse(int x, int y, t_party *party);
int		mouse_press(int button, int x, int y, t_party *party);
void	start_ants(t_visu *visu, t_party *party);
void	add_rstep(t_ant *ant, int step);
void	draw_all_ants(t_party *party, t_visu *visu);
void	free_ant_move(t_visu *visu);
void	init_rstep(t_visu *visu, int step);
void	free_prog(t_visu *visu, t_party *party);
void	parse(t_visu *visu, char *str, int *turn);
void	add_ant_name(t_visu *visu, t_party *party);
void	print_ath(t_visu *visu, t_party *party);

#endif
