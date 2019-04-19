/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 14:30:27 by oespion           #+#    #+#             */
/*   Updated: 2019/04/19 14:14:37 by oespion          ###   ########.fr       */
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
		ft_printf("\e[31;1mError: Not a clean numbers of ants\033[0m\n");
		free(map);
		exit(-1);
	}
}

void	link_wo_island(t_map *map)
{
	ft_printf("\e[31;1mError: No Islands\033[0m\n");
	free(map);
	exit(-1);
}

t_map	*get_ants(char *str, t_map *map)
{
	if (ft_strlen(str) > 13 || ft_atoi(str) > 2147483647
		|| ft_atoi(str) < -2147483648
		|| ((ft_atoi(str) == 0 && str[0] != '0')))
	{
		free(map);
		ft_printf("\e[31;1mError: 404 on lemmins\033[0m\n");
		exit(-1);
	}
	else if (ft_atoi(str) < 0)
	{
		free(map);
		ft_printf("\e[31;1mError: Negative numbers of lemmins\033[0m\n");
		exit(-1);
	}
	map->nb = ft_atoi(str);
	check_only_nb(str, map);
	return (map);
}

void	double_end(t_map *map, int which_end)
{
	t_node	*tmp;

	if (which_end == 0)
		ft_printf("\e[31;1mError: Double start \033[0m\n");
	else if (which_end == 1)
		ft_printf("\e[31;1mError: Double end\033[0m\n");
	else if (which_end == 3)
		ft_printf("\e[31;1mError: start is end\033[0m\n");
	else if (which_end == 4)
		ft_printf("\e[31;1mError: Invalid island input\033[0m\n");
	while (map->begin)
	{
		tmp = map->begin->next;
		free(map->begin);
		map->begin = tmp;
	}
	free(map);
	exit(-1);
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

void	check_valid_island(char *str, t_map *map)
{
	int	r;

	if (!ft_strcmp(str, "##start") || !ft_strcmp(str, "##end"))
		return ;
	if (str[0] == ' ')
		double_end(map, 4);
	r = 1;
	while (str[r] != ' ' && str[r])
		r++;
	if (str[r] != ' ')
		double_end(map, 4);
	r++;
	while (str[r] >= 48 && str[r] <= 57)
		r++;
	if (str[r] != ' ')
		double_end(map, 4);
	r++;
	while (str[r] >= 48 && str[r] <= 57)
		r++;
	if (str[r] != '\0')
		double_end(map, 4);
}

int		start_end(int *start, int *end, t_map *map, char *str)
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

t_map	*error_case(t_map *map, int *start, int *end, t_node *new_node)
{
	if (*start == 1 && *end == 1)
		double_end(map, 3);
	if (*start == 1)
	{
		if (map->start)
			double_end(map, 0);
		map->start = new_node;
		*start = -1;
	}
	else if (*end == 1)
	{
		if (map->end)
			double_end(map, 1);
		map->end = new_node;
		*end = -1;
	}
	return (map);
}

t_map	*get_island(char *str, t_map *map)
{
	static int	start = 0;
	static int	end = 0;
	char		*tmp;
	t_node		*new_node;

	if (start_end(&start, &end, map, str))
		return (map);
	if (!(new_node = (t_node*)malloc(sizeof(t_node))))
		exit(-1);
	tmp = ft_strsub(str, 0, find_space(str));
	new_node->name = tmp;
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
			ft_printf("\e[31;1mError: link twice between ");
			ft_printf("%s and %s\033[0m\n", link->node->name, tmp->name);
			ft_clean_map(map);
			exit(-1);
		}
		link = link->next;
	}
}

void	error_road(char *name1, char *name2, t_node **tmp, t_node **tmp2)
{
	while (ft_strcmp((*tmp)->name, name1))
	{
		if (!(*tmp)->next)
		{
			ft_printf("\e[31;1m%s road not found\033[0m\n", name1);
			exit(-1);
		}
		(*tmp) = (*tmp)->next;
	}
	while (ft_strcmp((*tmp2)->name, name2))
	{
		if (!(*tmp2)->next)
		{
			ft_printf("\e[31;1m%s road not found\033[0m\n", name2);
			exit(-1);
		}
		(*tmp2) = (*tmp2)->next;
	}
}

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

void	link_on_road(t_node **tmp, t_node **tmp2)
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
	error_road(name1, name2, &tmp, &tmp2);
	link_on_road(&tmp, &tmp2);
	free(name1);
	return (map);
}

t_map	*add_line(char *str, t_map *map, int turn)
{
	if (turn == 0)
		map = get_ants(str, map);
	else if (turn == 1)
	{
		check_valid_island(str, map);
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

t_map	*read_file(t_map *map)
{
	int		turn;
	char	*str;

	str = NULL;
	turn = 0;
	while (get_next_line(0, &str))
	{
		if (str[0] == '#' && str[1] != '#')
		{
			free(str);
			continue ;
		}
		turn = check_turn(str, turn, map);
		map = add_line(str, map, turn);
		ft_printf("%s\n", str);
		if (str)
			free(str);
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
	map->jcpu = NULL;
	map->start = NULL;
	map->end = NULL;
	map->begin = NULL;
	map->nb = -42;
	map = read_file(map);
	ft_putchar('\n');
	return (map);
}
