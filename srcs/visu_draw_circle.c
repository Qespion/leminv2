/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_draw_circle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 17:59:18 by ratin             #+#    #+#             */
/*   Updated: 2019/05/20 18:08:32 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

void	put_circle_piece(t_party *party, int *ctr_xy, int *xy, int color)
{
	ft_put_pixel(&party->mlx, ctr_xy[0] - xy[1], ctr_xy[1] - xy[0], color);
	ft_put_pixel(&party->mlx, ctr_xy[0] + xy[1], ctr_xy[1] - xy[0], color);
	ft_put_pixel(&party->mlx, ctr_xy[0] + xy[0], ctr_xy[1] - xy[1], color);
	ft_put_pixel(&party->mlx, ctr_xy[0] - xy[0], ctr_xy[1] - xy[1], color);
	ft_put_pixel(&party->mlx, ctr_xy[0] - xy[0], ctr_xy[1] + xy[1], color);
	ft_put_pixel(&party->mlx, ctr_xy[0] + xy[0], ctr_xy[1] + xy[1], color);
	ft_put_pixel(&party->mlx, ctr_xy[0] - xy[1], ctr_xy[1] + xy[0], color);
	ft_put_pixel(&party->mlx, ctr_xy[0] + xy[1], ctr_xy[1] + xy[0], color);
}

void	init_env(int *diameter, int radius, int (*xy)[2], int (*t_xy)[2])
{
	*diameter = radius * 2;
	(*xy)[0] = radius - 1;
	(*xy)[1] = 0;
	(*t_xy)[0] = 1;
	(*t_xy)[1] = 1;
}

void	draw_circle(t_party *party, int *centre_xy, int radius, int color)
{
	int	diameter;
	int	xy[2];
	int	t_xy[2];
	int	error;

	init_env(&diameter, radius, &xy, &t_xy);
	error = t_xy[0] - diameter;
	while (xy[0] >= xy[1])
	{
		put_circle_piece(party, centre_xy, xy, color);
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
