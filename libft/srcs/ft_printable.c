/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 11:37:15 by oespion           #+#    #+#             */
/*   Updated: 2018/06/05 10:16:30 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	printoctal(t_printf *p, int maj)
{
	intmax_t	nb;
	char		*total;

	p->hexa = 0;
	nb = getunb(p, maj);
	total = ft_convert_base(nb, 8);
	total[0] == '\0' ? total = "0" : 0;
	if (maj)
		total = ft_toupper(total);
	if (p->precision == -1 && p->width == -1)
	{
		p->nbout += ft_strlen(total);
		if (p->sharp && total[0] != '0')
		{
			ft_putchar('0');
			p->nbout++;
		}
		ft_putstr(total);
	}
	else if (total[0] == '0' && p->precision == 0
		&& p->width == -1 && !p->sharp)
		return ;
	else
		ft_putstrn_octal(p, total);
	total[0] != '0' ? ft_strdel(&total) : 0;
}

void	prints(t_printf *p)
{
	char	*str;

	if (p->l)
	{
		printlstring(p);
		return ;
	}
	str = va_arg(p->ap, char*);
	if (!str)
		str = "(null)";
	if (p->precision != -1 || p->width != -1)
		ft_putstrn(p, str);
	else
	{
		p->nbout += ft_strlen(str);
		ft_putstr(str);
	}
}

void	ft_get_adv_arg(char letter, t_printf *p)
{
	if (letter == 'U')
		printunb(p, 1);
	else if (letter == 'o')
		printoctal(p, 0);
	else if (letter == 'O')
		printoctal(p, 1);
	else if (letter == 'p')
		printaddress(p);
	else if (letter == 'C')
		printunicode(p);
	else if (letter == 'b')
		printbinary(p);
	else if (letter == 'S')
		printlstring(p);
}

void	ft_get_arg(char letter, t_printf *p)
{
	if (letter == 's' || letter == 'd' || letter == 'c' || letter == 'x'
			|| letter == 'b' || letter == 'i' || letter == 'X' || letter == 'u'
			|| letter == 'o' || letter == 'O' || letter == 'U' || letter == 'D'
			|| letter == 'p' || letter == 'C' || letter == 'S')
		p->increment = 1;
	if (letter == 's')
		prints(p);
	else if (letter == 'd' || letter == 'i')
		printnb(p, 0);
	else if (letter == 'c' || p->increment == 0)
		printchar(p, letter);
	else if (letter == 'D')
		printnb(p, 1);
	else if (letter == 'x')
		printhexa(p, 0);
	else if (letter == 'X')
		printhexa(p, 1);
	else if (letter == 'u')
		printunb(p, 0);
	else
		ft_get_adv_arg(letter, p);
}
