/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_map_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 00:11:31 by ratin             #+#    #+#             */
/*   Updated: 2019/05/23 01:35:16 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

void	check_mp_inpt(t_visu *visu, char *str)
{
	int	i;

	i = 0;
	if (str[0] == '#')
		return ;
	while (str[i] != ' ' && str[i])
		i++;
	if (!str[i])
		quit_parsing(visu->party);
	while (str[++i] != ' ' && str[i])
	{
		if (str[i] < 48 && str[i] > 57)
			quit_parsing(visu->party);
	}
	if (!str[i])
		quit_parsing(visu->party);
	while (str[++i] != ' ' && str[i])
	{
		if (str[i] < 48 && str[i] > 57)
			quit_parsing(visu->party);
	}
}
