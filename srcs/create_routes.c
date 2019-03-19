/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_routes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avo <avo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 09:40:13 by avo               #+#    #+#             */
/*   Updated: 2019/03/19 13:52:14 by avo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

int            found_finish(t_solve *routes, t_map *map)
{
	while (routes)
	{
		if (routes->path->current == map->end)
			return (1);
		routes = routes->next;
	}
	return (0);
}

void        free_node(t_solve *del)
{
	t_road  *tmp;

	while (del->path)
	{
		tmp = del->path->prev;
		free(del->path);
		del->path = tmp;
	}
	free(del);
}

int			check_loop(t_node *dest, t_road *road)
{
	while (road)
	{
		if (road->current == dest)
			return (1);
		road = road->prev;
	}
	return (0);
}

t_solve	*create_road(t_road *tmp, t_solve *new_routes, t_link *link)
{
	t_solve	*end_new;
	t_solve	*new_node;
	t_road	*road;
	t_road	*cpy;
	t_road	*lroad;
	
	if (!(new_node = (t_solve*)malloc(sizeof(t_solve))))
		exit(-1);
	if (!(road = (t_road*)malloc(sizeof(t_road))))
		exit(-1);
	if (!(road->current = (t_node*)malloc(sizeof(t_node))))
		exit(-1);
	ft_printf("FDS\n");
	memcpy(road->current, link->node, sizeof(road->current));
	new_node->path = road;
	// road->current = link->node;
	ft_printf("road %s\n", road->current->name);
	exit(-1);
	lroad = road;
	while (tmp)
	{
		if (!(cpy = (t_road*)malloc(sizeof(t_road))))
			exit(-1);
		if (!(cpy->current = (t_node*)malloc(sizeof(t_node))))
			exit(-1);
		memcpy(cpy->current, tmp->current, sizeof(tmp->current));
		// cpy->current = tmp->current;
		lroad->prev = cpy;
		lroad = tmp;
		tmp = tmp->prev;
	}
	cpy->prev = NULL;
	new_node->next = NULL;
	if (!new_routes)
		return (new_node);
	end_new = new_routes;
	while (end_new->next)
		end_new = end_new->next;
	end_new->next = new_node;
	return (new_routes);
}

t_solve	*add_routes(t_solve *new_routes,  t_solve *tmp, t_map *map)
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
		new_routes = create_road(tmp->path, new_routes, link_node);
		link_node = link_node->next;
	}
	return (new_routes);
}

void		read_current(t_solve *solution)
{
	ft_printf("--current state\n");
	while (solution)
	{
		ft_printf("%s\n", solution->path->current->name);
		solution = solution->next;
	}
	ft_printf("------\n");
}

t_solve	*ft_garbage(t_solve *routes)
{
	t_solve	*tmp_routes;
	t_road	*tmp;
	while (routes)
	{
		// while (routes->path)
		// {
		// 	tmp = routes->path->prev;
		// 	routes->path = NULL;
		// 	free(routes->path);
		// 	routes->path = tmp;
		// }
		tmp_routes = routes->next;
		free(routes);
		// routes = NULL;
		routes = tmp_routes;
	}
	return (NULL);
}

t_solve *create_routes(t_map *map, int max_roads, t_solve *routes)
{
	int turn;
	t_solve *tmp;
	t_solve	*new_routes;
	t_solve	*garbage;

	turn = 0;
	new_routes = NULL;
	garbage = NULL;
	while (!found_finish(new_routes, map))
	{
		if (new_routes)
			routes = new_routes;
		tmp = routes;
		new_routes = NULL;
		ft_printf("turn %d\n", ++turn);
		while(tmp)
		{
			new_routes = add_routes(new_routes, tmp, map);
			tmp = tmp->next;
		}
		routes = ft_garbage(routes);
		read_current(new_routes);
		if (turn == 3)
			exit(1);
	}
	new_routes = ft_garbage(new_routes);
	ft_printf("found finish !\n");
	return (routes);
}
