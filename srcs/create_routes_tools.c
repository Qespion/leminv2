/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_routes_tools.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 13:19:52 by oespion           #+#    #+#             */
/*   Updated: 2019/04/21 13:22:26 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

t_wroad	*ft_garbage_wroad(t_wroad *wroad)
{
	t_wroad		*tmp_wroad;
	t_road		*tmp_road;
	t_conflict	*tmp_conflict;

	while (wroad)
	{
		tmp_wroad = wroad->next;
		while (wroad->conflict)
		{
			tmp_conflict = wroad->conflict->next;
			free(wroad->conflict);
			wroad->conflict = tmp_conflict;
		}
		while (wroad->path)
		{
			tmp_road = wroad->path->prev;
			free(wroad->path);
			wroad->path = tmp_road;
		}
		free(wroad);
		wroad = tmp_wroad;
	}
	return (NULL);
}

t_solve	*ft_garbage(t_solve *routes)
{
	t_solve *tmp_routes;
	t_road	*tmp_road;

	while (routes)
	{
		tmp_routes = routes->next;
		while (routes->path)
		{
			tmp_road = routes->path->prev;
			free(routes->path);
			routes->path = tmp_road;
		}
		free(routes);
		routes = tmp_routes;
	}
	return (NULL);
}

t_road	*duplicate_road(t_road *old)
{
	t_road	*start;
	t_road	*road;
	t_road	*tmp;

	tmp = NULL;
	while (old)
	{
		if (!(road = (t_road*)malloc(sizeof(t_road))))
			exit(-1);
		road->current = old->current;
		if (tmp)
			tmp->prev = road;
		else
			start = road;
		tmp = road;
		old = old->prev;
	}
	road->prev = NULL;
	return (start);
}

t_solve	*create_road(t_solve *tmp, t_solve *new_routes, t_link *link)
{
	t_solve	*temp;
	t_solve	*new_solve;
	t_road	*new_road;

	if (!(new_solve = (t_solve*)malloc(sizeof(t_solve))))
		exit(-1);
	if (!(new_road = (t_road*)malloc(sizeof(t_road))))
		exit(-1);
	new_solve->next = NULL;
	new_solve->path = new_road;
	new_road->current = link->node;
	new_road->prev = duplicate_road(tmp->path);
	if (!new_routes)
	{
		new_solve->prev = NULL;
		return (new_solve);
	}
	temp = new_routes;
	while (temp->next)
		temp = temp->next;
	temp->next = new_solve;
	new_solve->prev = temp;
	return (new_routes);
}

t_solve	*add_routes(t_solve *new_routes, t_solve *tmp, t_map *map)
{
	t_link	*link_node;

	link_node = tmp->path->current->link;
	while (link_node)
	{
		if (check_loop(link_node->node, tmp->path)
			|| link_node->node == map->start)
		{
			link_node = link_node->next;
			continue ;
		}
		new_routes = create_road(tmp, new_routes, link_node);
		link_node = link_node->next;
	}
	return (new_routes);
}
