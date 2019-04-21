/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_routes_nnnode.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 13:17:49 by oespion           #+#    #+#             */
/*   Updated: 2019/04/21 13:19:32 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

void	malloc_fail_create(t_solve *routes, t_map *map)
{
	t_road	*tmp_road;
	t_solve	*tmp;

	while (routes)
	{
		tmp = routes->next;
		while (routes->path)
		{
			tmp_road = routes->path->prev;
			free(routes->path);
			routes->path = tmp_road;
		}
		free(routes);
		routes = tmp;
	}
	ft_clean_map(map);
	ft_printf("\e[31;1mMalloc failed\033[0m\n");
	exit(-1);
}

int		found_finish(t_solve *routes, t_map *map)
{
	while (routes)
	{
		if (routes->path->current == map->end)
			return (1);
		routes = routes->next;
	}
	return (0);
}

void	free_node(t_solve *del)
{
	t_road	*tmp;

	while (del->path)
	{
		tmp = del->path->prev;
		free(del->path);
		del->path = tmp;
	}
	free(del);
}

int		check_loop(t_node *dest, t_road *road)
{
	while (road)
	{
		if (road->current == dest)
			return (1);
		road = road->prev;
	}
	return (0);
}

void	read_current(t_solve *solution)
{
	ft_printf("--current state\n");
	while (solution)
	{
		ft_printf("%s\n", solution->path->current->name);
		solution = solution->next;
	}
	ft_printf("------\n");
}
