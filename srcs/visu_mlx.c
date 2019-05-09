/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 14:59:07 by ratin             #+#    #+#             */
/*   Updated: 2019/05/09 06:12:03 by ratin            ###   ########.fr       */
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
	if (key == 123 && party->i > 0)
		party->i--;
	if (key == 124 && party->i < party->turn - 1)
		party->i++;
	if (key == 78 && party->zoom > -42)
	{
		party->zoom -= 2;
		printf("zoom = %d\n", party->zoom);

	}
	if (key == 69)
		party->zoom += 2;
	if (key == 123)
		party->translate_x -= 10;
	if (key == 125)
		party->translate_y += 10;
	if (key == 126)
		party->translate_y -= 10;
	if (key == 124)
		party->translate_x += 10;
	//printf("key = %d\n", key);
	return (1);
}


int			init_mlx(t_party *party)
{
	if (!(party->mlx.mlx_ptr = mlx_init()))
		quit_visu(party);
	if (!(party->mlx.win_ptr = mlx_new_window(party->mlx.mlx_ptr, WIDTH, HEIGHT
	, "Lem-in")))
		quit_visu(party);
	if (!(party->mlx.img.img_ptr = mlx_new_image(party->mlx.mlx_ptr, WIDTH
	, HEIGHT)))
		quit_visu(party);
	party->mlx.img.data = (int *)mlx_get_data_addr(party->mlx.img.img_ptr
	, &party->mlx.img.bpp,
	&party->mlx.img.size_l, &party->mlx.img.endian);
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

int			draw(t_party *party, t_visu *visu)
{
	t_mlx	*mlx;

	mlx = &party->mlx;
	while (1)
	{
		mlx_clear_window(party->mlx.mlx_ptr, party->mlx.win_ptr);
		mlx_destroy_image(party->mlx.mlx_ptr, party->mlx.img.img_ptr);
		party->mlx.img.img_ptr = mlx_new_image(party->mlx.mlx_ptr, WIDTH
		, HEIGHT);
		party->mlx.img.data = (int *)mlx_get_data_addr(party->mlx.img.img_ptr
		, &party->mlx.img.bpp,
		&party->mlx.img.size_l, &party->mlx.img.endian);
		back_screen(party);

		place_party(visu, party);
		place_ants(visu, party);

		mlx_put_image_to_window(party->mlx.mlx_ptr, party->mlx.win_ptr
		, party->mlx.img.img_ptr, 0, 0);
		mlx_do_sync(party->mlx.mlx_ptr);
		if (party->pause == 0 && party->i < party->turn - 1)
			party->i += 1;
	}
	(void)visu;
	return (1);
}
