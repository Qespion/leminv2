/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_fill_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 23:59:34 by ratin             #+#    #+#             */
/*   Updated: 2019/05/23 01:53:03 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

t_room			*get_end_room(t_visu *visu)
{
	t_room		*current;

	current = visu->room;
	while (current)
	{
		if (current->end == 1)
			return (current);
		current = current->next;
	}
	return (0);
}

void			check_start_end(t_visu *visu, int select)
{
	if (select == 1)
	{
		if (get_start_room(visu))
			quit_parsing(visu->party);
	}
	if (select == 2 && get_end_room(visu))
		quit_parsing(visu->party);
}

void			get_map_inpt(int *start, int *end, t_visu *visu, char *str)
{
	if (*start == 1)
	{
		add_room(visu, str, 1);
		*start = 0;
	}
	else if (*end == 1)
	{
		add_room(visu, str, 2);
		*end = 0;
	}
	else
		add_room(visu, str, 0);
}

void			fill_map(t_visu *visu, char *str)
{
	static int	start = 0;
	static int	end = 0;

	check_mp_inpt(visu, str);
	if (str[0] == '#' && str[1] != '#')
		return ;
	else if (ft_strcmp("##start", str) == 0)
	{
		check_start_end(visu, 1);
		start = 1;
	}
	else if (ft_strcmp("##end", str) == 0)
	{
		check_start_end(visu, 2);
		end = 1;
	}
	else
		get_map_inpt(&start, &end, visu, str);
}
