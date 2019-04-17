/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 16:27:53 by oespion           #+#    #+#             */
/*   Updated: 2019/04/17 14:21:38 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# define MAXROADS	(1U << 0U)
# define FIRSTROADS	(1U << 1U)
# define NBWORKING	(1U << 2U)
# define GRAPH		(1U << 3U)
# define ROADGESTION	(1U << 4U)
# define LINENB	(1U << 5U)

unsigned int	g_flags;

typedef struct		s_link
{
	struct s_node	*node;
	struct s_link	*next;
}							t_link;

typedef struct		s_node
{
	char			*name;
	struct s_link	*link;
	struct s_node	*next;
}							t_node;

typedef struct		s_map
{
	int				nb;
	struct s_node	*jcpu;  // argh
	struct s_node	*start; //starting point
	struct s_node	*end;
	struct s_node	*begin;	//start of chain
}					t_map;

typedef struct		s_road
{
	struct s_node	*current;
	struct s_road	*prev;
}					t_road;

typedef struct		s_solve
{
	struct s_road	*path;
	struct s_solve	*next;
	struct s_solve	*prev;
}					t_solve;

typedef struct		s_conflict
{
	int						conflict;
	struct s_conflict *next;
}							t_conflict;

typedef struct		s_wroad
{
	int							nb;
	int							len;
	struct s_road		*path;
	struct s_wroad 		*next;
	struct s_conflict	*conflict;
}								t_wroad;

typedef struct		s_journey
{
	int						bib_nb;
	struct s_wroad	*wroad;
	struct s_node	*node;
}							t_journey;

typedef struct		s_pack
{
	struct s_journey *player;
	struct s_pack		*nxt;
}							t_pack;

int			get_max_roads(t_map *map);
t_map		*get_file();
t_solve		*create_base_routes(t_map *map);
void	print_working_roads(t_wroad *wroad, t_map *map);
void	ft_clean_map(t_map *map);

t_solve *create_routes(t_map *map, int max_roads, t_solve *routes);
int			enough_wroad(t_wroad *wroad, t_map *map, int turn, int max_roads);
t_wroad		*found_finish_line(t_solve *solution, t_map *map, t_wroad *wroad);
t_road	*duplicate_road(t_road *old);
t_wroad		*ft_find_conflict(t_wroad *wroad, t_map *map);
void    ft_create_group(t_wroad *wroad, t_map *map, int max_roads);
int	*bt_grp(int **tab, int len, int ants);
void    get_best_road(int *line, int ants, int max_roads, t_wroad *wroad);
int		ft_wroad_len(t_wroad *wroad);

void	ft_print_line(int *line, int len);
t_solve *epur_map(t_solve *solve);
t_map   *nget_file();

#endif
