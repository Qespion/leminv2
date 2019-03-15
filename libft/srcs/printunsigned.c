/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printunsigned.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 15:06:39 by oespion           #+#    #+#             */
/*   Updated: 2018/06/05 10:16:52 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

intmax_t	getnb(t_printf *p, int maj)
{
	intmax_t	nb;

	if (p->l || maj)
		nb = va_arg(p->ap, long);
	else if (p->ll)
		nb = va_arg(p->ap, long long);
	else if (p->z)
		nb = va_arg(p->ap, size_t);
	else if (p->j)
		nb = va_arg(p->ap, intmax_t);
	else if (p->h)
		nb = (short)va_arg(p->ap, int);
	else if (p->hh)
		nb = (char)va_arg(p->ap, int);
	else
		nb = va_arg(p->ap, int);
	return (nb);
}

uintmax_t	getunb(t_printf *p, int maj)
{
	uintmax_t	nb;

	if (p->l || maj)
		nb = va_arg(p->ap, unsigned long);
	else if (p->h)
		nb = (unsigned short)va_arg(p->ap, unsigned int);
	else if (p->hh)
		nb = (unsigned char)va_arg(p->ap, unsigned int);
	else if (p->ll)
		nb = va_arg(p->ap, unsigned long long);
	else if (p->z)
		nb = va_arg(p->ap, size_t);
	else if (p->j)
		nb = va_arg(p->ap, uintmax_t);
	else
		nb = va_arg(p->ap, unsigned int);
	return (nb);
}

void		printnbunsigned(t_printf *p, uintmax_t nb)
{
	uintmax_t	pos;

	pos = nb;
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

void		printunb(t_printf *p, int maj)
{
	uintmax_t	nb;

	nb = getunb(p, maj);
	p->nopesign = 1;
	if (p->precision == -1 && p->width == -1)
	{
		p->nbout += uintmax_t_len(nb);
		ft_putnbr_uintmax(nb);
	}
	else
	{
		printnbunsigned(p, nb);
	}
}
