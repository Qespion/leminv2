/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_roads.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 16:28:06 by oespion           #+#    #+#             */
/*   Updated: 2019/02/06 16:28:08 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

int get_max_roads(t_map *map)
{
    int     total;
    int     count;
    t_link  *tmp;

    count = 0;
    total = 0;
    tmp = map->start->link;
    while (tmp)
    {
        tmp = tmp->next;
        count++;
    }
    total = count;
    count = 0;
    tmp = map->end->link;
    while (tmp)
    {
        tmp = tmp->next;
        count++;
    }
    return (count < total ? count : total);
}
