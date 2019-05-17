/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_draw_ants.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 14:53:10 by ratin             #+#    #+#             */
/*   Updated: 2019/05/17 12:16:31 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

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

void		draw_all_ants(t_party *party, t_visu *visu)
{
	t_ant	*last;
	t_rstep *rstep;
	int		i;

	last = visu->ants;
	while (last)
	{
		i = 0;
		rstep = get_rstep(party->g_step, last->rstep);
		if (rstep)
		{
			while (i < party->mouv && rstep->move_cursor->next)
			{
				rstep->move_cursor = rstep->move_cursor->next;
				i++;
			}
			draw_ant(party, rstep->move_cursor->x, rstep->move_cursor->y, 5
			, ANT);
			fill_ant(party, rstep->move_cursor->x, rstep->move_cursor->y, 5
			, ANT);
		}
		last = last->next;
	}
}
