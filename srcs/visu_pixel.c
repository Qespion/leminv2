/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 18:39:11 by ratin             #+#    #+#             */
/*   Updated: 2019/05/13 12:14:18 by ratin            ###   ########.fr       */
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

void fill_ant(t_party *party, int centreX, int centreY, int radius, int color)
{
	int	diameter = (radius * 2);
	int	x = (radius - 2);
	int	y = 0;
	int	tx = 1;
	int	ty = 1;
	int	error = (tx - diameter);
	t_point line[8];

	while (x >= y)
	{
		line[0].x = centreX - y;
		line[0].y = centreY - x;
		line[1].x = centreX + y;
		line[1].y = centreY - x;
		line[2].x = centreX + x;
		line[2].y = centreY - y;
		line[3].x = centreX - x;
		line[3].y = centreY - y;
		line[4].x = centreX - x;
		line[4].y = centreY + y;
		line[5].x = centreX + x;
		line[5].y = centreY + y;
		line[6].x = centreX - y;
		line[6].y = centreY + x;
		line[7].x = centreX + y;
		line[7].y = centreY + x;
		put_line(&line[0], &line[1], &party->ant_image, color);
		put_line(&line[2], &line[3], &party->ant_image, color);
		put_line(&line[4], &line[5], &party->ant_image, color);
		put_line(&line[6], &line[7], &party->ant_image, color);
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

void fill_circle(t_party *party, int centreX, int centreY, int radius, int color)
{
	int	diameter = (radius * 2);
	int	x = (radius - 2);
	int	y = 0;
	int	tx = 1;
	int	ty = 1;
	int	error = (tx - diameter);
	t_point line[8];

	while (x >= y)
	{
		line[0].x = centreX - y;
		line[0].y = centreY - x;
		line[1].x = centreX + y;
		line[1].y = centreY - x;
		line[2].x = centreX + x;
		line[2].y = centreY - y;
		line[3].x = centreX - x;
		line[3].y = centreY - y;
		line[4].x = centreX - x;
		line[4].y = centreY + y;
		line[5].x = centreX + x;
		line[5].y = centreY + y;
		line[6].x = centreX - y;
		line[6].y = centreY + x;
		line[7].x = centreX + y;
		line[7].y = centreY + x;
		put_line(&line[0], &line[1], &party->mlx, color);
		put_line(&line[2], &line[3], &party->mlx, color);
		put_line(&line[4], &line[5], &party->mlx, color);
		put_line(&line[6], &line[7], &party->mlx, color);
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
	(void)party;
	(void)color;
}

void draw_circle(t_party *party, int centreX, int centreY, int radius, int color)
{
	int	diameter = (radius * 2);
	int	x = (radius - 1);
	int	y = 0;
	int	tx = 1;
	int	ty = 1;
	int	error = (tx - diameter);

	while (x >= y)
	{
		ft_put_pixel(&party->mlx, centreX - y, centreY - x, color);
		ft_put_pixel(&party->mlx, centreX + y, centreY - x, color);

		ft_put_pixel(&party->mlx, centreX + x, centreY - y, color);
		ft_put_pixel(&party->mlx, centreX - x, centreY - y, color);

		ft_put_pixel(&party->mlx, centreX - x, centreY + y, color);
		ft_put_pixel(&party->mlx, centreX + x, centreY + y, color);

		ft_put_pixel(&party->mlx, centreX - y, centreY + x, color);
		ft_put_pixel(&party->mlx, centreX + y, centreY + x, color);
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

void 	draw_ant(t_party *party, int centreX, int centreY, int radius, int color)
{
	int	diameter = (radius * 2);
	int	x = (radius - 1);
	int	y = 0;
	int	tx = 1;
	int	ty = 1;
	int	error = (tx - diameter);

	while (x >= y)
	{
		ft_put_pixel(&party->ant_image, centreX - y, centreY - x, color);
		ft_put_pixel(&party->ant_image, centreX + y, centreY - x, color);

		ft_put_pixel(&party->ant_image, centreX + x, centreY - y, color);
		ft_put_pixel(&party->ant_image, centreX - x, centreY - y, color);

		ft_put_pixel(&party->ant_image, centreX - x, centreY + y, color);
		ft_put_pixel(&party->ant_image, centreX + x, centreY + y, color);

		ft_put_pixel(&party->ant_image, centreX - y, centreY + x, color);
		ft_put_pixel(&party->ant_image, centreX + y, centreY + x, color);
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