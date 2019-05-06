/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 19:02:10 by ratin             #+#    #+#             */
/*   Updated: 2019/05/06 05:23:54 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

void		init_visu(t_visu *visu, t_party *party)
{
	visu->result = NULL;
	visu->nbr_of_ants = 0;
	visu->map_finished = 0;
	visu->tube_finished = 0;
	visu->room = NULL;
	visu->nbr_room = 0;
	party->zoom = 1;
	party->translate_x = 0;
	party->translate_y = 0;
	party->press_x = 0;
	party->press_y = 0;
	party->is_pressed = 0;
	party->x_save = 0;
	party->y_save = 0;
}

int		handle_mouse(int x, int y, t_party *party) 
{
	if (party->is_pressed == 1)
	{
		party->translate_x = x;
		party->translate_y = y;
	}
	return (0);
}

int			mouse_press(int button, int x, int y, t_party *party)
{
	if (button == 1 && party->is_pressed == 0)
	{
		party->is_pressed = 1;
		party->press_x = x;
		party->press_y = y;
	}
	else
		party->is_pressed = 0;
	return (0);
}

int			main(void)
{
	t_visu	visu;
	t_party	party;
	
	init_visu(&visu, &party);
	get_result(&visu);
	init_mlx(&party);
	mlx_hook(party.mlx.win_ptr, 17, 1L<<6, quit_visu, &party);
	mlx_hook(party.mlx.win_ptr, 2, 1L<<6, handle_key, &party);
	mlx_hook(party.mlx.win_ptr, 6, 1L<<6, handle_mouse, &party);
	mlx_hook(party.mlx.win_ptr, 4, 1L<<6, mouse_press, &party);
	draw(&party, &visu);
	return (0);
}
