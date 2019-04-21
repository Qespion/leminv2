/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 16:27:53 by oespion           #+#    #+#             */
/*   Updated: 2019/04/21 16:00:10 by oespion          ###   ########.fr       */
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
t_map	*get_file();
t_solve	*create_base_routes(t_map *map);
void	ft_clean_map(t_map *map);
t_solve	*create_routes(t_map *map, int max_roads, t_solve *routes);
int		enough_wroad(t_wroad *wroad, t_map *map, int turn, int max_roads);
t_wroad	*found_finish_line(t_solve *solution, t_map *map, t_wroad *wroad);
t_road	*duplicate_road(t_road *old);
t_wroad	*ft_find_conflict(t_wroad *wroad, t_map *map);
void	ft_create_group(t_wroad *wroad, t_map *map);
int		*bt_grp(int **tab, int len, int ants);
void	get_best_road(int *line, int ants, t_wroad *wroad);
int		ft_wroad_len(t_wroad *wroad);
t_solve	*epur_map(t_solve *solve);
t_map	*nget_file();
void	malloc_fail_base(t_map *map, t_solve *solution);
int		is_valid(t_map *map);
int		no_path(t_map *map);
void	free_road(t_road *road);



/*
**	group_tool functions -> from calc_grp
*/

int		ft_wroad_len(t_wroad *wroad);
int		*init_tab(int *tab, int len);
int		ft_check_conflict(t_conflict *current, int r);
int		ft_get_len(int r, t_wroad *wroad);
int		*ft_get_turn(t_wroad *wroad, t_wroad *current, t_map *map, int len);


/*
**	check_conflict -> from find conflict
*/

void	ft_list_conflict(t_conflict **tmp, t_wroad **list, t_conflict **lbs);
void	ft_add_conflict(t_wroad *wroad, t_wroad *list);
int		ft_deep_check(t_road *base_road, t_road *tmp_road, t_map *map);
t_wroad	*check_conflict(t_wroad *wroad, t_map *map);
t_wroad	*ft_find_conflict(t_wroad *wroad, t_map *map);

/*
**	tool_comb_grp -> from comb_grp
*/

void	ft_print_line(int *line, int len);
int		*set_zero(int *roads, int len, int **tab, int r);
int		*create_malloc_line(int *line, int len);
int		*copy_tmp_line(int *try_line, int *tmp_line, int len);
int		*ft_solution(int *try, int len, int **tab, int r);

/*
** find_comb_grp -> from comb_grp
*/

int		check_lines(int *l_one, int *l_two, int len);
int		calc_nb_road(int *line, int len);
int		calc_nb_turn(int *line, int ants, int len);

/*
**	create_routes_nnodes -> from create_routes
*/

void	malloc_fail_create(t_solve *routes, t_map *map);
int		found_finish(t_solve *routes, t_map *map);
void	free_node(t_solve *del);
int		check_loop(t_node *dest, t_road *road);
void	read_current(t_solve *solution);

/*
** create_routes_tools -> from create_routes
*/

t_wroad	*ft_garbage_wroad(t_wroad *wroad);
t_solve	*ft_garbage(t_solve *routes);
t_road	*duplicate_road(t_road *old);
t_solve	*create_road(t_solve *tmp, t_solve *new_routes, t_link *link);
t_solve	*add_routes(t_solve *new_routes, t_solve *tmp, t_map *map);

/*
**	create_routes_wroad -> from create_routes
*/

int		check_roads(t_road *road, t_node *end);
t_solve	*remove_finish_line(t_solve *new_routes, t_map *map);
int		len_wroad(t_wroad *wroad);
int		len_road(t_solve *routes);
void	init_wroad(t_wroad **wroad, t_solve **routes, t_map *map);

#endif
