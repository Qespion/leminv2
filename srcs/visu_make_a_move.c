/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_make_a_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 14:28:39 by ratin             #+#    #+#             */
/*   Updated: 2019/05/15 15:02:55 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

/* void		make_a_move(t_visu *visu, t_party *party)
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
			if (MAKEAMOVE == 1)
			{
				printf("*L%d----------------------------------- ", last->index);
				print_move(last->move);
			}
			last->move_cursor = last->move;
			while (last->move_cursor)
			{
				if (last->move_cursor->x % 4 == 0 || last->move_cursor->y % 4 == 0)
				{
					fill_move_screen(party);
					draw_ant(party, last->move_cursor->x, last->move_cursor->y, 5, ANT);
					fill_ant(party, last->move_cursor->x, last->move_cursor->y, 5, ANT);
					mlx_put_image_to_window(party->mlx.mlx_ptr, party->mlx.win_ptr, party->mlx.img.img_ptr, 0, 0);
					mlx_put_image_to_window(party->mlx.mlx_ptr, party->mlx.win_ptr, party->ant_image.img.img_ptr, 0, 0);
					mlx_string_put(party->mlx.mlx_ptr, party->mlx.win_ptr
					, last->move_cursor->x, last->move_cursor->y, ANT, ft_itoa(last->index));
					mlx_do_sync(party->mlx.mlx_ptr);
					mlx_clear_window(party->mlx.mlx_ptr, party->mlx.win_ptr);
				}
				last->move_cursor = last->move_cursor->next;
			}
			printf("00000000000000000000000000000000000000sortie\n");
			last->move = NULL;
		}
		last = last->next;
	}
	if (MAKEAMOVE == 1)
	{
		printf("\n\n");
	}
} */
