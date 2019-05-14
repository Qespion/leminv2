/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_bresenmove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 12:13:05 by ratin             #+#    #+#             */
/*   Updated: 2019/05/14 20:00:46 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

static int	line1(t_point *point1, t_point *point2, t_ant *ant)
{
	int		x;
	int		y;
	t_line	line;

	printf("passage in 1\n");
	x = point1->x;
	y = point1->y;
	line.dp = 2 * (point2->y - point1->y) - (point2->x - point1->x);
	line.delta_e = 2 * (point2->y - point1->y);
	line.delta_ne = 2 * ((point2->y - point1->y) - (point2->x - point1->x));
	add_move(ant, x, y);
	while (x < point2->x)
	{
		if (line.dp <= 0)
			line.dp = line.dp + line.delta_e;
		else
		{
			line.dp = line.dp + line.delta_ne;
			y++;
		}
		x++;
		add_move(ant, x, y);
	}
	return (1);
}

static int	line2(t_point *point1, t_point *point2, t_ant *ant)
{
	int		x;
	int		y;
	t_line	line;

	printf("passage in 2\n");
	x = point1->x;
	y = point1->y;
	line.dp = 2 * (point2->x - point1->x) - (point2->y - point1->y);
	line.delta_e = 2 * (point2->x - point1->x);
	line.delta_ne = 2 * ((point2->x - point1->x) - (point2->y - point1->y));
	add_move(ant, x, y);
	if (x == point2->x)
		vertical_move(point1, point2, ant);
	while (x < point2->x)
	{
		if (line.dp <= 0)
			line.dp = line.dp + line.delta_e;
		else
		{
			line.dp = line.dp + line.delta_ne;
			x++;
		}
		y++;
		add_move(ant, x, y);
	}
	return (0);
}

static int	line3(t_point *point1, t_point *point2, t_ant *ant)
{
	int		x;
	int		y;
	t_line	line;

	printf("passage in 3\n");
	x = point1->x;
	y = point1->y;
	line.dp = 2 * (point2->y - point1->y) - (point1->x - point2->x);
	line.delta_e = 2 * (point2->y - point1->y);
	line.delta_ne = 2 * ((point2->y - point1->y) - (point1->x - point2->x));
	add_move(ant, x, y);
	while (x > point2->x)
	{
		if (line.dp <= 0)
			line.dp = line.dp + line.delta_e;
		else
		{
			line.dp = line.dp + line.delta_ne;
			y++;
		}
		x--;
		add_move(ant, x, y);
	}
	return (0);
}

static int	line4(t_point *point1, t_point *point2, t_ant *ant)
{
	int		x;
	int		y;
	t_line	line;

	printf("passage in 4\n");
	x = point1->x;
	y = point1->y;
	line.dp = 2 * (point1->x - point2->x) - (point2->y - point1->y);
	line.delta_e = 2 * (point1->x - point2->x);
	line.delta_ne = 2 * ((point1->x - point2->x) - (point2->y - point1->y));
	add_move(ant, x, y);
	while (x > point2->x)
	{
		if (line.dp <= 0)
			line.dp = line.dp + line.delta_e;
		else
		{
			line.dp = line.dp + line.delta_ne;
			x--;
		}
		y++;
		add_move(ant, x, y);
	}
	return (0);
}

void		bresenmove(t_point *point1, t_point *point2, t_ant *ant)
{
	if (point2->x >= point1->x)
	{
		if ((point2->x - point1->x) >= (point2->y - point1->y))
			line1(point1, point2, ant);
		if ((point2->x - point1->x) < (point2->y - point1->y))
			line2(point1, point2, ant);
	}
	if (point2->x < point1->x)
	{
		if ((point1->x - point2->x) >= (point2->y - point1->y))
			line3(point1, point2, ant);
		if ((point1->x - point2->x) < (point2->y - point1->y))
			line4(point1, point2, ant);
	}
}
