/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 16:27:46 by oespion           #+#    #+#             */
/*   Updated: 2019/03/25 15:19:56 by oespion          ###   ########.fr       */
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

int	main(int ac, char **av)
{
	int			max_roads;
	t_map	*map;
	t_solve	*routes;
	(void)av;
	if (ac > 1)
	{
		ft_printf("usage: ./lem-in\n");
		exit(-1);
	}
	map = get_file();
	if (!no_path(map) || !map->start || !map->end)
		exit(-1);
	max_roads = get_max_roads(map);
	// ft_printf("\nmax roads %d\n", max_roads);
	// exit(-1);
	routes = create_base_routes(map, max_roads);
	routes = create_routes(map, max_roads, routes);
	
	ft_clean_map(map);
	return (0);
}
