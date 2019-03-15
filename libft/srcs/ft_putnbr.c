/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 11:53:29 by oespion           #+#    #+#             */
/*   Updated: 2018/06/05 10:16:21 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(intmax_t nb)
{
	if (nb < -9223372036854775807)
		ft_putstr("-9223372036854775808");
	else if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(nb *= -1);
	}
	else
		ft_putchar('0' + nb);
}

void	ft_putnbr_uintmax(uintmax_t nb)
{
	if (nb > 9)
	{
		ft_putnbr_uintmax(nb / 10);
		ft_putnbr_uintmax(nb % 10);
	}
	else
		ft_putchar('0' + nb);
}
