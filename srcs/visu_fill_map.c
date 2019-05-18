/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_fill_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 23:59:34 by ratin             #+#    #+#             */
/*   Updated: 2019/05/18 19:39:46 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

void			fill_map(t_visu *visu, char *str)
{
	static int	start = 0;
	static int	end = 0;

	if (str[0] == '#' && str[1] != '#')
		return ;
	else if (ft_strcmp("##start", str) == 0)
		start = 1;
	else if (ft_strcmp("##end", str) == 0)
		end = 1;
	else if (start == 1)
	{
		add_room(visu, str, 1);
		start = 0;
	}
	else if (end == 1)
	{
		add_room(visu, str, 2);
		end = 0;
	}
	else
		add_room(visu, str, 0);
}
