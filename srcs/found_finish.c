/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_finish.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 21:23:40 by oespion           #+#    #+#             */
/*   Updated: 2019/04/19 15:22:42 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

t_solve		*remove_line(t_solve *solution, t_map *map)
{
	t_solve	*tmp;

	while (solution->path->current == map->end
		|| solution->path->current == map->start)
		solution = solution->next;
	tmp = solution;
	while (tmp)
	{
		if (tmp->next && tmp->next->path->current == map->end)
			tmp->next = tmp->next->next;
		if (tmp->next && tmp->next->path->current == map->start)
			tmp->next = tmp->next->next;
		tmp = tmp->next;
	}
	return (solution);
}

int			ft_len_road(t_road *road)
{
	int		len;
	t_road	*tmp;

	tmp = road;
	len = 0;
	while (tmp)
	{
		tmp = tmp->prev;
		len++;
	}
	return (len);
}

void		finish_line_wroad(t_wroad **wroad, t_wroad **nnode, t_wroad **tmp)
{
	if (!(*wroad))
	{
		*wroad = *nnode;
		(*wroad)->nb = 0;
		*tmp = *nnode;
	}
	else
	{
		while ((*wroad)->next)
			*wroad = (*wroad)->next;
		(*wroad)->next = *nnode;
		(*wroad)->next->nb = (*wroad)->nb + 1;
	}
}

t_wroad		*found_finish_line(t_solve *solution, t_map *map, t_wroad *wroad)
{
	t_wroad	*new_node;
	t_wroad	*tmp;

	tmp = wroad;
	while (solution)
	{
		if (solution->path->current == map->end)
		{
			if (!(new_node = (t_wroad*)malloc(sizeof(t_wroad))))
				exit(-1);
			new_node->path = duplicate_road(solution->path);
			new_node->next = NULL;
			new_node->conflict = NULL;
			new_node->len = ft_len_road(solution->path);
			finish_line_wroad(&wroad, &new_node, &tmp);
		}
		solution = solution->next;
	}
	return (tmp);
}

int			enough_wroad(t_wroad *wroad, t_map *map, int turn, int max_roads)
{
	int		len_wroad;
	t_wroad	*tmp;

	len_wroad = 0;
	tmp = wroad;
	while (tmp)
	{
		tmp = tmp->next;
		len_wroad++;
	}
	if (len_wroad / 4 > max_roads)
		return (1);
	if (wroad && turn > (wroad->len + map->nb))
		return (1);
	return (0);
}
