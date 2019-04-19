/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group_tool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 18:32:13 by oespion           #+#    #+#             */
/*   Updated: 2019/04/19 18:38:28 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

int		ft_wroad_len(t_wroad *wroad)
{
	int nb;

	nb = 0;
	while (wroad)
	{
		wroad = wroad->next;
		nb++;
	}
	return (nb);
}

int		*init_tab(int *tab, int len)
{
	int	r;

	r = 0;
	while (r < len)
	{
		tab[r] = 0;
		r++;
	}
	return (tab);
}

int		ft_check_conflict(t_conflict *current, int r)
{
	while (current)
	{
		if (current->conflict == r)
			return (0);
		current = current->next;
	}
	return (1);
}

int		ft_get_len(int r, t_wroad *wroad)
{
	while (r != wroad->nb)
		wroad = wroad->next;
	return (wroad->len);
}

int		*ft_get_turn(t_wroad *wroad, t_wroad *current, t_map *map, int len)
{
	int	*tab;
	int	r;

	(void)map;
	if (!(tab = (int*)malloc(sizeof(int) * len)))
		exit(-1);
	tab = init_tab(tab, len);
	r = 0;
	while (r < len)
	{
		if (ft_check_conflict(current->conflict, r))
			tab[r] = ft_get_len(r, wroad);
		r++;
	}
	return (tab);
}
