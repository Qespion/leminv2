/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_link.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 18:25:52 by ratin             #+#    #+#             */
/*   Updated: 2019/05/22 19:23:51 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

t_room			*get_room_by_name(t_visu *visu, char *name)
{
	t_room		*last;

	last = visu->room;
	while (last)
	{
		if (ft_strcmp(name, last->name) == 0)
			return (last);
		last = last->next;
	}
	return (0);
}

t_tube			*create_link(t_visu *visu, char *name)
{
	t_tube		*tube;

	if (!(tube = malloc(sizeof(*tube))))
		return (0);
	tube->room = get_room_by_name(visu, name);
	tube->test = 42;
	tube->next = NULL;
	return (tube);
}

int				add_link(t_visu *visu, t_room *room, char *name)
{
	t_tube		*last;
	t_tube		*new_link;

	last = room->link;
	if (!(new_link = create_link(visu, name)))
		quit_visu(visu->party);
	if (room->link == NULL)
		room->link = new_link;
	else
	{
		while (last->next)
			last = last->next;
		last->next = new_link;
	}
	return (1);
}
