/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_conflict.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 15:43:09 by oespion           #+#    #+#             */
/*   Updated: 2019/04/19 18:45:14 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

void		ft_print_conflict(t_wroad *wroad)
{
	int			raod;
	t_conflict	*tmp;

	raod = 0;
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
	t_wroad			*tmp_wroad;
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
			tmp = tmp ? tmp->next : tmp;
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
	return (wroad);
}
