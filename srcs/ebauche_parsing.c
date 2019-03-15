/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ebauche_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avo <avo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 22:48:47 by avo               #+#    #+#             */
/*   Updated: 2018/11/03 14:11:50 by avo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

void	get_ants(char *str, int *turn, t_map **map, int border)
{
	if (str[0] == '#' && str[1] != '#')
		return ;
	if (ft_strlen(str) > 13 || ft_atoi(str) > 2147483647
		|| ft_atoi(str) < -2147483648
		|| ((ft_atoi(str) == 0 && str[0] != '0')))
	{
		ft_printf("404 on lemmins");
		exit(-1);
	}
	(*map)->nb = ft_atoi(str);
	ft_printf("%d\n", (*map)->nb);
	*turn += 1;
}

void	get_roads(char *str, int *turn, t_map **map, int border)
{
	if (str[0] == '#' && str[1] != '#')
		return ;
	ft_printf("fsdfas\n");
	ft_printf("%s\n", (*map)->nb);
	ft_printf(str);
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

void	get_island(char *str, int *turn, t_map **map, int border)
{
	t_node	*new_node;

	if (str[0] == '#' && str[1] != '#')
		return ;
	else if (ft_strstr(str, "-"))
	{
		*turn += 1;
		get_roads(str, turn, map, border);
		return ;
	}
	if(!(new_node = (t_node*)malloc(sizeof(t_node))))
		exit(-1);
	if ((*map)->jcpu)
		(*map)->jcpu->next = new_node;
	(*map)->jcpu = new_node;

	new_node->name = ft_strsub(str, 0, find_space(str));
	new_node->link = NULL;
	new_node->next = NULL;
}

t_map	*parse_file(char *str, int border)
{
	static	int turn;
	void	(*parse[2])(char *, int *, t_map **, int border);
	t_map	*map;

	if(!(map = (t_map*)malloc(sizeof(t_map))))
		exit(-1);
	map->jcpu = NULL;
	map->start = NULL;
	map->end = NULL;
	parse[0] = get_ants;
	parse[1] = get_island;
	parse[2] = get_roads;
	if (turn < 3)
		parse[turn](str, &turn, &map, border);
	ft_putchar('\n');
	ft_putnbr(turn);
	ft_putchar('\n');
	return (map);
}

void	get_file(char *file)
{
	int		 fd;
	int		border;
	char	*str;
	t_map	*map;

	border = 0;
	fd = open(file, 0);
	while (get_next_line(fd, &str))
	{
		border = (border == 1 ? -1 : 0);
		if (!ft_strcmp("##start", str))
		{
			border = 1;
			continue ;
		}	
		else if (!ft_strcmp("##end", str))
		{
			border = (border == -1 ? 3 : 2);
			continue ;
		}	
		map = parse_file(str, border);
		ft_strdel(&str);
	}
	ft_strdel(&str);

}
