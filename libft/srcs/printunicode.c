/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printunicode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 12:37:33 by oespion           #+#    #+#             */
/*   Updated: 2018/06/06 13:12:28 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	print_first(char *binary, int nlen)
{
	int		r;
	char	tab[8];
	int		index;

	index = (ft_strlen(binary) - (nlen - 1) * 6) - 1;
	r = 0;
	while (r < nlen)
		tab[r++] = '1';
	while (r < 7)
		tab[r++] = '0';
	tab[r] = '0';
	while (index >= 0)
	{
		if (binary[index] == '1')
			tab[r] = '1';
		index--;
		r--;
	}
	r = bin_to_dec(tab);
	write(1, &r, 1);
}

void	print_uni_width(t_printf *p, int nlen)
{
	int		width_tmp;
	int		r;
	char	spaces;

	spaces = ' ';
	r = 0;
	p->zeros ? spaces = '0' : 0;
	width_tmp = p->width - nlen;
	while (r < width_tmp)
	{
		p->nbout++;
		ft_putchar(spaces);
		r++;
	}
}

void	print_rest(char *binary, int index)
{
	int		r;
	char	tab[8];

	r = 0;
	tab[r++] = '1';
	while (r < 8)
		tab[r++] = '0';
	r = 2;
	while (r < 8)
	{
		tab[r++] = binary[index++];
	}
	r = bin_to_dec(tab);
	write(1, &r, 1);
}

void	break_bin(char *binary, t_printf *p, int brett)
{
	int	r;
	int	nlen;
	int	index;
	int	tmp;

	r = ft_strlen(binary) - 1;
	nlen = r / 6;
	if (r > 0)
		nlen += (r % 6 < 5) ? 1 : 2;
	brett >= 65536 ? nlen = 4 : 0;
	index = (ft_strlen(binary) - (nlen - 1) * 6);
	!p->negative ? print_uni_width(p, nlen) : 0;
	tmp = nlen;
	print_first(binary, nlen);
	p->nbout += nlen;
	while (nlen - 1 > 0)
	{
		print_rest(binary, index);
		nlen--;
		index += 6;
	}
	p->negative ? print_uni_width(p, tmp) : 0;
}

void	printunicode(t_printf *p)
{
	int		brett;
	char	*binary;

	!p->brett ? brett = va_arg(p->ap, int) : 0;
	p->brett ? brett = p->brett : 0;
	p->brett = 0;
	if ((MB_CUR_MAX == 1 && brett > 255) || (brett <= 917759 && brett >= 917632)
			|| (brett >= 918000 && brett <= 983039)
			|| (brett >= 55296 && brett <= 57343)
			|| brett >= 1114112 || brett < 0)
	{
		p->brett = -1;
		return ;
	}
	if (brett <= 127 || (brett <= 255 && MB_CUR_MAX == 1))
	{
		!p->negative ? print_uni_width(p, 1) : 0;
		write(1, &brett, 1);
		p->negative ? print_uni_width(p, 1) : 0;
		p->nbout++;
		return ;
	}
	binary = ft_convert_base(brett, 2);
	break_bin(binary, p, brett);
	ft_strdel(&binary);
}
