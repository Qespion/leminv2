/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_bresenham.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 18:31:24 by ratin             #+#    #+#             */
/*   Updated: 2019/05/03 22:51:32 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

static int	line1(t_point *point1, t_point *point2, t_mlx *mlx, int color)
{
	int		x;
	int		y;
	t_line	line;

	x = point1->x;
	y = point1->y;
	line.dp = 2 * (point2->y - point1->y) - (point2->x - point1->x);
	line.delta_e = 2 * (point2->y - point1->y);
	line.delta_ne = 2 * ((point2->y - point1->y) - (point2->x - point1->x));
	ft_put_pixel(mlx, x, y, color);
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
		ft_put_pixel(mlx, x, y, color);
	}
	return (0);
}

static int	line2(t_point *point1, t_point *point2, t_mlx *mlx, int color)
{
	int		x;
	int		y;
	t_line	line;

	x = point1->x;
	y = point1->y;
	line.dp = 2 * (point2->x - point1->x) - (point2->y - point1->y);
	line.delta_e = 2 * (point2->x - point1->x);
	line.delta_ne = 2 * ((point2->x - point1->x) - (point2->y - point1->y));
	ft_put_pixel(mlx, x, y, color);
	if (x == point2->x)
		vertical_limit(point1, point2, mlx, color);
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
		ft_put_pixel(mlx, x, y, color);
	}
	return (0);
}

static int	line3(t_point *point1, t_point *point2, t_mlx *mlx, int color)
{
	int		x;
	int		y;
	t_line	line;

	x = point1->x;
	y = point1->y;
	line.dp = 2 * (point2->y - point1->y) - (point1->x - point2->x);
	line.delta_e = 2 * (point2->y - point1->y);
	line.delta_ne = 2 * ((point2->y - point1->y) - (point1->x - point2->x));
	ft_put_pixel(mlx, x, y, color);
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
		ft_put_pixel(mlx, x, y, color);
	}
	return (0);
}

static int	line4(t_point *point1, t_point *point2, t_mlx *mlx, int color)
{
	int		x;
	int		y;
	t_line	line;

	x = point1->x;
	y = point1->y;
	line.dp = 2 * (point1->x - point2->x) - (point2->y - point1->y);
	line.delta_e = 2 * (point1->x - point2->x);
	line.delta_ne = 2 * ((point1->x - point2->x) - (point2->y - point1->y));
	ft_put_pixel(mlx, x, y, color);
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
		ft_put_pixel(mlx, x, y, color);
	}
	return (0);
}

int			put_line(t_point *point1, t_point *point2, t_mlx *mlx, int color)
{
	if (point2->x >= point1->x)
	{
		if ((point2->x - point1->x) >= (point2->y - point1->y))
			line1(point1, point2, mlx, color);
		if ((point2->x - point1->x) < (point2->y - point1->y))
			line2(point1, point2, mlx, color);
	}
	if (point2->x < point1->x)
	{
		if ((point1->x - point2->x) >= (point2->y - point1->y))
			line3(point1, point2, mlx, color);
		if ((point1->x - point2->x) <= (point2->y - point1->y))
			line4(point1, point2, mlx, color);
	}
	return (0);
}
