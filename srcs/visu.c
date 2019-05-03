/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 19:02:10 by ratin             #+#    #+#             */
/*   Updated: 2019/05/03 18:49:25 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

int			main(void)
{
	t_visu	visu;
	
	visu.map_finished = 0;
	visu.tube_finished = 0;
	visu.room = NULL;
	visu.nbr_room = 0;
	get_result(&visu);
	return (0);
}