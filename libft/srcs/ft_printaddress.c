/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printaddress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 18:23:55 by oespion           #+#    #+#             */
/*   Updated: 2018/06/05 10:16:28 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	address_width(t_printf *p, char *total)
{
	int		r;
	char	spaces;

	spaces = ' ';
	p->zeros && !p->negative ? spaces = '0' : 0;
	r = p->width;
	total[0] == '\0' ? r-- : 0;
	while (r > ft_strlen(total) + 2)
	{
		ft_putchar(spaces);
		r--;
		p->nbout++;
	}
}

void	address_precision(t_printf *p, char *total)
{
	int	r;

	r = p->precision;
	total[0] == '\0' ? r-- : 0;
	while (r > ft_strlen(total))
	{
		ft_putchar('0');
		r--;
		p->nbout++;
	}
}

void	printaddress(t_printf *p)
{
	uintmax_t	adr;
	char		*total;

	adr = (uintmax_t)va_arg(p->ap, void*);
	total = ft_convert_base(adr, 16);
	total[0] == '\0' ? total = "0" : 0;
	if (p->negative)
	{
		ft_putstr("0x");
		address_precision(p, total);
		ft_putstr(total[0] == '0' && p->precision == 0 ? "" : total);
		address_width(p, total);
	}
	else
	{
		!p->zeros ? address_width(p, total) : 0;
		ft_putstr("0x");
		p->zeros ? address_width(p, total) : 0;
		address_precision(p, total);
		ft_putstr(total[0] == '0' && p->precision == 0 ? "" : total);
	}
	total[0] == '\0' ? p->nbout++ : 0;
	p->nbout += ft_strlen(total) + 2;
	total[0] == '0' && p->precision == 0 ? p->nbout-- : 0;
	total[0] != '0' ? ft_strdel(&total) : 0;
}
