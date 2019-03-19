/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avo <avo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 13:49:19 by avo               #+#    #+#             */
/*   Updated: 2019/03/19 09:55:56 by avo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

void	ft_clean_map(t_map *map)
{
    t_node  *tmp_node;
    t_link      *tmp_link;

    while (map->begin)
    {
        tmp_node = map->begin->next;
        while (map->begin->link)
        {
            tmp_link = map->begin->link->next;
            free(map->begin->link);
            map->begin->link = tmp_link;
        }
        free(map->begin->name);
        free(map->begin);
        map->begin = tmp_node;
    }
    free(map);
}

void    ft_clean_routes(t_solve *routes)
{
    t_solve *tmp_routes;
    t_road  *tmp_road;

    while (routes)
    {
        tmp_routes = routes->next;
        while (routes->path)
        {
            tmp_road = routes->path->prev;
            free(routes->path);
            routes->path = tmp_road;
        }
        free(routes);
        routes = tmp_routes;
    }
}
