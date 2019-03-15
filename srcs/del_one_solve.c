/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_one_solve.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 18:49:46 by oespion           #+#    #+#             */
/*   Updated: 2019/02/19 16:40:55 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

t_solve *ft_del_one_solve(t_solve *start, t_solve *todel)
{
	t_solve	*tmp;

	tmp = start;
	if (tmp == todel)
	{
		start = start->next;
		return (start);
	}
	while (tmp->next != todel)
		tmp = tmp->next;
	if (!todel->next)
	{
		tmp->next = NULL;
		return (start);
	}
	else
	{
		tmp->next = todel->next;
		return (start);
	}
}
