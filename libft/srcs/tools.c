/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avo <avo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 13:54:53 by oespion           #+#    #+#             */
/*   Updated: 2018/07/24 13:03:23 by avo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

const char	*end_of_int(const char *str)
{
	str++;
	while (*str >= '0' && *str <= '9')
		str++;
	return (str);
}

int			uintmax_t_len(uintmax_t nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

int			longlong_len(intmax_t nb)
{
	int	i;

	i = 0;
	if (nb < -9223372036854775807)
		return (20);
	if (nb < 0)
	{
		i++;
		nb *= -1;
	}
	else if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

t_printf	*create_struct(void)
{
	t_printf	*p;

	if (!(p = (t_printf*)malloc(sizeof(t_printf))))
		exit(-1);
	p->brett = 0;
	p->nbout = 0;
	p->precision = -1;
	p->width = -1;
	p->increment = 0;
	p->negative = 0;
	p->zeros = 0;
	p->blank = 0;
	p->positive = 0;
	p->sharp = 0;
	p->h = 0;
	p->neg = 0;
	p->hh = 0;
	p->l = 0;
	p->ll = 0;
	p->j = 0;
	p->z = 0;
	return (p);
}

t_printf	*reset_struct(t_printf *p)
{
	p->precision = -1;
	p->width = -1;
	p->negative = 0;
	p->zeros = 0;
	p->blank = 0;
	p->neg = 0;
	p->increment = 0;
	p->positive = 0;
	p->sharp = 0;
	p->h = 0;
	p->hh = 0;
	p->l = 0;
	p->ll = 0;
	p->j = 0;
	p->z = 0;
	return (p);
}
