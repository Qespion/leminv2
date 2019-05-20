/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_room.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 23:52:21 by ratin             #+#    #+#             */
/*   Updated: 2019/05/20 17:12:02 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

t_room			*create_room(int special)
{
	t_room		*room;
	static int	index = 0;

	if (!(room = malloc(sizeof(*room))))
		return (0);
	room->start = 0;
	room->end = 0;
	if (special == 1)
		room->start = 1;
	if (special == 2)
		room->end = 1;
	room->index = index++;
	room->x = 0;
	room->y = 0;
	room->name = NULL;
	room->link = NULL;
	room->next = NULL;
	return (room);
}

void			fill_room(char *str, t_room *room)
{
	int			i;

	i = 0;
	while(str[i] && str[i] != ' ')
		i++;
	if (!(room->name = ft_strsub(str, 0, i)))
		exit(1);
	i++;
	room->x = ft_atoi(&str[i]);
	while (str[i] && str[i] != ' ')
		i++;
	room->y = ft_atoi(&str[i]);
}

int				add_room(t_visu *visu, char *str, int special)
{
	t_room		*new_room;
	t_room		*last;

	last = visu->room;
	if (!(new_room = create_room(special)))
		quit_visu(visu->party);
	fill_room(str, new_room);
	if (visu->room == NULL)
		visu->room = new_room;
	else
	{
		while (last->next)
			last = last->next;
		last->next = new_room;
	}
	return (1);
}
