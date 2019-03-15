/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_working_roads.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avo <avo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 18:13:27 by oespion           #+#    #+#             */
/*   Updated: 2019/03/04 14:44:59 by avo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

void	print_working_roads(t_wroad *wroad, t_map *map)
{
	t_wroad	*tmp;
	t_road		*tmp_road;

	tmp = wroad;
	int		roadnb = 0;
	ft_printf("starting printing working roads \n----\n");
	while (tmp)
	{
		tmp_road = tmp->path;
		while (tmp_road)
		{
			ft_printf("road: %s\n", tmp_road->current->name);
			tmp_road = tmp_road->prev;
		}
		roadnb++;
		ft_printf("roadname: %d\n", tmp->nb);
		ft_printf("roadlen: %d\n", tmp->len);		
		ft_printf("road nb %d\n", roadnb);
		tmp = tmp->next;
	}
}
