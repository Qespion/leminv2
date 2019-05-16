/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_make_a_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 14:28:39 by ratin             #+#    #+#             */
/*   Updated: 2019/05/16 19:17:11 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

void		make_a_move(t_visu *visu, t_party *party)
{
	t_ant	*last;
	t_rstep	*rstep;

	last = visu->ants;
	while (last)
	{
		rstep = get_rstep(party->g_step, last->rstep);
		if (rstep->move_cursor->next)
			rstep->move_cursor = rstep->move_cursor->next;
		last = last->next;
	}
}
