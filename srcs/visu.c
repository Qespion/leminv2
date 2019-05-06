/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 19:02:10 by ratin             #+#    #+#             */
/*   Updated: 2019/05/06 02:25:06 by ratin            ###   ########.fr       */
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
}

int			main(void)
{
	t_visu	visu;
	t_party	party;
	
	init_visu(&visu, &party);
	get_result(&visu);
	init_mlx(&party);
	mlx_hook(party.mlx.win_ptr, 17, 1L<<6, quit_visu
	, &party);
	mlx_hook(party.mlx.win_ptr, 2, 1L<<6, handle_key, &party);
	draw(&party, &visu);
	return (0);
}
