/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printhexa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 14:35:35 by oespion           #+#    #+#             */
/*   Updated: 2018/06/05 10:16:48 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	print_precision(t_printf *p, char *str)
{
	int	precision_tmp;

	precision_tmp = p->precision - ft_strlen(str);
	p->sharp && !p->hexa && str[0] != '0' ? precision_tmp-- : 0;
	while (precision_tmp-- > 0)
	{
		ft_putchar('0');
		p->nbout++;
	}
}

void	print_width(t_printf *p, char *str)
{
	int	spaces;
	int	max;
	int	width_tmp;

	max = 0;
	width_tmp = p->width;
	spaces = ' ';
	p->zeros && p->precision == -1 && !p->negative ? spaces = '0' : 0;
	if ((p->neg || p->positive) && !p->negative)
		width_tmp--;
	if (ft_strlen(str) > p->precision)
		max += ft_strlen(str);
	else
		max += p->precision;
	p->sharp && p->hexa && str[0] != '0' ? max += 2 : 0;
	p->sharp && !p->hexa && str[0] != '0' ? max++ : 0;
	while (max < width_tmp--)
	{
		p->nbout++;
		ft_putchar(spaces);
	}
}

void	ft_putstrn_hexa(t_printf *p, char *str, int maj)
{
	int	r;

	r = 0;
	p->nbout += ft_strlen(str);
	if (p->sharp && p->zeros && p->precision == -1 && str[0] != '0')
	{
		maj ? ft_putstr("0X") : ft_putstr("0x");
		print_precision(p, str);
		p->nbout += 2;
		r = 1;
	}
	!p->negative ? print_width(p, str) : 0;
	if (r == 0 && p->sharp && str[0] != '0')
	{
		maj ? ft_putstr("0X") : ft_putstr("0x");
		print_precision(p, str);
		p->nbout += 2;
		r = 1;
	}
	r == 0 ? print_precision(p, str) : 0;
	str[0] == '0' && p->precision == 0 ? ft_putchar(' ') : ft_putstr(str);
	p->negative ? print_width(p, str) : 0;
}

void	ft_putstrn_octal(t_printf *p, char *str)
{
	int	r;

	r = 0;
	p->nbout += ft_strlen(str);
	if (p->sharp && p->zeros && p->precision == -1 && str[0] != '0')
	{
		ft_putchar('0');
		print_precision(p, str);
		p->nbout++;
		r = 1;
	}
	!p->negative ? print_width(p, str) : 0;
	if (r == 0 && p->sharp && str[0] != '0')
	{
		ft_putchar('0');
		print_precision(p, str);
		p->nbout++;
		r = 1;
	}
	r == 0 ? print_precision(p, str) : 0;
	str[0] == '0' && p->precision == 0
		&& !p->sharp ? ft_putchar(' ') : ft_putstr(str);
	p->negative ? print_width(p, str) : 0;
}

void	printhexa(t_printf *p, int maj)
{
	intmax_t	nb;
	char		*total;

	p->hexa = 1;
	nb = getunb(p, 0);
	total = ft_convert_base(nb, 16);
	total[0] == '\0' ? total = "0" : 0;
	if (maj)
		total = ft_toupper(total);
	if (p->precision == -1 && p->width == -1)
	{
		p->nbout += ft_strlen(total);
		if (p->sharp && total[0] != '0')
		{
			maj ? ft_putstr("0X") : ft_putstr("0x");
			p->nbout += 2;
		}
		ft_putstr(total);
	}
	else if (total[0] == '0' && p->precision == 0 && p->width == -1)
		return ;
	else
		ft_putstrn_hexa(p, total, maj);
	total[0] != '0' ? ft_strdel(&total) : 0;
}
