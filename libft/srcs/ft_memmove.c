/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 11:20:46 by oespion           #+#    #+#             */
/*   Updated: 2018/06/05 13:19:42 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*tmp_src;
	unsigned char	*tmp_dst;
	size_t			r;

	r = 0;
	tmp_dst = (unsigned char *)dest;
	tmp_src = (unsigned char *)src;
	if (tmp_dst < tmp_src)
	{
		while (r < n)
		{
			tmp_dst[r] = tmp_src[r];
			r++;
		}
	}
	else
	{
		n--;
		while ((int)n >= 0)
		{
			tmp_dst[n] = tmp_src[n];
			n--;
		}
	}
	return ((void*)tmp_dst);
}
