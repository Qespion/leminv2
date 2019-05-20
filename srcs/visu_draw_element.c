/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_draw_element.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 02:34:48 by ratin             #+#    #+#             */
/*   Updated: 2019/05/20 17:38:26 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

int			draw_link(t_party *party, t_room *last, t_tube *tube)
{
	t_point	room1;
	t_point	room2;
	int		i;

	i = 0;
	if (party->is_bigmap == 1)
	{
		room1.x = last->x / party->space + (WIDTH - party->zoom * 5) / 4;
		room1.y = last->y / party->space + (HEIGHT + party->zoom * 1) / 3;
		room2.x = tube->room->x / party->space + (WIDTH - party->zoom * 5) / 4;
		room2.y = tube->room->y / party->space + (HEIGHT + party->zoom * 1) / 3;
	}
	else
	{
		room1.x = last->x * party->space + (WIDTH - party->zoom * 5) / 4;
		room1.y = last->y * party->space + (HEIGHT + party->zoom * 1) / 3;
		room2.x = tube->room->x * party->space + (WIDTH - party->zoom * 5) / 4;
		room2.y = tube->room->y * party->space + (HEIGHT + party->zoom * 1) / 3;
	}
	room1.x += party->translate_x - party->press_x;
	room1.y += party->translate_y - party->press_y;
	room2.x += party->translate_x - party->press_x;
	room2.y += party->translate_y - party->press_y;
	print_lines(&room1, &room2, &party->mlx, ROOM);
	return (0);
}

int			draw_room(t_party *party, t_room *last)
{
	int		xy[2];
	int		circle;

	if (party->is_bigmap == 1)
	{
		xy[0] = last->x / party->space + (WIDTH - party->zoom * 5) / 4;
		xy[1] = last->y / party->space + (HEIGHT + party->zoom * 1) / 3;
		circle = 20;
	}
	else
	{
		xy[0] = last->x * party->space + (WIDTH - party->zoom * 5) / 4;
		xy[1] = last->y * party->space + (HEIGHT + party->zoom * 1) / 3;
		circle = 20 + party->zoom / 4;
	}
	xy[0] += party->translate_x - party->press_x;
	xy[1] += party->translate_y - party->press_y;
	last->new_x = xy[0];
	last->new_y = xy[1];
	draw_circle(party, xy, circle, ROOM);
	if (last->start == 1)
		draw_circle(party, xy, circle + 2, START);
	if (last->end == 1)
		draw_circle(party, xy, circle + 2, END);
	return (circle);
}

void		color_room(t_party *party, t_room *last)
{
	int		xy[2];
	int		circle;
	int		i;

	i = 0;
	if (party->is_bigmap == 1)
	{
		xy[0] = last->x / party->space + (WIDTH - party->zoom * 5) / 4;
		xy[1] = last->y / party->space + (HEIGHT + party->zoom * 1) / 3;
		circle = 20;
	}
	else
	{
		xy[0] = last->x * party->space + (WIDTH - party->zoom * 5) / 4;
		xy[1] = last->y * party->space + (HEIGHT + party->zoom * 1) / 3;
		circle = 20 + party->zoom / 4;
	}
	xy[0] += party->translate_x - party->press_x;
	xy[1] += party->translate_y - party->press_y;
	fill_circle(party, xy, circle - i, ROOM_COLOR);
}
