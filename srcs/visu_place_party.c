/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_place_party.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 17:58:36 by ratin             #+#    #+#             */
/*   Updated: 2019/05/06 05:33:58 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

int			draw_room(t_visu *visu, t_party *party, t_room *last)
{
	int		x;
	int		y;
	int		circle;

	if ((visu->room->next->x - visu->room->y) + (visu->room->next->y
	- visu->room->y) > 100)
	{
		x = last->x - party->space;
		y = last->y - party->space;
		circle = 20;
	}
	else
	{
		x = last->x * party->space + (WIDTH - party->zoom * 5) / 4;
		y = last->y * party->space + (HEIGHT + party->zoom * 1) / 3;
		circle = 20 + party->zoom / 4;
	}
	x += party->translate_x - party->press_x;
	y += party->translate_y - party->press_y;
	DrawCircle(party, x, y, circle);
	mlx_string_put(party->mlx.mlx_ptr, party->mlx.win_ptr, x, y, ROOM, "salut\n");
	return (circle);
}

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

	last = visu->room;
	min = get_min_room(visu);
	while (last)
	{
		last->x -= min->x;
		last->y -= min->y;
		last = last->next;
	}
}

void	place_room(t_visu *visu, t_party *party)
{
	t_room	*last;
	int		circle;

	last = visu->room;
	put_room_zero(visu);
	while (last)
	{
		circle = draw_room(visu, party, last);
		//draw_link(visu, party, last, circle);
		last = last->next;
	}
}

void	place_party(t_visu *visu, t_party *party)
{
	party->space = 60 + party->zoom;
	place_room(visu, party);
}
