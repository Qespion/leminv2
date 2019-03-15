/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printable_adv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 12:34:52 by oespion           #+#    #+#             */
/*   Updated: 2018/06/05 10:16:45 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_c_width(t_printf *p)
{
	int		width_tmp;
	int		r;
	char	spaces;

	spaces = ' ';
	r = 0;
	p->zeros && !p->negative ? spaces = '0' : 0;
	width_tmp = p->width - 1;
	while (r < width_tmp)
	{
		p->nbout++;
		ft_putchar(spaces);
		r++;
	}
}

int		printc(t_printf *p)
{
	int		brett;

	!p->brett ? brett = getnb(p, 0) : 0;
	p->brett ? brett = p->brett : 0;
	if (p->l)
	{
		p->brett = brett;
		printunicode(p);
		return (1);
	}
	!p->l ? brett = (char)brett : 0;
	if ((brett > 255 || brett < -255) && !p->l)
	{
		ft_putchar('\0');
		p->nbout++;
		return (0);
	}
	ft_putcharn(p, brett);
	return (1);
}

void	printchar(t_printf *p, char letter)
{
	if (letter == 'c')
	{
		printc(p);
		return ;
	}
	if ((p->precision != -1 || p->width != -1)
			&& letter != 'c')
		letter != '\0' ? ft_putcharnf(p, letter) : 0;
	else
		letter != '\0' ? ft_putchar(letter) : 0;
	letter != '\0' ? p->nbout++ : 0;
	letter != '\0' ? p->increment++ : 0;
}

int		checkunicode(t_printf *p)
{
	int		brett;

	brett = va_arg(p->ap, int);
	if ((MB_CUR_MAX == 1 && brett > 255) || (brett <= 917759 && brett >= 917632)
			|| (brett >= 918000 && brett <= 983039)
			|| (brett >= 55296 && brett <= 57343)
			|| brett >= 1114112 || brett < 0)
	{
		p->brett = -1;
		return (1);
	}
	p->brett = brett;
	return (0);
}
