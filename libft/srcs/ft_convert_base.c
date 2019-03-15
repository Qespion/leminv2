/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 14:37:21 by oespion           #+#    #+#             */
/*   Updated: 2018/06/05 10:16:32 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		int_len(uintmax_t nb, int base)
{
	int	len;

	len = 0;
	while (nb > 0)
	{
		nb /= base;
		len++;
	}
	return (len);
}

char	*ft_convert_base(uintmax_t nb, int base)
{
	int		len;
	char	*total;
	char	*tab;

	tab = "0123456789abcdef";
	len = int_len(nb, base);
	if (len == 0)
		return ("\0");
	if (!(total = (char*)malloc(sizeof(char) * len)))
		return (0);
	total[len--] = '\0';
	while (len >= 0)
	{
		total[len] = tab[nb % base];
		nb /= base;
		len--;
	}
	return (total);
}

char	*ft_convert_binary(uintmax_t nb)
{
	char	*tab;
	int		len;
	int		r;

	r = 0;
	len = 18;
	if (!(tab = (char*)malloc(sizeof(char) * 18)))
		return (0);
	tab[len] = '\0';
	while (len >= 0)
	{
		tab[len] = nb % 2 + 48;
		nb /= 2;
		len--;
		r++;
		if (r == 4)
		{
			r = 0;
			tab[len] = ' ';
			len--;
		}
	}
	return (tab);
}

int		bin_to_dec(char *bin)
{
	int		len;
	int		total;
	int		add;

	add = 1;
	len = 7;
	total = 0;
	while (len >= 0)
	{
		if (bin[len] == '1')
			total += add;
		add += add;
		len--;
	}
	return (total);
}
