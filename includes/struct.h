/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 16:27:53 by oespion           #+#    #+#             */
/*   Updated: 2019/05/03 23:09:30 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

unsigned int			g_flags;

typedef struct			s_link
{
	struct s_node		*node;
	struct s_link		*next;
}						t_link;

typedef struct			s_node
{
	int					bfs;
	char				*name;
	struct s_link		*link;
	struct s_node		*next;
}						t_node;

typedef struct			s_map
{
	int					valid;
	int					nb;
	struct s_node		*jcpu;
	struct s_node		*start;
	struct s_node		*end;
	struct s_node		*begin;
}						t_map;

typedef struct			s_road
{
	struct s_node		*current;
	struct s_road		*prev;
}						t_road;

typedef struct			s_solve
{
	struct s_road		*path;
	struct s_solve		*next;
	struct s_solve		*prev;
}						t_solve;

typedef struct			s_conflict
{
	int					conflict;
	struct s_conflict	*next;
}						t_conflict;

typedef struct			s_wroad
{
	int					nb;
	int					len;
	struct s_road		*path;
	struct s_wroad		*next;
	struct s_conflict	*conflict;
}						t_wroad;

typedef struct			s_journey
{
	int					bib_nb;
	struct s_wroad		*wroad;
	struct s_node		*node;
}						t_journey;

typedef struct			s_pack
{
	struct s_journey	*player;
	struct s_pack		*nxt;
}						t_pack;

typedef struct			s_room
{
	char				*name;
	int					index;
	int					x;
	int					y;
	int					start;
	int					end;
	struct s_room		*next;
	struct s_tube		*link;
}						t_room;

typedef	struct			s_tube
{
	struct s_room		*room;				
	struct s_tube		*next;
	int					test;
}						t_tube;

typedef struct			s_visu
{
	char				**turn;
	char				*result;
	int					nbr_of_ants;
	int					map_finished;
	int					tube_finished;
	struct s_room		*room;
	int					nbr_room;
}						t_visu;

typedef struct 			s_point
{
	int					x;
	int 				y;
}						t_point;

typedef struct			s_img
{
	void				*img_ptr;
	int					*data;
	int					bpp;
	int					size_l;
	int					endian;
}						t_img;

typedef struct 			s_mlx
{
	void				*mlx_ptr;
	void				*win_ptr;
	t_img				img;
}						t_mlx;

typedef	struct			s_party
{
	int					turn;
	int					pause;
	int					i;
	struct s_mlx		mlx;
}						t_party;

typedef struct			s_line
{
	int					dx;
	int					dy;
	int					dp;
	int					delta_e;
	int					delta_ne;
}						t_line;

#endif
