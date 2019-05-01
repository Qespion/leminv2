/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_routes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 16:28:22 by oespion           #+#    #+#             */
/*   Updated: 2019/05/01 11:30:19 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

t_road		*start_road(t_map *map, t_solve *solution)
{
	t_road	*road;

	if (!(road = (t_road*)malloc(sizeof(t_road))))
		malloc_fail_base(map, solution);
	road->prev = NULL;
	road->current = map->start;
	return (road);
}

void		add_first_road(t_solve **sol, t_solve **nsol, t_map *m, t_road **r)
{
	if (!(*nsol = (t_solve*)malloc(sizeof(t_solve))))
		malloc_fail_base(m, *sol);
	(*sol)->next = *nsol;
	(*nsol)->prev = (*sol);
	(*nsol)->path = *r;
	(*nsol)->next = NULL;
	(*sol) = (*nsol);
}

t_solve		*get_first_roads(t_solve *solution, t_map *map)
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
			malloc_fail_base(map, solution);
		road->current = tmp->node;
		tmp->node->bfs = 1;
		road->prev = start_road(map, solution);
		if (!solution->path)
			solution->path = road;
		else
			add_first_road(&solution, &next_sol, map, &road);
		tmp = tmp->next;
	}
	start->prev = NULL;
	return (start);
}

void		ft_print_solution(t_solve *solution)
{
	t_solve	*tmp;

	tmp = solution;
	ft_printf("\n\e[32;40mFIRST ROADS:\033[0m\n");
	while (tmp)
	{
		ft_printf("-first node: %s\n", tmp->path->current->name);
		tmp = tmp->next;
	}
	ft_putchar('\n');
}

t_solve		*create_base_routes(t_map *map)
{
	t_solve	*solution;

	if (!(solution = (t_solve*)malloc(sizeof(t_solve))))
		malloc_fail_base(map, solution);
	solution->path = NULL;
	solution->next = NULL;
	solution = get_first_roads(solution, map);
	if (g_flags & FIRSTROADS)
		ft_print_solution(solution);
	return (solution);
}
