/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 16:27:46 by oespion           #+#    #+#             */
/*   Updated: 2019/05/01 12:52:06 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

void	print_help(void)
{
	ft_printf(" \e[32;40mNAME\033[0m\n");
	ft_printf("	lem_in -- flow network simulator\n\n");
	ft_printf(" \e[32;40mUSAGE\033[0m\n");
	ft_printf("	./lem_in [-mfngrl] < map\n\n");
	ft_printf(" \e[32;40mOPTIONS\033[0m\n");
	ft_printf("	%-20s%-6s%s\n", "--help", "-h", "display help.");
	ft_printf("	%-20s", "--max_roads");
	ft_printf("%-6s%s\n", "-m", "display max_roads in graph.");
	ft_printf("	%-20s", "--first_roads");
	ft_printf("%-6s%s\n", "-f", "display first roads in graph.");
	ft_printf("	%-20s", "--nb_working");
	ft_printf("%-6s%s\n", "-n", "numbers of working roads found with BFS.");
	ft_printf("	%-20s%-6s%s\n", "--graph", "-g", "display graph.");
	ft_printf("	%-20s", "--road_gestion");
	ft_printf("%-6s%s\n", "-r", "display possible combinaison of roads.");
	ft_printf("	%-20s", "--line_nb");
	ft_printf("%-6s%s\n", "-l", "display the number of line written.");
	exit(0);
}

void	short_usage(char *str)
{
	str++;
	while (*str)
	{
		if (*str == 'm')
			g_flags |= MAXROADS;
		else if (*str == 'f')
			g_flags |= FIRSTROADS;
		else if (*str == 'n')
			g_flags |= NBWORKING;
		else if (*str == 'g')
			g_flags |= GRAPH;
		else if (*str == 'r')
			g_flags |= ROADGESTION;
		else if (*str == 'l')
			g_flags |= LINENB;
		else if (*str == 'h')
			print_help();
		else
		{
			ft_printf("\e[31;1mERROR: '%c' ", *str);
			ft_printf("is not a proper argument\033[0m\n");
			print_help();
		}
		str++;
	}
}

void	usage(int ac, char **av)
{
	int	r;

	r = 1;
	while (r < ac)
	{
		if (!ft_strcmp(av[r], "--max_roads"))
			g_flags |= MAXROADS;
		else if (!ft_strcmp(av[r], "--first_roads"))
			g_flags |= FIRSTROADS;
		else if (!ft_strcmp(av[r], "--nb_working"))
			g_flags |= NBWORKING;
		else if (!ft_strcmp(av[r], "--graph"))
			g_flags |= GRAPH;
		else if (!ft_strcmp(av[r], "--road_gestion"))
			g_flags |= ROADGESTION;
		else if (!ft_strcmp(av[r], "--line_nb"))
			g_flags |= LINENB;
		else if (!ft_strcmp(av[r], "--help"))
			print_help();
		else if (av[r][0] == '-' && av[r][1])
			short_usage(av[r]);
		else
			print_help();
		r++;
	}
}

int		main(int ac, char **av)
{
	int		max_roads;
	t_map	*map;
	t_solve	*routes;

	g_flags = 0U;
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
	routes = create_base_routes(map);
	if (g_flags & NBWORKING)
		ft_printf("\e[32;40mWORKING ROADS FOUND IN BFS:\033[0m\n");
	routes = create_routes(map, max_roads, routes);
	ft_clean_map(map);
	return (0);
}
