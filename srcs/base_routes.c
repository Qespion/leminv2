/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_routes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avo <avo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 16:28:22 by oespion           #+#    #+#             */
/*   Updated: 2019/03/05 13:48:10 by avo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

/*
**  create base routes at start
*/

t_road	*start_road(t_map *map)
{
	t_road	*road;
	if (!(road = (t_road*)malloc(sizeof(t_road))))
		exit(-1);
	road->prev = NULL;
	road->current = map->start;
	return (road);
}

t_solve     *get_first_roads(t_solve *solution, t_map *map)
{
	t_link		*tmp;
	t_road		*road;
	t_solve		*next_sol;
	t_solve		*start;

	tmp = map->start->link;
	start = solution;
	while (tmp)
	{
		if (!(road = (t_road*)malloc(sizeof(t_road))))
			exit(-1);
		road-> current = tmp->node;
		road->prev = start_road(map);
		if (!solution->path)
			solution->path = road;
		else
		{
			if (!(next_sol = (t_solve*)malloc(sizeof(t_solve))))
				exit(-1);
			solution->next = next_sol;
			next_sol->path = road;
			next_sol->next = NULL;
			solution = next_sol;
		}
		tmp = tmp->next;
	}
	return start;
}

void	ft_print_solution(t_solve * solution)
{
	t_solve	*tmp;

	tmp = solution;
	while (tmp)
	{
		ft_printf("first node: %s\n", tmp->path->current->name);
		tmp = tmp->next;
	}
}

t_solve    *create_base_routes(t_map *map, int max_roads)
{
    t_solve   *solution;

	if (!(solution = (t_solve*)malloc(sizeof(t_solve))))
        exit(-1);
    solution->path = NULL;
    solution->next = NULL;
    solution = get_first_roads(solution, map);
	ft_print_solution(solution);
	// exit(-32);
	return solution;
}