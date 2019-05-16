/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 12:24:20 by ratin             #+#    #+#             */
/*   Updated: 2019/05/16 14:55:56 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

t_rstep	*create_rstep(int step)
{
	t_rstep	*new_rstep;

	if (!(new_rstep = malloc(sizeof(*new_rstep))))
		return (0);
	new_rstep->index = step;
	new_rstep->move = NULL;
	new_rstep->move_cursor = NULL;
	new_rstep->next = NULL;
	return (new_rstep);
}

void	add_rstep(t_ant *ant, int step)
{
	t_rstep *new_rstep;
	t_rstep *last;

	last = ant->rstep;
	if (!(new_rstep = create_rstep(step)))
		exit (1);
	if (ant->rstep == NULL)
		ant->rstep = new_rstep;
	else
	{
		while (last->next)
			last = last->next;
		last->next = new_rstep;
	}
}

t_move	*create_move(int x, int y)
{
	t_move	*new_move;

	if (!(new_move = malloc(sizeof(*new_move))))
		return (0);
	new_move->x = x;
	new_move->y = y;
	new_move->next = NULL;
	return (new_move);
}

int		add_move(t_rstep *rstep, int x, int y)
{
	t_move *new_move;
	t_move *last;

	last = rstep->move;
	if (!(new_move = create_move(x, y)))
		exit (1);
	if (rstep->move == NULL)
		rstep->move = new_move;
	else
	{
		while (last->next)
			last = last->next;
		last->next = new_move;
	}
	return (1);
}

void	vertical_move(t_point *point1, t_point *point2, t_rstep *rstep)
{
	int	y;

	y = point1->y;
	while (y < point2->y)
	{
		add_move(rstep, point1->x, y);
		y++;
	}
}