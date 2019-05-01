/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   olapping_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 14:05:42 by oespion           #+#    #+#             */
/*   Updated: 2019/05/01 12:32:46 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

int		count_solve(t_solve *solve)
{
	static int	turn = 2;
	int			nb;

	nb = 0;
	while (solve)
	{
		if (!solve->path->current->bfs)
			solve->path->current->bfs = turn;
		solve = solve->next;
		nb++;
	}
	turn++;
	return (nb);
}

t_solve	*del_tmp(t_solve *tmp, t_solve *solve)
{
	t_solve	*start;

	start = solve;
	if (start == tmp)
	{
		start = start->next;
		free_road(tmp->path);
		free(tmp);
		tmp = NULL;
		return (start);
	}
	while (solve->next != tmp)
		solve = solve->next;
	solve->next = solve->next->next;
	free_road(tmp->path);
	free(tmp);
	return (start);
}

int		get_lowest_number(t_solve *solve)
{
	int	nb;

	while (!solve->path->current->bfs)
		solve = solve->next;
	nb = solve->path->current->bfs;
	while (solve)
	{
		if (!nb && solve->path->current->bfs)
			nb = solve->path->current->bfs;
		else if (solve->path->current->bfs && solve->path->current->bfs < nb)
			nb = solve->path->current->bfs;
		solve = solve->next;
	}
	return (nb);
}

t_solve	*epured_solve(t_solve *solve)
{
	int		number;
	t_solve *tmp;
	t_solve *tmped_tmp;

	tmp = solve;
	number = get_lowest_number(solve);
	while (tmp)
	{
		if (tmp->path->current->bfs == number)
		{
			tmped_tmp = tmp->next;
			solve = del_tmp(tmp, solve);
			tmp = tmped_tmp;
			continue ;
		}
		tmp = tmp->next;
	}
	return (solve);
}

t_solve	*epur_map(t_solve *solve)
{
	while (count_solve(solve) > 500)
		solve = epured_solve(solve);
	return (solve);
}
