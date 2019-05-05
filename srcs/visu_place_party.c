/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_place_party.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 17:58:36 by ratin             #+#    #+#             */
/*   Updated: 2019/05/05 03:59:37 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

void	draw_room(t_party *party, t_room *last)
{
	int		x;
	int		y;
	int		i;
/* 	int		name_x;
	int		name_y; */

	i = 0;
	x = last->x * party->space + WIDTH / 4;
	y = last->y * party->space + HEIGHT / 3;
/* 	name_y = y - 100;
	name_x = x - 50;
	mlx_string_put(party->mlx.mlx_ptr, party->mlx.win_ptr, name_x, name_y,
	ROOM, last->name); */
	while (i < 5)
	{
		DrawCircle(party, x, y, 20 - i);
		i++;
	}
}

void	place_room(t_visu *visu, t_party *party)
{
	t_room	*last;

	last = visu->room;
	while (last)
	{
		draw_room(party, last);
		last = last->next;
	}
}

void	place_party(t_visu *visu, t_party *party)
{
	party->space = 60 * party->zoom;
	place_room(visu, party);
}
