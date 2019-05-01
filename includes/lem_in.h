/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 16:27:53 by oespion           #+#    #+#             */
/*   Updated: 2019/05/01 12:53:03 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "struct.h"

# define MAXROADS		(1U << 0U)
# define FIRSTROADS		(1U << 1U)
# define NBWORKING		(1U << 2U)
# define GRAPH			(1U << 3U)
# define ROADGESTION	(1U << 4U)
# define LINENB			(1U << 5U)

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

#endif
