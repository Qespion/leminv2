/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_err.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 18:11:34 by oespion           #+#    #+#             */
/*   Updated: 2019/05/22 22:51:47 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

void	check_only_nb(char *str, t_map *map)
{
	while (*str >= '0' && *str <= '9')
		str++;
	if (*str != '\0')
	{
		ft_printf("\e[31;1mERROR: Not a clean numbers of ants\033[0m\n");
		free(map);
		exit(-1);
	}
}

t_map	*get_ants(char *str, t_map *map)
{
	if (ft_strlen(str) > 13 || ft_atoi(str) > 2147483647
		|| ft_atoi(str) < -2147483648
		|| ((ft_atoi(str) == 0 && str[0] != '0')))
	{
		free(map);
		ft_printf("\e[31;1mERROR: 404 on lemmins\033[0m\n");
		exit(-1);
	}
	else if (ft_atoi(str) < 0)
	{
		free(map);
		ft_printf("\e[31;1mERROR: Negative numbers of lemmins\033[0m\n");
		exit(-1);
	}
	map->nb = ft_atoi(str);
	check_only_nb(str, map);
	return (map);
}

void	double_end(int which_end)
{
	if (which_end == 0)
		ft_printf("\e[31;1mERROR: Double start \033[0m\n");
	else if (which_end == 1)
		ft_printf("\e[31;1mERROR: Double end\033[0m\n");
	else if (which_end == 3)
		ft_printf("\e[31;1mERROR: start is end\033[0m\n");
	else if (which_end == 4)
		ft_printf("\e[31;1mERROR: Invalid island input\033[0m\n");
	else if (which_end == 5)
		ft_printf("\e[31;1mERROR: Island can't start with 'L'\033[0m\n");
	else if (which_end == 6)
		ft_printf("\e[31;1mERROR: Island can't start with '#'\033[0m\n");
	exit(-1);
}

t_map	*error_case(t_map *map, int *start, int *end, t_node *new_node)
{
	if (new_node->name[0] == 'L')
		double_end(5);
	if (*start == 1 && *end == 1)
		double_end(3);
	if (*start == 1)
	{
		if (map->start)
			double_end(0);
		map->start = new_node;
		*start = -1;
	}
	else if (*end == 1)
	{
		if (map->end)
			double_end(1);
		map->end = new_node;
		*end = -1;
	}
	return (map);
}

int		error_road(char *name1, char *name2, t_node **tmp, t_node **tmp2)
{
	while (ft_strcmp((*tmp)->name, name1))
	{
		if (!(*tmp)->next)
		{
			if (name1[0] == '#')
				ft_printf("\e[31;1mERROR: Island can't start with #\033[0m\n");
			else
				ft_printf("\e[31;1m%s road not found\033[0m\n", name1);
			return (0);
		}
		(*tmp) = (*tmp)->next;
	}
	while (ft_strcmp((*tmp2)->name, name2))
	{
		if (!(*tmp2)->next)
		{
			if (name2[0] == '#')
				ft_printf("\e[31;1mERROR: Island can't start with #\033[0m\n");
			else
				ft_printf("\e[31;1m%s road not found\033[0m\n", name2);
			return (0);
		}
		(*tmp2) = (*tmp2)->next;
	}
	return (1);
}
