/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcharn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 18:09:47 by oespion           #+#    #+#             */
/*   Updated: 2018/06/05 10:16:23 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	ft_putcharn(t_printf *p, char c)
{
	int		len_width;
	char	spaces;

	spaces = ' ';
	if (p->zeros && p->negative == 0)
		spaces = '0';
	len_width = 1;
	if (p->negative == 0)
		while (len_width++ < p->width)
		{
			p->nbout++;
			ft_putchar(spaces);
		}
	ft_putchar(c);
	p->nbout++;
	if (p->negative == 1)
		while (len_width++ < p->width)
		{
			p->nbout++;
			ft_putchar(spaces);
		}
}

void	ft_putcharnf(t_printf *p, char letter)
{
	int		len_width;
	char	spaces;

	spaces = ' ';
	if (p->zeros && p->negative == 0)
		spaces = '0';
	len_width = 1;
	if (p->negative == 0)
		while (len_width++ < p->width)
		{
			p->nbout++;
			ft_putchar(spaces);
		}
	ft_putchar(letter);
	if (p->negative == 1)
		while (len_width++ < p->width)
		{
			p->nbout++;
			ft_putchar(spaces);
		}
}
