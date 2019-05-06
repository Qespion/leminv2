/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_place_party.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 17:58:36 by ratin             #+#    #+#             */
/*   Updated: 2019/05/06 02:25:12 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

void	draw_room(t_visu *visu, t_party *party, t_room *last)
{
	int		x;
	int		y;

	if ((visu->room->next->x - visu->room->y) + (visu->room->next->y
	- visu->room->y) > 100)
	{
		x = last->x + party->space + (WIDTH - party->zoom * 5) / 4;
		y = last->y + party->space + (HEIGHT + party->zoom * 1) / 3;

	}
	else
	{
		x = last->x * party->space + (WIDTH - party->zoom * 5) / 4;
		y = last->y * party->space + (HEIGHT + party->zoom * 1) / 3;
	}
	x += party->translate_x;
	y += party->translate_y;
	DrawCircle(party, x, y, 20 + party->zoom / 4);// + party->zoom / 5);
	mlx_string_put(party->mlx.mlx_ptr, party->mlx.win_ptr, x, y, 0x000000, "salut\n");
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

	last = visu->room;
	put_room_zero(visu);
	while (last)
	{
		draw_room(visu, party, last);
		last = last->next;
	}
}

void	place_party(t_visu *visu, t_party *party)
{
	party->space = 60 + party->zoom;
	place_room(visu, party);
}
