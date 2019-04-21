/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_routes_wroad.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 13:22:48 by oespion           #+#    #+#             */
/*   Updated: 2019/04/21 13:42:29 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

int		check_roads(t_road *road, t_node *end)
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

int		len_wroad(t_wroad *wroad)
{
	int	r;

	r = 0;
	while (wroad)
	{
		wroad = wroad->next;
		r++;
	}
	return (r);
}

int		len_road(t_solve *routes)
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

void	init_wroad(t_wroad **wroad, t_solve **routes, t_map *map)
{
	*wroad = NULL;
	*wroad = found_finish_line(*routes, map, *wroad);
	if (*wroad)
	{
		*wroad = ft_find_conflict(*wroad, map);
		ft_create_group(*wroad, map);
		*routes = ft_garbage(*routes);
	}
}
