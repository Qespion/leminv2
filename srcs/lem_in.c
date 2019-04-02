/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 16:27:46 by oespion           #+#    #+#             */
/*   Updated: 2019/04/02 11:11:48 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

int	no_path(t_map *map)
{
	t_node	*begin;

	begin = map->begin;
	while (begin)
	{
		if (begin->link)
			return (1);
		begin = begin->next;
	}
	return (0);
}

int	is_valid(t_map *map)
{
	if (!no_path(map) || !map->start || !map->end || !map->start->link)
		return (0);
	return (1);
}

void	print_help()
{
	ft_printf(" \e[32;40mNAME\033[0m\n");
	ft_printf("	lem_in -- flow network simulator\n\n");
	ft_printf(" \e[32;40mUSAGE\033[0m\n");
	ft_printf("	./lem_in [-mfngrl] < map\n\n");
	ft_printf(" \e[32;40mOPTIONS\033[0m\n");
	ft_printf("	%-20s%-6s%s\n", "--help", "-h", "display help.");
	ft_printf("	%-20s%-6s%s\n", "--max_roads", "-m", "display max_roads in graph.");
	ft_printf("	%-20s%-6s%s\n", "--first_roads", "-f", "display first roads in graph.");
	ft_printf("	%-20s%-6s%s\n", "--nb_working", "-n", "display numbers of working roads found with BFS.");
	ft_printf("	%-20s%-6s%s\n", "--graph", "-g", "display graph.");
	ft_printf("	%-20s%-6s%s\n", "--road_gestion", "-r", "display possible combinaison of roads.");
	ft_printf("	%-20s%-6s%s\n", "--line_nb", "-l", "display the number of line written.");
	exit(0);
}

// print max roads
// print first roads
// print nb working roads
// print graph
// print roads gestion
// print nb line

void	usage(int ac, char **av)
{
	int	r;

	r = 1;
	while (r < ac)
	{
		if (!ft_strcmp(av[r], "-m") || !ft_strcmp(av[r], "--max_roads"))
			g_flags |= MAXROADS;
		else if (!ft_strcmp(av[r], "-f") || !ft_strcmp(av[r], "--first_roads"))
			g_flags |= FIRSTROADS;
		else if (!ft_strcmp(av[r], "-n") || !ft_strcmp(av[r], "--nb_working"))
			g_flags |= NBWORKING;
		else if (!ft_strcmp(av[r], "-g") || !ft_strcmp(av[r], "--graph"))
			g_flags |= GRAPH;
		else if (!ft_strcmp(av[r], "-r") || !ft_strcmp(av[r], "--road_gestion"))
			g_flags |= ROADGESTION;
		else if (!ft_strcmp(av[r], "-l") || !ft_strcmp(av[r], "--line_nb"))
			g_flags |= LINENB;
		else if (!ft_strcmp(av[r], "-h") || !ft_strcmp(av[r], "--help"))
			print_help();
		r++;
	}
}

int	main(int ac, char **av)
{
	int			max_roads;
	t_map	*map;
	t_solve	*routes;
	
	g_flags =  0U;
	if (ac > 1)
		usage(ac, av);
	map = nget_file();
	if (!is_valid(map))
	{
		ft_printf("Error: Invalid map\n");
		ft_clean_map(map);
		return (-1);		
	}
	max_roads = get_max_roads(map);
	if (g_flags & MAXROADS)
		ft_printf("\n\e[32;40mMAX ROADS IN GRAPH\033[0m\n%d\n", max_roads);
	routes = create_base_routes(map, max_roads);
	routes = create_routes(map, max_roads, routes);
	ft_clean_map(map);
	return (0);
}
