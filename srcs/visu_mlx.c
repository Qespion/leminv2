/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 14:59:07 by ratin             #+#    #+#             */
/*   Updated: 2019/05/18 18:45:45 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

int			quit_visu(t_party *party)
{
	mlx_clear_window(party->mlx.mlx_ptr, party->mlx.win_ptr);
	mlx_destroy_window(party->mlx.mlx_ptr, party->mlx.win_ptr);
	//free_prog(party);
	exit(1);
	return (0);
} 
int		handle_key(int key, t_party *party)
{
	if (key == 53)
		quit_visu(party);
	if (key == 49)
	{
		if (party->pause == 0)
			party->pause = 1;
		else
			party->pause = 0;
	}
	if (key == 78 && party->zoom > -42 && party->is_bigmap == 0)
		party->zoom -= 2;
	if (key == 69 && party->is_bigmap == 0)
		party->zoom += 2;
	if (key == 69 && party->is_bigmap == 1 && party->zoom > -59)
		party->zoom--;
	if (key == 78 && party->is_bigmap == 1 && party->zoom < 0)
		party->zoom++;
	if (key == 123)
		party->translate_x -= 10;
	if (key == 125)
		party->translate_y += 10;
	if (key == 126)
		party->translate_y -= 10;
	if (key == 124)
		party->translate_x += 10;
	if (key == 116 && party->g_step < party->nbr_of_step)
	{
		party->mouv = 0;
		party->g_step++;
	}
	if (key == 121 && party->g_step > 1)
	{
		party->mouv = 0;
		party->g_step--;
	}
	//printf("key = %d\n", key);
	return (1);
}


int			init_mlx(t_visu *visu, t_party *party)
{
	if (!(party->mlx.mlx_ptr = mlx_init()))
		quit_visu(party);
	if (!(party->mlx.win_ptr = mlx_new_window(party->mlx.mlx_ptr, WIDTH, HEIGHT
	, "Lem-in")))
		quit_visu(party);
	if (!(party->mlx.img.img_ptr = mlx_new_image(party->mlx.mlx_ptr, WIDTH
	, HEIGHT)))
		quit_visu(party);
	if (!(party->ant_image.img.img_ptr = mlx_new_image(party->mlx.mlx_ptr, WIDTH, HEIGHT)))
		quit_visu(party);
	party->mlx.img.data = (int *)mlx_get_data_addr(party->mlx.img.img_ptr
		, &party->mlx.img.bpp, &party->mlx.img.size_l, &party->mlx.img.endian);
	party->ant_image.img.data = (int *)mlx_get_data_addr(party->ant_image
		.img.img_ptr, &party->ant_image.img.bpp, &party->ant_image.img.size_l
		, &party->ant_image.img.endian);
	party->nbr_of_ants = visu->nbr_of_ants;
	party->nbr_of_step = visu->nbr_of_step;
	return (1);
}

void		back_screen(t_party *party)
{
	int		y;
	int		x;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			ft_put_pixel(&party->mlx, x, y, BACKSCREEN);
			x++;
		}
		y++;
	}
}

void		add_ant_name(t_visu *visu, t_party *party)
{
	t_ant	*last;
	t_rstep *rstep;
	char	*ant_in;

	last = visu->ants;
	while (last)
	{
		rstep = get_rstep(party->g_step, last->rstep);
		if (rstep)
		{
			ant_in = ft_itoa(last->index);
			mlx_string_put(party->mlx.mlx_ptr, party->mlx.win_ptr
			, rstep->move_cursor->x, rstep->move_cursor->y, ANT, ant_in);
			free(ant_in);
		}
		last = last->next;
	}
}

void		print_ant_pos(t_visu *visu, t_party *party)
{
	t_ant		*last;
	t_rstep		*rstep;

	last = visu->ants;
	while (last)
	{
		printf("pour ant %d:\n", last->index);
		rstep = last->rstep;
		while (rstep)
		{
			printf("	g_step %d\n", rstep->index);
			printf("	L%d positinon = {%d, %d}\n", last->index,
			rstep->move->x,	rstep->move->y);
			rstep = rstep->next;
		}
		last = last->next;
	}
	printf("\n\n");
	(void)party;
}

int			draw(t_party *party, t_visu *visu)
{
	t_mlx	*mlx;

	mlx = &party->mlx;
	while (1)
	{
		printf("gstep = %d\n", party->g_step);
		mlx_clear_window(party->mlx.mlx_ptr, party->mlx.win_ptr);
		mlx_destroy_image(party->mlx.mlx_ptr, party->mlx.img.img_ptr);
		party->mlx.img.img_ptr = mlx_new_image(party->mlx.mlx_ptr, WIDTH
		, HEIGHT);
		party->mlx.img.data = (int *)mlx_get_data_addr(party->mlx.img.img_ptr
		, &party->mlx.img.bpp,
		&party->mlx.img.size_l, &party->mlx.img.endian);
		back_screen(party);
		place_party(visu, party);
		start_ants(visu, party);

		draw_all_ants(party, visu);
		mlx_put_image_to_window(party->mlx.mlx_ptr, party->mlx.win_ptr
		, party->mlx.img.img_ptr, 0, 0);
		add_ant_name(visu, party);
		add_name(visu, party);

		mlx_do_sync(party->mlx.mlx_ptr);

		free_ant_move(visu);
		party->mouv += 3;
	}
	return (1);
}
