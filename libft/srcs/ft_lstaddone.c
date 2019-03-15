/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 18:19:45 by oespion           #+#    #+#             */
/*   Updated: 2018/07/19 16:48:31 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstaddone(int nb, t_list *start, t_list *current)
{
	t_list	*new;

	if (!(new = ft_lstnew(nb)))
		return(NULL);
	current->next = new;
	new->prev = current;
	new->next = start;
	start->prev = new;
	return (new);
}
