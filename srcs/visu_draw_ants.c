/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_draw_ants.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 14:53:10 by ratin             #+#    #+#             */
/*   Updated: 2019/05/20 18:22:47 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

void		draw_all_ants(t_party *party, t_visu *visu)
{
	t_ant	*last;
	t_rstep *rstep;
	int		i;
	int		xy[2];

	last = visu->ants;
	while (last)
	{
		i = 0;
		rstep = get_rstep(party->g_step, last->rstep);
		if (rstep)
		{
			while (i < party->mouv && rstep->move_cursor->next)
			{
				rstep->move_cursor = rstep->move_cursor->next;
				i++;
			}
			xy[0] = rstep->move_cursor->x;
			xy[1] = rstep->move_cursor->y;
			draw_circle(party, xy, 5, ANT);
			fill_circle(party, xy, 5, ANT);
		}
		last = last->next;
	}
}
