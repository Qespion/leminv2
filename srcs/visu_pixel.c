/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 18:39:11 by ratin             #+#    #+#             */
/*   Updated: 2019/05/20 18:22:42 by ratin            ###   ########.fr       */
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
