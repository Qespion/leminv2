/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_start_ants.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 20:46:02 by ratin             #+#    #+#             */
/*   Updated: 2019/05/15 17:13:42 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

void		start_ants(t_visu *visu, t_party *party)
{
	place_ants(visu, party);
}

void		free_move(t_move *move)
{
	t_move	*last;
	t_move	*tmp;

	last = move;
	while (last)
	{
		tmp = last->next;
		free(last);
		last = tmp;
	}
}

void		free_rstep(t_rstep *rstep)
{
	t_rstep	*last;
	t_rstep	*tmp;

	last = rstep;
	while (last)
	{
		tmp = last->next;
		free_move(last->move);
		free(last);
		last = tmp;
	}
}

void		free_ant_move(t_visu *visu)
{
	t_ant	*last_ant;

	last_ant = visu->ants;
	while (last_ant)
	{
		if (last_ant->rstep)
			free_rstep(last_ant->rstep);
		last_ant->rstep = NULL;
		last_ant->position = get_start_room(visu);
		last_ant = last_ant->next;
	}
}