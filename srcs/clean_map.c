/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avo <avo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 13:49:19 by avo               #+#    #+#             */
/*   Updated: 2019/03/19 15:27:35 by avo              ###   ########.fr       */
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