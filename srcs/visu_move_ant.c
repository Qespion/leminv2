/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_move_ant.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 12:04:08 by ratin             #+#    #+#             */
/*   Updated: 2019/05/14 20:12:33 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

void		print_move(t_move *move)
{
	t_move	*last;

	last = move;
/* 	printf("going {%d, %d} to ", last->x, last->y);
	while (last->next)
		last = last->next;
	printf("{%d, %d}\n", last->x, last->y); */
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
					add_name(visu, party);
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
}

void		reverse_move(t_move **move)
{
	t_move	*current;
	t_move	*next_el;
	t_move	*prev;

	current = *move;
	prev = NULL;
	next_el = NULL;
	while (current != NULL)
	{
		next_el = current->next;
		current->next = prev;
		prev = current;
		current = next_el;
	}
	*move = prev;
}

void		get_move(t_visu *visu, t_party *party, t_ant **ant, t_room *dest)
{
	t_point	src;
	t_point	dst;

	src.x = (*ant)->position->new_x;
	src.y = (*ant)->position->new_y;
	dst.x = dest->new_x;
	dst.y = dest->new_y;

	printf("new_ant %d-%s {%d, %d} --> %s {%d, %d}\n", (*ant)->index
	, (*ant)->position->name, src.x, src.y, dest->name, dst.x, dst.y);


	//suprimer proprement le move
	//free((*ant)->move);
	(*ant)->move = NULL;
	printf("@L%d before ----------------------------\n", (*ant)->index);
	print_move((*ant)->move);
	if (src.y <= dst.y)
	{
		printf("bresenmove1\n");
		bresenmove(&src, &dst, (*ant));
	}
	else
	{
		printf("bresenmove2\n");
		bresenmove(&dst, &src, (*ant));
		reverse_move(&(*ant)->move);
	}
	printf("@L%d ----------------------------\n", (*ant)->index);
	print_move((*ant)->move);
	print_lines(&src, &dst, &party->mlx, ANT);

	(*ant)->position = dest;
 	(void)visu;
	(void)party;
	(void)dest;
}
