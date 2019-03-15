/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 11:52:36 by oespion           #+#    #+#             */
/*   Updated: 2018/07/15 12:04:27 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const char	*ft_lenght_mod(const char *format, t_printf *p)
{
	if (*format == 'h' && format[1] == 'h')
		p->hh = 1;
	else if (*format == 'l' && format[1] == 'l')
		p->ll = 1;
	else if (*format == 'h')
		p->h = 1;
	else if (*format == 'l')
		p->l = 1;
	else if (*format == 'j')
		p->j = 1;
	else if (*format == 'z')
		p->z = 1;
	while (*format == 'h' || *format == 'j' || *format == 'l'
			|| *format == 'z')
		format++;
	ft_get_arg(*format, p);
	return (format);
}

int			checkafter(const char *f, t_printf *p)
{
	int	r;
	int	l;

	l = 0;
	r = 0;
	while (f[r] != '%' && f[r])
		r++;
	if (f[r] == '%')
	{
		r++;
		while (f[r] != 's' && f[r] != 'd' && f[r] != 'c' && f[r] != 'b'
		&& f[r] != 'i' && f[r] != 'X' && f[r] != 'o' && f[r] != 'O'
		&& f[r] != 'U' && f[r] != '%' && f[r] != 'p' && f[r] != 'C'
		&& f[r] && f[r] != 'x' && f[r] != 'u' && f[r] != 'D' && f[r] != 'S')
		{
			f[r] == 'l' && f[r + 1] != 'l'
				&& f[r - 1] != 'l' ? l = 1 : 0;
			r++;
		}
		if (f[r] == 'C' || (f[r] == 'c' && l == 1))
			if (checkunicode(p))
				return (0);
	}
	return (1);
}

void		parce_percent(t_printf *p, const char *format)
{
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			format = ft_flags(format, p);
			format = ft_width(format, p);
			format = ft_precision(format, p);
			format = ft_lenght_mod(format, p);
		}
		p->increment ? format++ : 0;
		if (checkafter(format, p) == 1)
		{
			while (*format != '\0' && *format != '%' && p->brett != -1)
			{
				p->nbout++;
				ft_putchar((char)*format);
				format++;
			}
		}
		if (p->brett == -1)
			break ;
		p = reset_struct(p);
	}
}

int			ft_printf(const char *format, ...)
{
	t_printf	*p;
	int			outnbr;

	p = create_struct();
	va_start(p->ap, format);
	if (!format)
		return (0);
	parce_percent(p, format);
	va_end(p->ap);
	outnbr = (p->brett == -1 ? -1 : p->nbout);
	free(p);
	return (outnbr);
}
