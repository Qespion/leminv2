/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avo <avo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 16:28:14 by oespion           #+#    #+#             */
/*   Updated: 2019/03/05 13:45:22 by avo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

t_map   *get_ants(char *str, int *turn, t_map *map, int border)
{
	if (str[0] == '#' && str[1] != '#')
	{
		map->nb = -42;
		return (map);
	}
	if (ft_strlen(str) > 13 || ft_atoi(str) > 2147483647
		|| ft_atoi(str) < -2147483648
		|| ((ft_atoi(str) == 0 && str[0] != '0')))
	{
		ft_printf("404 on lemmins");
		exit(-1);
	}
	else if (ft_atoi(str) < 0)
	{
		ft_printf("Negative numbers of lemmins");
		exit(-1);
	}
	map->nb = ft_atoi(str);
	return (map);
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

t_map   *get_island(char *str, int *turn, t_map *map, int border)
{
	t_node	*new_node;

	if (str[0] == '#' && str[1] != '#')
		return (map);
	else if (!ft_strcmp(str, "##start") || !ft_strcmp(str, "##end"))
		return (map);
	if (!(new_node = (t_node*)malloc(sizeof(t_node))))
		exit(-1);
	if (!(new_node->name = (char *)malloc(sizeof((char) * ft_strsub(str, 0, find_space(str))))))
		exit(-1);
	new_node->name = ft_strsub(str, 0, find_space(str));
	new_node->link = NULL;
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
	if (border == 1)
		map->start = new_node;
	else if (border == 2)
		map->end = new_node;
	return (map);
}

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

t_map   *get_road(char *str, int *turn, t_map *map, int border)
{
	t_link	*new_link;
	t_link	*new_link2;
	char	*name1;
	char	*name2;
	t_node	*tmp;
	t_node	*tmp2;
	t_link	*tmp_link;
	t_link	*tmp_link2;
	t_link	*startlink;

	tmp = map->begin;
	tmp2 = map->begin;
	if (str[0] == '#' && str[1] != '#')
		return (map);
	if (!(new_link = (t_link*)malloc(sizeof(t_link))))
		exit(-1);
	if (!(new_link2 = (t_link*)malloc(sizeof(t_link))))
		exit(-1);
	name1 = ft_strsub(str, 0, find_del(str));
	name2 = ft_strchr(str, '-') + 1;
	while (ft_strcmp(tmp->name, name1))
	{
		if (!tmp->next)
		{
			ft_printf("%s road not found\n", name1);
			exit(-1);
		}
		tmp = tmp->next;
	}
	while (ft_strcmp(tmp2->name, name2))
	{
		if (!tmp2->next)
		{
			ft_printf("%s road not found\n", name2);
			exit(-1);
		}
		tmp2 = tmp2->next;
	}
	new_link->node = tmp2;
	new_link->next = NULL;
	new_link2->node = tmp;
	new_link2->next = NULL;
	if (!tmp->link)
		tmp->link = new_link;
	else
	{
		startlink = tmp->link;
		while (tmp->link->next)
			tmp->link = tmp->link->next;
		tmp->link->next = new_link;
		tmp->link = startlink;
	}
	if (!tmp2->link)
		tmp2->link = new_link2;
	else
	{
		startlink = tmp2->link;
		while (tmp2->link->next)
			tmp2->link = tmp2->link->next;
		tmp2->link->next = new_link2;
		tmp2->link = startlink;
	}
	return (map);
}

int		where_am_i(char *str, int turn, t_map *map)
{
	if (turn == 0 && (map->nb != -42 || !map->nb))
		return (1);
	else if (str[0] == '#' && str[1] != '#')
		return (turn);
	else if (turn == 1 && ft_strstr(str, "-"))
		return (2);
	return (turn);
}

int		find_border(char *str, int border)
{
	if (!ft_strcmp("##start", str))
		return (1);
	else if (!ft_strcmp("##end", str))
	{
		if (border == 1)
		{
			ft_printf("start is end\n");
			exit(-1);
		}
		return (2);
	}
	return (0);
}

t_map	*read_file(t_map *map, char *file)
{
	static int	border;
	static int	turn;
	int			fd;
	char		*str;
	t_map		*(*parse[3])(char *, int *, t_map *, int border);

	turn = 0;
	border = 0;
	fd = open(file, 0);
	parse[0] = get_ants;
	parse[1] = get_island;
	parse[2] = get_road;
	while (get_next_line(0, &str))
	{
		ft_printf("- %s\n", str);
		turn = where_am_i(str, turn, map);
		parse[turn](str, &turn, map, border);
		border = find_border(str, border);
	}
	return (map);
}

void		ft_print_map(t_map *map)
{
	t_node	*tmp;
	t_link		*tmp_link;

	tmp = map->begin;
	while (tmp)
	{
		ft_printf("%s", tmp->name);
		ft_printf(" --link -> ");
		tmp_link = tmp->link;
		while (tmp_link)
		{
			ft_printf(" %s -", tmp_link->node->name);
			tmp_link = tmp_link->next;
		}
		ft_putchar('\n');
		tmp = tmp->next;
	}
}	

t_map	*get_file(char *file)
{
	t_map	*map;

	if (!(map = (t_map*)malloc(sizeof(t_map))))
		exit(-1);
	map->jcpu = NULL;
	map->start = NULL;
	map->end = NULL;
	map->nb = -42;
	map = read_file(map, file);
	// ft_print_map(map);
	// exit(-1);
	return (map);
}
