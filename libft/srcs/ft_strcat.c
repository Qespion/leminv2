/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 11:21:55 by oespion           #+#    #+#             */
/*   Updated: 2018/06/05 10:16:39 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int	r;
	int	i;

	i = ft_strlen(dest);
	r = 0;
	while (src[r])
	{
		dest[i] = ((char*)src)[r];
		i++;
		r++;
	}
	dest[i] = '\0';
	return (dest);
}
