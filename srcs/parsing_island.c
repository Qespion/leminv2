/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_island.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 18:05:59 by oespion           #+#    #+#             */
/*   Updated: 2019/05/02 23:10:00 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

void	link_wo_island(t_map *map)
{
	ft_printf("\e[31;1mERROR: No Islands\033[0m\n");
	ft_printf("\n\e[32;40mFINISHED\033[0m\n");
	free(map);
	exit(-1);
}

void	check_valid_island(char *str)
{
	int	r;

	if (!ft_strcmp(str, "##start") || !ft_strcmp(str, "##end"))
		return ;
	if (str[0] == ' ')
		double_end(4);
	r = 1;
	while (str[r] != ' ' && str[r])
		r++;
	if (str[r] != ' ')
		double_end(4);
	r++;
	while (str[r] >= 48 && str[r] <= 57)
		r++;
	if (str[r] != ' ')
		double_end(4);
	r++;
	while (str[r] >= 48 && str[r] <= 57)
		r++;
	if (str[r] != '\0')
		double_end(4);
}

int		find_space(char *str)
{
	int	r;

	r = 0;
	while (str[r])
	{
		if (str[r] == ' ')
			return (r);
		r++;
	}
	return (0);
}

int		start_end(int *start, int *end, char *str)
{
	if (!ft_strcmp(str, "##start"))
	{
		*start = 1;
		return (1);
	}
	if (!ft_strcmp(str, "##end"))
	{
		*end = 1;
		return (1);
	}
	return (0);
}

t_map	*get_island(char *str, t_map *map)
{
	static int	start = 0;
	static int	end = 0;
	t_node		*new_node;

	if (start_end(&start, &end, str))
		return (map);
	if (!(new_node = (t_node*)malloc(sizeof(t_node))))
		exit(-1);
	new_node->name = ft_strsub(str, 0, find_space(str));
	new_node->bfs = 0;
	new_node->link = NULL;
	new_node->next = NULL;
	if (!map->jcpu)
	{
		map->begin = new_node;
		map->jcpu = new_node;
	}
	else
	{
		map->jcpu->next = new_node;
		map->jcpu = new_node;
	}
	map = error_case(map, &start, &end, new_node);
	return (map);
}
