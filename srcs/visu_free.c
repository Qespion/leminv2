/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 19:17:44 by ratin             #+#    #+#             */
/*   Updated: 2019/05/20 18:52:29 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

void			free_reponse(t_visu *visu)
{
	t_reponse	*reponse;
	t_reponse	*tmp;
	int			i;

	reponse = visu->reponse;
	while (reponse)
	{
		i = 0;
		tmp = reponse->next;
		while (reponse->step[i])
		{
			free(reponse->step[i]);
			i++;
		}
		free(reponse->step);
		free(reponse);
		reponse = tmp;
	}
}

void			free_tube(t_tube *link)
{
	t_tube		*tmp;

	while (link)
	{
		tmp = link->next;
		free(link);
		link = tmp;
	}
}

void			free_room(t_visu *visu)
{
	t_room		*room;
	t_room		*tmp;

	room = visu->room;
	while (room)
	{
		tmp = room->next;
		free_tube(room->link);
		free(room->name);
		free(room);
		room = tmp;
	}
}

void			free_prog(t_visu *visu, t_party *party)
{
	free_ant_move(visu);
	free_room(visu);
	free_reponse(visu);
	(void)party;
}
