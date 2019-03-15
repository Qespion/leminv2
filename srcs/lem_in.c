/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avo <avo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 16:27:46 by oespion           #+#    #+#             */
/*   Updated: 2019/03/04 11:02:22 by avo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

int	main(int ac, char **av)
{
	int			max_roads;
	t_map	*map;
	t_solve	*routes;
	if (ac > 1)
	{
		ft_printf("usage: ./lem-in\n");
		exit(-1);
	}
	map = get_file(av[1]);
	max_roads = get_max_roads(map);
	ft_printf("\nmax roads %d\n", max_roads);
	routes = create_base_routes(map, max_roads);
	routes = create_routes(map, max_roads, routes);
	// loop on base unti
	return (0);
}
