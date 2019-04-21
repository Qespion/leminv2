/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_fail.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 18:26:26 by oespion           #+#    #+#             */
/*   Updated: 2019/04/21 13:15:35 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

void	malloc_fail_base(t_map *map, t_solve *solution)
{
	t_road	*tmp;
	t_solve	*tmp_sol;

	while (solution)
	{
		tmp_sol = solution->next;
		while (solution->path)
		{
			tmp = solution->path->prev;
			free(solution->path);
			solution->path = tmp;
		}
		free(solution);
		solution = tmp_sol;
	}
	ft_clean_map(map);
	ft_printf("\e[31;1mMalloc failed\033[0m\n");
	exit(-1);
}

int		no_path(t_map *map)
{
	t_node	*begin;

	begin = map->begin;
	while (begin)
	{
		if (begin->link)
			return (1);
		begin = begin->next;
	}
	return (0);
}

int		is_valid(t_map *map)
{
	if (!no_path(map) || !map->start || !map->end || !map->start->link)
		return (0);
	return (1);
}

void	free_road(t_road *road)
{
	t_road	*tmp;

	while (road)
	{
		tmp = road->prev;
		free(road);
		road = tmp;
	}
}
