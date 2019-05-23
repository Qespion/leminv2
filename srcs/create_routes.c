/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_routes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 10:00:49 by oespion           #+#    #+#             */
/*   Updated: 2019/05/23 14:07:38 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

void	init_new_routes(t_solve **new_routes, t_solve **routes, t_solve **tmp)
{
	if (*new_routes)
		*routes = *new_routes;
	*tmp = *routes;
	*new_routes = NULL;
}

void	loop_tmp(t_solve **tmp, t_solve **nroutes, t_map *map, t_solve **routes)
{
	while (*tmp)
	{
		if ((*tmp)->path->current == map->end)
		{
			*tmp = (*tmp)->next;
			continue ;
		}
		*nroutes = add_routes(*nroutes, *tmp, map);
		*tmp = (*tmp)->next;
	}
	*routes = ft_garbage(*routes);
}

void	check_err_road(t_wroad **wroad, t_map *map, t_solve **nr)
{
	if (!(*wroad))
	{
		ft_printf("\e[31;1mERROR\033[0m\n");
		exit(2);
	}
	*wroad = ft_find_conflict(*wroad, map);
	*nr = ft_garbage(*nr);
	ft_create_group(*wroad, map);
}

t_solve	*create_routes(t_map *map, int m, t_solve *routes)
{
	int		turn;
	t_solve *tmp;
	t_solve	*new_routes;
	t_wroad	*wroad;

	turn = 0;
	new_routes = NULL;
	init_wroad(&wroad, &routes, map);
	if (!wroad)
	{
		while ((new_routes || routes) && !enough_wroad(wroad, map, turn, m))
		{
			init_new_routes(&new_routes, &routes, &tmp);
			loop_tmp(&tmp, &new_routes, map, &routes);
			wroad = found_finish_line(new_routes, map, wroad);
			if (len_road(new_routes) == 0)
				break ;
			new_routes = epur_map(new_routes);
			if (g_flags & NBWORKING)
				ft_printf("len of working roads: %d\n", len_wroad(wroad));
		}
		check_err_road(&wroad, map, &new_routes);
	}
	wroad = ft_garbage_wroad(wroad);
	return (routes);
}
