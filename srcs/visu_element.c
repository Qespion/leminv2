/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_element.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 02:34:48 by ratin             #+#    #+#             */
/*   Updated: 2019/05/07 03:30:58 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

int			draw_link(t_party *party, t_room *last, t_tube *tube, int circle)
{
	t_point	room1;
	t_point	room2;
	int		i;

	printf("pour room %s link = %s\n", last->name, tube->room->name);
	printf("------------------\n");
	i = 0;
	room1.x = last->x * party->space + (WIDTH - party->zoom * 5) / 4;
	room1.y = last->y * party->space + (HEIGHT + party->zoom * 1) / 3;
	room2.x = tube->room->x * party->space + (WIDTH - party->zoom * 5) / 4;
	room2.y = tube->room->y * party->space + (HEIGHT + party->zoom * 1) / 3;
	printf("print_line {%d, %d} {%d, %d}\n", room1.x, room1.y, room2.x, room2.y);
	print_lines(&room1, &room2, &party->mlx, ROOM);
	while (i < 50)
	{
		room1.x += i;
		room1.y += i;
		room2.x += i;
		room2.y += i;
		i++;
	}
	printf("passage\n");
	(void)circle;
	(void)last;
	(void)tube;
	return (0);
}