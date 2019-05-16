/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_place_ants.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 05:46:17 by ratin             #+#    #+#             */
/*   Updated: 2019/05/16 18:03:28 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

t_room		*get_start_room(t_visu *visu)
{
	t_room	*current;

	current = visu->room;
	while (current)
	{
		if (current->start == 1)
			return (current);
		current = current->next;
	}
	return (current);
}

t_ant		*create_ant(t_visu *visu, int i)
{
	t_ant	*new_ant;

	if (!(new_ant = malloc(sizeof(*new_ant))))
		return (0);
	new_ant->position = get_start_room(visu);
	new_ant->index = i;
	new_ant->rstep = NULL;
	new_ant->next = NULL;
	return (new_ant);
}

void		add_ant(t_visu *visu, int i)
{
	t_ant	*new_ant;
	t_ant	*last;

	new_ant = create_ant(visu, i);
	last = visu->ants;
	if (visu->ants == NULL)
		visu->ants = new_ant;
	else
	{
		while (last->next)
		{
			last = last->next;
		}
		last->next = new_ant;
	}
}

t_ant	*get_ant(t_visu *visu, int index)
{
	t_ant	*ant;

	ant = visu->ants;
	while (ant)
	{
		if (ant->index == index)
			return (ant);
		ant = ant->next;
	}
	return (0);
}

int				place_ants(t_visu *visu, t_party *party)
{
	int			i;
	int			y;
	int			i_step;
	char		*step;
	t_reponse	*current;
	t_room		*destination;
	t_ant		*ant;

	current = visu->reponse;
	i_step = 1;
	while (current)
	{
		i = 0;
		init_rstep(visu, i_step);
		while (current->step[i] != 0)
		{
			y = 0;
			step = current->step[i];
			if (!(ant = get_ant(visu, ft_atoi(&step[1]))))
				return (0);
			while (step[y] != '-' && step[y])
				y++;
			destination = get_room_by_name(visu, &step[++y]);
			//add_rstep(ant, i_step);
			get_move(visu, &ant, destination, i_step);
			i++;
		}
		current = current->next;
		i_step++;
	}
	(void)party;
	return (1);
}
