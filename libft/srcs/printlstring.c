/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printlstring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 15:33:10 by oespion           #+#    #+#             */
/*   Updated: 2018/06/05 10:16:49 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		calc_len(t_printf *p, int nb, int output)
{
	int	len;

	if (p->precision == -1)
		return (1);
	nb < 128 ? len = 1 : 0;
	nb >= 128 && nb < 2048 ? len = 2 : 0;
	nb >= 2048 && nb < 65536 ? len = 3 : 0;
	nb >= 65536 ? len = 4 : 0;
	MB_CUR_MAX == 1 ? len = 1 : 0;
	if (len + output <= p->precision)
		return (1);
	return (0);
}

int		calc_global_len_without_mb(int total, wchar_t *brett_tab)
{
	int	r;

	r = 0;
	if (MB_CUR_MAX == 1)
	{
		total = 0;
		r = 0;
		while (brett_tab[r++])
			total++;
	}
	return (total);
}

int		calc_global_len(t_printf *p, wchar_t *brett_tab)
{
	int	r;
	int	total;

	total = 0;
	r = 0;
	while (brett_tab[r] && p->precision == -1)
	{
		brett_tab[r] < 128 ? total += 1 : 0;
		brett_tab[r] >= 128 && brett_tab[r] < 2048 ? total += 2 : 0;
		brett_tab[r] >= 2048 && brett_tab[r] < 65536 ? total += 3 : 0;
		brett_tab[r] >= 65536 ? total += 4 : 0;
		r++;
	}
	while (brett_tab[r] && p->precision != -1)
	{
		brett_tab[r] < 128 && total + 1 <= p->precision ? total += 1 : 0;
		brett_tab[r] >= 128 && brett_tab[r] < 2048
			&& total + 2 <= p->precision ? total += 2 : 0;
		brett_tab[r] >= 2048 && brett_tab[r] < 65536
			&& total + 3 <= p->precision ? total += 3 : 0;
		brett_tab[r] >= 65536 && total + 4 <= p->precision ? total += 4 : 0;
		r++;
	}
	total = calc_global_len_without_mb(total, brett_tab);
	return (total);
}

void	print_width_c(t_printf *p, int r, wchar_t *brett_tab, int output)
{
	while (brett_tab[r])
	{
		if (calc_len(p, brett_tab[r], output) == 0)
			break ;
		output += ft_printf("%C", brett_tab[r++]);
	}
	p->nbout += output;
	p->negative ? print_uni_width(p, calc_global_len(p, brett_tab)) : 0;
}

void	printlstring(t_printf *p)
{
	wchar_t *brett_tab;
	int		r;
	int		output;

	output = 0;
	brett_tab = va_arg(p->ap, wchar_t*);
	if (!brett_tab)
	{
		ft_putstrn(p, "(null)");
		return ;
	}
	r = 0;
	if (check_brett_tab(brett_tab, p) == 0)
	{
		p->brett = -1;
		return ;
	}
	!p->negative ? print_uni_width(p, calc_global_len(p, brett_tab)) : 0;
	print_width_c(p, r, brett_tab, output);
}
