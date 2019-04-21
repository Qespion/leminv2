/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   olapping_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 14:05:42 by oespion           #+#    #+#             */
/*   Updated: 2019/04/21 13:16:49 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

int		count_solve(t_solve *solve)
{
	int	nb;

	nb = 0;
	while (solve)
	{
		solve = solve->next;
		nb++;
	}
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

int		check_road(t_solve *check, t_solve *start)
{
	t_road	*cmp;

	while (start)
	{
		if (start == check)
		{
			start = start->next;
			continue ;
		}
		cmp = start->path->prev;
		while (cmp)
		{
			if (cmp->current == check->path->current)
				return (0);
			cmp = cmp->prev;
		}
		start = start->next;
	}
	return (1);
}

t_solve	*epured_solve(t_solve *solve)
{
	t_solve *tmp;
	t_solve *tmped_tmp;

	tmp = solve;
	while (tmp)
	{
		if (!check_road(tmp, solve))
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
	int count;

	count = count_solve(solve);
	if (count > 1000)
		return (epured_solve(solve));
	return (solve);
}
