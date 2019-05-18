/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_move_ant.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 12:04:08 by ratin             #+#    #+#             */
/*   Updated: 2019/05/19 00:19:43 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

void		print_move(t_move *move)
{
	t_move	*last;

	last = move;
/* 	printf("going {%d, %d} to ", last->x, last->y);
	while (last->next)
		last = last->next;
	printf("{%d, %d}\n", last->x, last->y); */
	while (last)
	{
		printf("{%d, %d}\n", last->x, last->y);
		last = last->next;
	}
}

void		reverse_move(t_move **move)
{
	t_move	*current;
	t_move	*next_el;
	t_move	*prev;

	current = *move;
	prev = NULL;
	next_el = NULL;
	while (current != NULL)
	{
		next_el = current->next;
		current->next = prev;
		prev = current;
		current = next_el;
	}
	*move = prev;
}

t_rstep		*get_rstep(int step, t_rstep *rstep)
{
	t_rstep *last;

	last = rstep;
	while (last)
	{
		if (last->index == step)
			return (last);
		last = last->next;
	}
	return (last);
}

void		check_move(t_move **move)
{
	t_move	*tmp;

	if ((*move)->next)
	{
		tmp = (*move)->next;
		free((*move));
		(*move) = tmp;
	}
}

void		get_move(t_ant **ant, t_room *dest, int step)
{
	t_point	src;
	t_point	dst;
	t_rstep *move_step;

	src.x = (*ant)->position->new_x;
	src.y = (*ant)->position->new_y;
	dst.x = dest->new_x;
	dst.y = dest->new_y;
	move_step = get_rstep(step, (*ant)->rstep);
	if (src.y <= dst.y)
		bresenmove(&src, &dst, move_step);
	else
	{
		bresenmove(&dst, &src, move_step);
		check_move(&move_step->move);
		reverse_move(&move_step->move);
	}
	move_step->move_cursor = move_step->move;
	(*ant)->position = dest;
}
