/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_fill_circle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 17:13:28 by ratin             #+#    #+#             */
/*   Updated: 2019/05/20 17:30:05 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

void		init_line(t_point *line, int centre_x, int centre_y, int *xy)
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

void		init_var(int (*xy)[2], int (*t_xy)[2], int *diameter, int radius)
{
	(*xy)[0] = radius - 2;
	(*xy)[1] = 0;
	(*t_xy)[0] = 1;
	(*t_xy)[1] = 1;
	*diameter = radius * 2;
}

void		fill_it(t_point *line, t_party *party, int color)
{
	put_line(&line[0], &line[1], &party->mlx, color);
	put_line(&line[2], &line[3], &party->mlx, color);
	put_line(&line[4], &line[5], &party->mlx, color);
	put_line(&line[6], &line[7], &party->mlx, color);
}

void		fill_circle(t_party *party, int *centre_xy, int radius, int color)
{
	int		diameter;
	int		xy[2];
	int		t_xy[2];
	int		error;
	t_point	line[8];

	init_var(&xy, &t_xy, &diameter, radius);
	error = (t_xy[0] - diameter);
	while (xy[0] >= xy[1])
	{
		init_line(line, centre_xy[0], centre_xy[1], xy);
		fill_it(line, party, color);
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
