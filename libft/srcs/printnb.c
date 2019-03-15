/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printnb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 12:48:45 by oespion           #+#    #+#             */
/*   Updated: 2018/06/05 10:16:50 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_get_width(t_printf *p, uintmax_t nbr)
{
	char	spaces;
	int		max;
	int		width_tmp;

	max = 0;
	width_tmp = p->width;
	spaces = ' ';
	p->nopesign == 0 && p->blank == 1 && !p->neg && !p->positive ? max++ : 0;
	nbr == 0 && p->precision == 0 && p->width > 0 ? ft_putchar(' ') : 0;
	nbr == 0 && p->precision == 0 && p->width > 0 ? p->nbout++ : 0;
	p->zeros && !p->negative && p->precision == -1 ? spaces = '0' : 0;
	if ((p->neg || p->positive) && !p->negative)
		width_tmp--;
	if (spaces == '0' && p->neg && !p->negative)
		ft_pos(p);
	((p->neg == 1 || p->neg == 2) && spaces == '0') ? max-- : 0;
	spaces == '0' && !p->negative && p->positive ? ft_pos(p) : 0;
	if (uintmax_t_len(nbr) > p->precision)
		max += uintmax_t_len(nbr);
	else
		max += p->precision;
	p->neg == 2 ? width_tmp-- : 0;
	p->blank && p->negative && p->width > uintmax_t_len(nbr) ? max++ : 0;
	width_write(max, width_tmp, spaces, p);
}

void	printnbu(t_printf *p, intmax_t nb)
{
	uintmax_t	pos;

	nb < 0 ? p->neg = 1 : 0;
	pos = ft_abs(nb);
	if (p->negative)
	{
		ft_get_precision(pos, p);
		if (p->precision == 0 && nb == 0)
		{
			ft_get_width(p, pos);
			return ;
		}
		p->nbout += uintmax_t_len(pos);
		ft_putnbr_uintmax(pos);
		ft_get_width(p, pos);
	}
	else
	{
		ft_get_width(p, pos);
		ft_get_precision(pos, p);
		if (p->precision == 0 && nb == 0)
			return ;
		p->nbout += uintmax_t_len(pos);
		ft_putnbr_uintmax(pos);
	}
}

void	printnb_nbu(t_printf *p, intmax_t nb)
{
	if (!p->positive && p->blank && nb >= 0)
	{
		p->nbout++;
		ft_putchar(' ');
	}
	printnbu(p, nb);
}

void	printnb(t_printf *p, int maj)
{
	intmax_t	nb;

	nb = getnb(p, maj);
	p->nopesign = 0;
	if (p->precision == -1 && p->width == -1)
	{
		if (p->blank && p->width == -1 && nb >= 0 && !p->positive)
		{
			ft_putchar(' ');
			p->nbout++;
		}
		if (p->positive && nb >= 0)
		{
			p->nbout++;
			ft_putchar('+');
		}
		p->nbout += longlong_len(nb);
		ft_putnbr(nb);
	}
	else
		printnb_nbu(p, nb);
}
