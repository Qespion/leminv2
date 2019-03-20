/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_conflict.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 15:43:09 by oespion           #+#    #+#             */
/*   Updated: 2019/03/20 15:10:22 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

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
	
	tmp = list->conflict;
	if (!list->conflict)
		list->conflict = linked_base;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = linked_base;
	}
}

int		ft_deep_check(t_road *base_road, t_road *tmp_road, t_map *map)
{
	unsigned int		len_base;
	unsigned int		len_tmp;
	t_conflict				*tmp;

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
	// if (ft_abs(len_base - len_tmp) > (map->nb / 2))
	// 	return (0);
	return (1);
}

t_wroad		*check_conflict(t_wroad *wroad, t_map *map)
{
	int	nb;
	t_wroad	*tmp_wroad;
	t_road	*base;
	t_road	*compare;

	nb = 0;
	base = wroad->path;
	tmp_wroad = wroad->next;
	while (base)
	{
		while (tmp_wroad)
		{
			compare = tmp_wroad->path;
			while (compare)
			{
				if (base->current == compare->current)
				{
					if (ft_deep_check(base, compare, map))
					{
						// ft_printf("base %s\n", base->current->name);
						// ft_printf("compare %s\n", compare->current->name);
						ft_add_conflict(wroad, tmp_wroad);
						// ft_printf("base %s\n", base->current->name);
						// ft_printf("compare %s\n", compare->current->name);
					}
				}
				compare = compare->prev;
			}
			tmp_wroad = tmp_wroad->next;
		}
		base = base->prev;
		tmp_wroad = wroad->next;
	}
	return (wroad);
}

void			ft_print_conflict(t_wroad *wroad)
{
	t_conflict *tmp;
	int		raod = 0;
	while (wroad)
	{
		ft_printf("\nnb %d -=", raod++);
		tmp = wroad->conflict;
		while (tmp)
		{
			ft_printf("- %d -", tmp->conflict);
			tmp = tmp->next;
		}
		wroad = wroad->next;
	}
	ft_putchar('\n');
}

t_wroad		*clean_conflict(t_wroad *wroad)
{
	t_wroad		*tmp_wroad;
	t_conflict		*prev;
	t_conflict		*tmp;

	tmp_wroad = wroad;
	while (tmp_wroad)
	{
		tmp = tmp_wroad->conflict;
		while (tmp)
		{
			if (tmp->conflict == -1)
			{
				prev->next = tmp->next;
				free(tmp);
				tmp = prev;
			}
			prev = tmp;
			if (tmp)
				tmp = tmp->next;
		}
		tmp_wroad = tmp_wroad->next;
	}
	return (wroad);
}

t_wroad		*remove_double(t_wroad *wroad)
{
	t_wroad		*tmp_wroad;
	t_conflict	*tmp;
	t_conflict	*prev_tmp;
	t_conflict	*start;

	tmp_wroad = wroad;
	while (tmp_wroad)
	{
		tmp = tmp_wroad->conflict;
		while (tmp)
		{
			start = tmp_wroad->conflict;
			while (start != tmp)
			{
				if (start->conflict == tmp->conflict)
				{
					tmp->conflict = -1;
					break ;
				}
				start = start->next;
			}
			prev_tmp = tmp;
			if (tmp)
				tmp = tmp->next;
		}
		tmp_wroad = tmp_wroad->next;
	}
	return (wroad);
}

t_wroad		*ft_find_conflict(t_wroad *wroad, t_map *map)
{
	t_wroad	*tmp;

	tmp = wroad;
	while (tmp)
	{
		tmp = check_conflict(tmp, map);
		tmp = tmp->next;
	}
	wroad = remove_double(wroad);
	wroad = clean_conflict(wroad);
	ft_print_conflict(wroad);
	return (wroad);
}
