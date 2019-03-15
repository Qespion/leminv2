/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_one.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avo <avo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 14:56:52 by oespion           #+#    #+#             */
/*   Updated: 2018/07/24 14:11:01 by avo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	**ft_insert_one(t_list **global, int lst_nb, int nb)
{
	t_list	*new;
	t_list	*before;
	t_list	*after;

	new = ft_lstnew(nb);
	if (!new)
	{
		ft_lstdel(global[1]);
		ft_lstdel(global[0]);
		free(global);
		exit(-1);
	}
	before = global[lst_nb]->prev;
	after = global[lst_nb];
	before->next = new;
	after->prev = new;
	global[lst_nb] = new;
	new->next = after;
	new->prev = before;
	return (global);
}
