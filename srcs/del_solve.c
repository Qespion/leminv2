/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_solve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 19:41:30 by oespion           #+#    #+#             */
/*   Updated: 2019/02/19 15:29:30 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

void	del_road(t_solve *todel)
{
	t_road *next;

	while (todel->path)
	{
		next = todel->path->prev;
		free(todel->path);
		todel->path = next;
	}
}

t_solve	*ft_del_solve(t_solve *start, t_solve *todel)
{
	t_solve	*tmp;

	tmp = start;
	if (tmp == todel)
	{
		start = start->next;
		del_road(todel);
		return (start);
	}
	while (tmp->next != todel)
		tmp = tmp->next;
	if (!todel->next)
	{
		tmp->next = NULL;
		del_road(todel);
		return (start);
	}
	else
	{
		tmp->next = todel->next;
		del_road(todel);
		return (start);
	}
}
