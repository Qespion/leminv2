/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstring_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 11:45:23 by oespion           #+#    #+#             */
/*   Updated: 2018/06/05 10:16:43 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		single_len(t_printf *p, int nb)
{
	int	len;

	len = 0;
	if (p->precision == -1)
		return (1);
	nb < 128 ? len = 1 : 0;
	nb >= 128 && nb < 2048 ? len = 2 : 0;
	nb >= 2048 && nb < 65536 ? len = 3 : 0;
	nb >= 65536 ? len = 4 : 0;
	MB_CUR_MAX == 1 ? len = 1 : 0;
	return (len);
}

int		check_brett_tab(wchar_t *brett, t_printf *p)
{
	int	r;
	int	len;

	len = 0;
	r = 0;
	while (brett[r])
	{
		len += single_len(p, brett[r]);
		if (len > p->precision && p->precision != -1)
			break ;
		if ((MB_CUR_MAX == 1 && brett[r] > 255) || (brett[r] <= 917759
			&& brett[r] >= 917632)
				|| (brett[r] >= 918000 && brett[r] <= 983039)
				|| (brett[r] >= 55296 && brett[r] <= 57343)
				|| brett[r] >= 1114112 || brett[r] < 0)
			return (0);
		r++;
	}
	return (1);
}
