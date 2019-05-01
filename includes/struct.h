/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 16:27:53 by oespion           #+#    #+#             */
/*   Updated: 2019/04/30 16:30:57 by oespion          ###   ########.fr       */
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

#endif
