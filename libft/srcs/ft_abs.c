/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 14:59:58 by oespion           #+#    #+#             */
/*   Updated: 2018/06/05 10:16:34 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

uintmax_t	ft_abs(long long nb)
{
	uintmax_t	nbr;

	nbr = 0;
	if (nb < 0)
		nbr = nb * -1;
	else
		nbr = nb;
	return (nbr);
}
