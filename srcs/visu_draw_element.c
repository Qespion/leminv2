/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_draw_element.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 02:34:48 by ratin             #+#    #+#             */
/*   Updated: 2019/05/09 11:02:45 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

int			draw_link(t_party *party, t_room *last, t_tube *tube, int circle)
{
	t_point	room1;
	t_point	room2;
	int		i;

	i = 0;
	room1.x = last->x * party->space + (WIDTH - party->zoom * 5) / 4;
	room1.y = last->y * party->space + (HEIGHT + party->zoom * 1) / 3;
	room2.x = tube->room->x * party->space + (WIDTH - party->zoom * 5) / 4;
	room2.y = tube->room->y * party->space + (HEIGHT + party->zoom * 1) / 3;
	room1.x += party->translate_x - party->press_x;
	room1.y += party->translate_y - party->press_y;
	room2.x += party->translate_x - party->press_x;
	room2.y += party->translate_y - party->press_y;
	print_lines(&room1, &room2, &party->mlx, ROOM);
	(void)circle;
	return (0);
}

int			draw_room(t_party *party, t_room *last)
{
	int		x;
	int		y;
	int		circle;

	if (party->is_bigmap == 1)
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
	last->new_x = x;
	last->new_y = y;
	draw_circle(party, x, y, circle, ROOM);
	return (circle);
}

void		color_room(t_party *party, t_room *last)
{
	int		x;
	int		y;
	int		circle;
	int		i;

	i = 0;
	if (party->is_bigmap == 1)
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
	fill_circle(party, x, y, circle - i, ROOM_COLOR);
}

void		draw_dest(t_visu *visu, t_party *party, t_ant *ant, t_room *dest)
{
	t_point	src;
	t_point	dst;
	t_point	move;

	src.x = ant->position->new_x;
	src.y = ant->position->new_y;
	move.x = ant->position->new_x;
	move.y = ant->position->new_y;
	dst.x = dest->new_x;
	dst.y = dest->new_y;
/* 	printf("ant %d-%s {%d, %d} --> %s {%d, %d}\n", ant->index, ant->position->name,
	ant->position->new_x, ant->position->new_y, dest->name,
	dest->new_x, dest->new_y); */
	//printf("\n");
	print_lines(&src, &dst, &party->mlx, ANT);
	ant->position = dest;
 	(void)visu;
	(void)party;
	(void)dest;
}