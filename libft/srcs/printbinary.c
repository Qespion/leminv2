/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printbinary.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 15:28:40 by oespion           #+#    #+#             */
/*   Updated: 2018/06/05 10:16:46 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	printbinary(t_printf *p)
{
	int		brett;
	char	*total;

	brett = va_arg(p->ap, int);
	total = ft_convert_binary(brett);
	while (*total)
	{
		ft_putchar(*total);
		total++;
		p->nbout++;
	}
}
