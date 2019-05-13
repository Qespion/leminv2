/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 12:24:20 by ratin             #+#    #+#             */
/*   Updated: 2019/05/13 12:10:09 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

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

int		add_move(t_ant *ant, int x, int y)
{
	t_move *new_move;
	t_move *last;

	last = ant->move;
	if (!(new_move = create_move(x, y)))
		return (0);
	if (ant->move == NULL)
		ant->move = new_move;
	else
	{
		while (last->next)
			last = last->next;
		last->next = new_move;
	}
	return (1);
}

void	vertical_move(t_point *point1, t_point *point2, t_ant *ant)
{
	int	y;

	y = point1->y;
	while (y < point2->y)
	{
		add_move(ant, point1->x, y);
		y++;
	}
}