/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 19:02:10 by ratin             #+#    #+#             */
/*   Updated: 2019/05/04 00:14:52 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

void		init_visu(t_visu *visu)
{
	visu->result = NULL;
	visu->nbr_of_ants = 0;
	visu->map_finished = 0;
	visu->tube_finished = 0;
	visu->room = NULL;
	visu->nbr_room = 0;
}

int			main(void)
{
	t_visu	visu;
	t_party	party;
	
	init_visu(&visu);
	get_result(&visu);
	init_mlx(&party);
	mlx_hook(party.mlx.win_ptr, 17, 1L<<6, quit_visu
	, &party);
	draw(&party, &visu);
	return (0);
}
