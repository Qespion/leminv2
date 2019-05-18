/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 19:02:10 by ratin             #+#    #+#             */
/*   Updated: 2019/05/19 01:04:43 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

void		init_visu(t_visu *visu, t_party *party)
{
	visu->room = NULL;
	visu->ants = NULL;
	visu->nbr_of_ants = 0;
	visu->map_finished = 0;
	visu->tube_finished = 0;
	visu->reponse_finished = 0;
	visu->party = party;
	party->visu = visu;
	party->g_step = 1;
	party->zoom = 1;
	party->translate_x = 0;
	party->translate_y = 0;
	party->press_x = 0;
	party->press_y = 0;
	party->is_pressed = 0;
	party->mouv = 0;
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

void		printant(t_visu *visu)
{
	t_ant	*last = visu->ants;
	while (last)
	{
		printf("ant %d position = %s\n", last->index, last->position->name);
		last = last->next;
	}
}

void		init_ants(t_visu *visu)
{
	int		nbr;
	int		i;

	nbr = visu->nbr_of_ants;
	i = 1;
	while (nbr)
	{
		add_ant(visu, i);
		i++;
		nbr--;
	}
}

void		init_zoom(t_visu *visu, t_party *party)
{
	if ((visu->room->next->x - visu->room->x) + (visu->room->next->y
	- visu->room->y) > 100)
	{
		party->is_bigmap = 1;
		party->zoom = -57;
	}
	else
		party->is_bigmap = 0;
}

int			main(void)
{
	t_visu	visu;
	t_party	party;
	
	init_visu(&visu, &party);
	get_result(&visu);
	init_mlx(&visu, &party);
	init_ants(&visu);
	mlx_hook(party.mlx.win_ptr, 17, 1L<<6, quit_visu, &visu);
	mlx_hook(party.mlx.win_ptr, 2, 1L<<6, handle_key, &party);
	mlx_hook(party.mlx.win_ptr, 6, 1L<<6, handle_mouse, &party);
	mlx_hook(party.mlx.win_ptr, 4, 1L<<6, mouse_press, &party);
	init_zoom(&visu, &party);
	draw(&party, &visu);
	return (0);
}

//no start map error
//faire ath avec print step et legende