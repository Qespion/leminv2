/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_roads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 18:08:42 by oespion           #+#    #+#             */
/*   Updated: 2019/05/01 12:53:04 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

void	link_on_tmp2(t_node ***tmp2, t_link **startlink, t_link **new_link2)
{
	if (!(**tmp2)->link)
		(**tmp2)->link = *new_link2;
	else
	{
		*startlink = (**tmp2)->link;
		while ((**tmp2)->link->next)
			(**tmp2)->link = (**tmp2)->link->next;
		(**tmp2)->link->next = *new_link2;
		(**tmp2)->link = *startlink;
	}
}

void	link_on_road(t_node **tmp, t_node **tmp2, t_map *map)
{
	t_link	*new_link;
	t_link	*new_link2;
	t_link	*startlink;

	if (!(new_link = (t_link*)malloc(sizeof(t_link))))
		exit(-1);
	if (!(new_link2 = (t_link*)malloc(sizeof(t_link))))
		exit(-1);
	new_link->node = *tmp2;
	new_link->next = NULL;
	new_link2->node = *tmp;
	new_link2->next = NULL;
	if (!(*tmp)->link)
		(*tmp)->link = new_link;
	else
	{
		startlink = (*tmp)->link;
		while ((*tmp)->link->next)
			(*tmp)->link = (*tmp)->link->next;
		(*tmp)->link->next = new_link;
		(*tmp)->link = startlink;
	}
	check_double_road(*tmp, new_link, map);
	link_on_tmp2(&tmp2, &startlink, &new_link2);
}

t_map	*get_road(char *str, t_map *map)
{
	char	*name1;
	char	*name2;
	t_node	*tmp;
	t_node	*tmp2;

	tmp = map->begin;
	tmp2 = map->begin;
	if (str[0] == '#' && str[1] != '#')
		return (map);
	name1 = ft_strsub(str, 0, find_del(str));
	name2 = ft_strchr(str, '-') + 1;
	if (!error_road(name1, name2, &tmp, &tmp2))
		map->valid = 0;
	link_on_road(&tmp, &tmp2, map);
	free(name1);
	return (map);
}

t_map	*add_line(char *str, t_map *map, int turn)
{
	if (turn == 0)
		map = get_ants(str, map);
	else if (turn == 1)
	{
		check_valid_island(str);
		map = get_island(str, map);
	}
	else
	{
		if (!map->begin)
			link_wo_island(map);
		map = get_road(str, map);
	}
	return (map);
}

int		check_turn(char *str, int turn, t_map *map)
{
	if (turn == 0 && map->nb != -42)
		return (1);
	if (turn == 1 && ft_strchr(str, '-'))
		return (2);
	return (turn);
}
