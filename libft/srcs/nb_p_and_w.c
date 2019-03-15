/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_p_and_w.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 15:32:22 by oespion           #+#    #+#             */
/*   Updated: 2018/06/05 10:16:44 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_pos(t_printf *p)
{
	if (p->positive == 1 && !p->neg && !p->nopesign)
	{
		p->nbout++;
		ft_putchar('+');
		p->neg = 3;
		p->width > 0 ? p->width-- : 0;
	}
	if (p->neg == 1)
	{
		p->nbout++;
		ft_putchar('-');
		p->neg = 2;
	}
	p->positive = 2;
}

void	ft_get_precision(uintmax_t nbr, t_printf *p)
{
	int	precision_tmp;

	precision_tmp = p->precision;
	ft_pos(p);
	while (uintmax_t_len(nbr) < precision_tmp)
	{
		ft_putchar('0');
		p->nbout++;
		precision_tmp--;
	}
}

void	width_write(int max, int width_tmp, char spaces, t_printf *p)
{
	while (max < width_tmp--)
	{
		p->nbout++;
		ft_putchar(spaces);
	}
}
