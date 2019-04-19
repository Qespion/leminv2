/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_conflict.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 18:39:52 by oespion           #+#    #+#             */
/*   Updated: 2019/04/19 18:54:49 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

void		ft_list_conflict(t_conflict **tmp, t_wroad **list, t_conflict **lbs)
{
	*tmp = (*list)->conflict;
	if (!(*list)->conflict)
		(*list)->conflict = *lbs;
	else
	{
		while ((*tmp)->next)
			*tmp = (*tmp)->next;
		(*tmp)->next = *lbs;
	}
}

void		ft_add_conflict(t_wroad *wroad, t_wroad *list)
{
	t_conflict	*base;
	t_conflict	*linked_base;
	t_conflict	*tmp;

	if (!(base = (t_conflict*)malloc(sizeof(t_conflict))))
		exit(-1);
	if (!(linked_base = (t_conflict*)malloc(sizeof(t_conflict))))
		exit(-1);
	base->conflict = list->nb;
	linked_base->conflict = wroad->nb;
	base->next = NULL;
	linked_base->next = NULL;
	tmp = wroad->conflict;
	if (!wroad->conflict)
		wroad->conflict = base;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = base;
	}
	ft_list_conflict(&tmp, &list, &linked_base);
}

int			ft_deep_check(t_road *base_road, t_road *tmp_road, t_map *map)
{
	unsigned int		len_base;
	unsigned int		len_tmp;

	len_base = 0;
	len_tmp = 0;
	if (base_road->current == map->start || base_road->current == map->end
		|| tmp_road->current == map->start || tmp_road->current == map->end)
		return (0);
	while (base_road)
	{
		len_base++;
		base_road = base_road->prev;
	}
	while (tmp_road)
	{
		len_tmp++;
		tmp_road = tmp_road->prev;
	}
	return (1);
}

t_wroad		*check_conflict(t_wroad *wroad, t_map *map)
{
	t_wroad	*tmp_wroad;
	t_road	*base;
	t_road	*compare;

	base = wroad->path;
	tmp_wroad = wroad->next;
	while (base)
	{
		while (tmp_wroad)
		{
			compare = tmp_wroad->path;
			while (compare)
			{
				if (base->current == compare->current
					&& ft_deep_check(base, compare, map))
					ft_add_conflict(wroad, tmp_wroad);
				compare = compare->prev;
			}
			tmp_wroad = tmp_wroad->next;
		}
		base = base->prev;
		tmp_wroad = wroad->next;
	}
	return (wroad);
}
