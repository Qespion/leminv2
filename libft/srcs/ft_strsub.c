/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 11:23:21 by oespion           #+#    #+#             */
/*   Updated: 2018/08/28 19:35:09 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	r;
	char	*str;

	r = 0;
	if (!s || !len)
		return (ft_strnew(1));
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		exit (-1);
	while (r < len)
	{
		str[r] = s[start];
		r++;
		start++;
	}
	str[r] = '\0';
	return (str);
}
