/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 14:30:27 by oespion           #+#    #+#             */
/*   Updated: 2019/05/02 23:11:15 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

int		find_del(char *str)
{
	int	r;

	r = 0;
	while (str[r])
	{
		if (str[r] == '-')
			return (r);
		r++;
	}
	exit(-1);
}

void	check_double_road(t_node *tmp, t_link *last_link, t_map *map)
{
	t_link	*link;

	link = tmp->link;
	while (link->next)
	{
		if (link->node == last_link->node)
		{
			ft_printf("\n\e[31;1mERROR: link twice between ");
			ft_printf("%s and %s\033[0m\n", link->node->name, tmp->name);
			ft_clean_map(map);
			exit(-1);
		}
		link = link->next;
	}
}

t_map	*read_file(t_map *map)
{
	int		turn;
	char	*str;

	str = NULL;
	turn = 0;
	while (get_next_line(0, &str))
	{
		if ((str[0] == '#' && str[1] != '#') || ((str[0] == '#' && str[1] == '#'
			&& (ft_strcmp(str, "##start") && ft_strcmp(str, "##end")))))
		{
			ft_printf("%s\n", str);
			free(str);
			continue ;
		}
		turn = check_turn(str, turn, map);
		map = add_line(str, map, turn);
		ft_printf("%s\n", str);
		if (str)
			free(str);
		if (!map->valid)
			return (map);
	}
	if (str)
		free(str);
	return (map);
}

t_map	*nget_file(void)
{
	t_map	*map;

	if (!(map = (t_map*)malloc(sizeof(t_map))))
		exit(-1);
	map->valid = 1;
	map->jcpu = NULL;
	map->start = NULL;
	map->end = NULL;
	map->begin = NULL;
	map->nb = -42;
	map = read_file(map);
	ft_putchar('\n');
	return (map);
}
