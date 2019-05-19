/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 18:39:11 by ratin             #+#    #+#             */
/*   Updated: 2019/05/19 20:40:28 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

int		ft_put_pixel(t_mlx *mlx, int x, int y, int color)
{
	if (y < HEIGHT && y > 0 && x < WIDTH && x > 0)
		mlx->img.data[y * WIDTH + x] = color;
	return (0);
}

int		print_lines(t_point *point1, t_point *point2, t_mlx *mlx, int color)
{
	if (point1->y <= point2->y)
		put_line(point1, point2, mlx, color);
	else
		put_line(point2, point1, mlx, color);
	return (0);
}

void	vertical_limit(t_point *point1, t_point *point2, t_mlx *mlx, int color)
{
	int	y;

	y = point1->y;
	while (y < point2->y)
	{
		ft_put_pixel(mlx, point1->x, y, color);
		y++;
	}
}

void	init_line(t_point *line, int centre_x, int centre_y, int *xy)
{
	line[0].x = centre_x - xy[1];
	line[0].y = centre_y - xy[0];
	line[1].x = centre_x + xy[1];
	line[1].y = centre_y - xy[0];
	line[2].x = centre_x + xy[0];
	line[2].y = centre_y - xy[1];
	line[3].x = centre_x - xy[0];
	line[3].y = centre_y - xy[1];
	line[4].x = centre_x - xy[0];
	line[4].y = centre_y + xy[1];
	line[5].x = centre_x + xy[0];
	line[5].y = centre_y + xy[1];
	line[6].x = centre_x - xy[1];
	line[6].y = centre_y + xy[0];
	line[7].x = centre_x + xy[1];
	line[7].y = centre_y + xy[0];
}

void	fill_circle(t_party *party, int centre_x, int centre_y, int radius, int color)
{
	int	diameter;
	int	xy[2];
	int	t_xy[2];
	int	error;
	t_point line[8];

	t_xy[0] = 1;
	t_xy[1] = 1;
	xy[0] = radius - 2;
	xy[1] = 0;
	diameter = radius * 2;
	error = (t_xy[0] - diameter);
	while (xy[0] >= xy[1])
	{
		init_line(line, centre_x, centre_y, xy);
		put_line(&line[0], &line[1], &party->mlx, color);
		put_line(&line[2], &line[3], &party->mlx, color);
		put_line(&line[4], &line[5], &party->mlx, color);
		put_line(&line[6], &line[7], &party->mlx, color);
		if (error <= 0)
		{
			++xy[1];
			error += t_xy[1];
			t_xy[1] += 2;
		}
		if (error > 0)
		{
			--xy[0];
			t_xy[0] += 2;
			error += (t_xy[0] - diameter);
		}
	}
}

void draw_circle(t_party *party, int centre_x, int centre_y, int radius, int color)
{
	int	diameter = (radius * 2);
	int	x = (radius - 1);
	int	y = 0;
	int	tx = 1;
	int	ty = 1;
	int	error = (tx - diameter);

	while (x >= y)
	{
		ft_put_pixel(&party->mlx, centre_x - y, centre_y - x, color);
		ft_put_pixel(&party->mlx, centre_x + y, centre_y - x, color);
		ft_put_pixel(&party->mlx, centre_x + x, centre_y - y, color);
		ft_put_pixel(&party->mlx, centre_x - x, centre_y - y, color);
		ft_put_pixel(&party->mlx, centre_x - x, centre_y + y, color);
		ft_put_pixel(&party->mlx, centre_x + x, centre_y + y, color);
		ft_put_pixel(&party->mlx, centre_x - y, centre_y + x, color);
		ft_put_pixel(&party->mlx, centre_x + y, centre_y + x, color);
		if (error <= 0)
		{
			++y;
			error += ty;
			ty += 2;
		}
		if (error > 0)
		{
			--x;
			tx += 2;
			error += (tx - diameter);
		}
	}
}
