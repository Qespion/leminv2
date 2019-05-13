/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_move_ant.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 12:04:08 by ratin             #+#    #+#             */
/*   Updated: 2019/05/13 13:37:20 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

void		print_move(t_move *move)
{
	t_move	*last;

	last = move;
	while (last)
	{
		printf("{%d, %d}\n", last->x, last->y);
		last = last->next;
	}
}

void		fill_move_screen(t_party *party)
{
	int		y;
	int		x;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			ft_put_pixel(&party->ant_image, x, y, 0xffffff00);
			x++;
		}
		y++;
	}
}

void		make_a_move(t_visu *visu, t_party *party)
{
	t_ant	*last;

	last = visu->ants;
	mlx_destroy_image(party->mlx.mlx_ptr, party->ant_image.img.img_ptr);
	if (!(party->ant_image.img.img_ptr = mlx_new_image(party->mlx.mlx_ptr, WIDTH, HEIGHT)))
		quit_visu(party);
	party->ant_image.img.data = (int *)mlx_get_data_addr(party->ant_image
		.img.img_ptr, &party->ant_image.img.bpp, &party->ant_image.img.size_l
		, &party->ant_image.img.endian);
	while (last)
	{
		if (last->move)
		{
			last->move_cursor = last->move;
			while (last->move_cursor)
			{
				if (last->move_cursor->x % 5 == 0)
				{
					fill_move_screen(party);
					draw_ant(party, last->move_cursor->x, last->move_cursor->y, 5, ANT);
					fill_ant(party, last->move_cursor->x, last->move_cursor->y, 5, ANT);
					mlx_put_image_to_window(party->mlx.mlx_ptr, party->mlx.win_ptr, party->mlx.img.img_ptr, 0, 0);
					mlx_put_image_to_window(party->mlx.mlx_ptr, party->mlx.win_ptr, party->ant_image.img.img_ptr, 0, 0);
					add_name(visu, party);
					mlx_string_put(party->mlx.mlx_ptr, party->mlx.win_ptr
					, last->move_cursor->x, last->move_cursor->y, ANT, ft_itoa(last->index));
					mlx_do_sync(party->mlx.mlx_ptr);
					//mlx_clear_window(party->mlx.mlx_ptr, party->mlx.win_ptr);
				}
				last->move_cursor = last->move_cursor->next;
			}
			last->move = NULL;
		}
		last = last->next;
		(void)party;
	}
}

void		get_move(t_visu *visu, t_party *party, t_ant **ant, t_room *dest)
{
	t_point	src;
	t_point	dst;

	src.x = (*ant)->position->new_x;
	src.y = (*ant)->position->new_y;
	dst.x = dest->new_x;
	dst.y = dest->new_y;
	printf("new_ant %d-%s {%d, %d} --> %s {%d, %d}\n", (*ant)->index, (*ant)->position->name,
	(*ant)->position->new_x, (*ant)->position->new_y, dest->name,
	dest->new_x, dest->new_y);

	bresenmove(&src, &dst, (*ant));
	print_lines(&src, &dst, &party->mlx, ANT);

	(*ant)->position = dest;
 	(void)visu;
	(void)party;
	(void)dest;
}