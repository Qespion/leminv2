/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_place_party.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 17:58:36 by ratin             #+#    #+#             */
/*   Updated: 2019/05/20 19:53:20 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

t_room		*get_min_room(t_visu *visu)
{
	t_room	*last;
	t_room	*min;
	int		tmp;

	last = visu->room;
	min = last;
	tmp = last->x;
	while (last)
	{
		if (last->x < tmp)
		{
			min = last;
			tmp = last->x;
		}
		last = last->next;
	}
	return (min);
}

void		put_room_zero(t_visu *visu)
{
	t_room	*min;
	t_room	*last;
	int		x;
	int		y;

	last = visu->room;
	min = get_min_room(visu);
	x = min->x;
	y = min->y;
	while (last)
	{
		last->x -= x;
		last->y -= y;
		last = last->next;
	}
}

void		place_room(t_visu *visu, t_party *party)
{
	t_room	*last;
	int		circle;
	t_tube	*tube;

	last = visu->room;
	put_room_zero(visu);
	while (last)
	{
		tube = last->link;
		circle = draw_room(party, last);
		while (tube)
		{
			draw_link(party, last, tube);
			tube = tube->next;
		}
		last = last->next;
	}
}

void		add_color(t_visu *visu, t_party *party)
{
	t_room	*last;

	last = visu->room;
	while (last)
	{
		color_room(party, last);
		last = last->next;
	}
}

void		place_party(t_visu *visu, t_party *party)
{
	party->space = 60 + party->zoom;
	place_room(visu, party);
	add_color(visu, party);
}
