/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_routes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 10:00:49 by oespion           #+#    #+#             */
/*   Updated: 2019/03/20 13:38:09 by oespion          ###   ########.fr       */
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

t_wroad	*ft_garbage_wroad(t_wroad *wroad)
{
	t_wroad	*tmp_wroad;
	t_road	*tmp_road;
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
    t_road  *tmp_road;

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
	t_road	*old_road;
	if (!(new_solve = (t_solve*)malloc(sizeof(t_solve))))
		exit(-1);
	if (!(new_road = (t_road*)malloc(sizeof(t_road))))
		exit(-1);
	new_solve->next = NULL;
	new_solve->path = new_road;
	new_road->current = link->node;
	new_road->prev = duplicate_road(tmp->path);
	if (!new_routes)
		return (new_solve);
	temp = new_routes;
	while (temp->next)
		temp = temp->next;
	temp->next = new_solve;
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
		new_routes = create_road(tmp, new_routes, link_node);
		link_node = link_node->next;
	}
	return (new_routes);
}

int			check_roads(t_road	*road, t_node *end)
{
	while (road)
	{
		if (road->current == end)
			return (0);
		road = road->prev;
	}
	return (1);
}

t_solve	*remove_finish_line(t_solve *new_routes, t_map *map)
{
	t_solve	*tmp;

	while (!check_roads(new_routes->path, map->end))
		new_routes = new_routes->next;
	tmp = new_routes;
	while (tmp->next)
	{
		if (!check_roads(tmp->next->path, map->end))
			tmp->next = tmp->next->next;
		tmp = tmp->next;
	}
	return (new_routes);
}

int			len_road(t_solve *routes)
{
	int	r;

	r = 0;
	while (routes)
	{
		routes = routes->next;
		r++;
	}
	return (r);
}

t_solve *create_routes(t_map *map, int max_roads, t_solve *routes)
{
	int turn;
	t_solve *tmp;
	t_solve	*new_routes;
	t_wroad	*wroad;

	turn = 0;
	new_routes = NULL;
	wroad = NULL;
	wroad = found_finish_line(routes, map, wroad);
	if (!wroad)
	{
		while ((new_routes || routes) && !enough_wroad(wroad, map, turn, max_roads))
		{
			if (new_routes)
				routes = new_routes;
			tmp = routes;
			new_routes = NULL;
			ft_printf("turn %d\n", ++turn);
			// new_routes = ft_jcompren_pa(routes);
			while(tmp)
			{
				if (tmp->path->current == map->end)
				{
					tmp = tmp->next;
					continue ;
				}
				new_routes = add_routes(new_routes, tmp, map);
				tmp = tmp->next;
			}
			routes = ft_garbage(routes);
			wroad = found_finish_line(new_routes, map, wroad);
			// new_routes = remove_finish_line(new_routes, map);
			// ft_printf("test-> %s\n", new_routes->path->current->name);
			// read_current(new_routes);
			// if (len_road(new_routes) == 0)
			// 	break ;
			ft_printf("len roads %d\n", len_road(new_routes));
		}
	}
	print_working_roads(wroad, map);
	wroad = ft_find_conflict(wroad, map);
	// new_routes = ft_garbage(new_routes);
	ft_create_group(wroad, map, max_roads);
	wroad = ft_garbage_wroad(wroad);
	ft_printf("found finish !\n");
	ft_printf("max roads %d !\n", max_roads);
	return (routes);
}
