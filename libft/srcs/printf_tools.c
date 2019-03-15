/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 13:02:07 by oespion           #+#    #+#             */
/*   Updated: 2018/06/05 10:16:47 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const char	*ft_flags(const char *format, t_printf *p)
{
	if (*format == '-')
		p->negative = 1;
	else if (*format == '+')
		p->positive = 1;
	else if (*format == '0')
		p->zeros = 1;
	else if (*format == ' ')
		p->blank = 1;
	else if (*format == '#')
		p->sharp = 1;
	if (*format == '#' || *format == ' ' || *format == '+' || *format == '-'
			|| *format == '0')
		format++;
	if (*format == '#' || *format == ' ' || *format == '+' || *format == '-'
			|| *format == '0')
		return (ft_flags(format, p));
	return (format);
}

const char	*ft_width(const char *format, t_printf *p)
{
	while ((*format >= '0' && *format <= '9') || *format == '*')
	{
		if (*format >= '0' && *format <= '9')
		{
			p->width = ft_atoi(format);
			format = end_of_int(format);
		}
		if (*format == '*')
		{
			p->width = va_arg(p->ap, int);
			if (p->width < 0)
			{
				p->negative = 1;
				p->width = ft_abs(p->width);
			}
			format++;
		}
	}
	return (format);
}

const char	*parse_precision(const char *format, t_printf *p)
{
	while ((*format >= '0' && *format <= '9') || *format == '*')
	{
		if (*format >= '0' && *format <= '9')
		{
			p->precision = ft_atoi(format);
			format = end_of_int(format);
		}
		if (*format == '*')
		{
			p->precision = va_arg(p->ap, int);
			p->precision < 0 ? p->precision = -1 : 0;
			format++;
		}
	}
	return (format);
}

const char	*ft_precision(const char *format, t_printf *p)
{
	if (*format == '.')
	{
		p->precision = 0;
		format++;
		if (*format == '-')
		{
			format++;
			p->negative = 1;
			format = ft_width(format, p);
		}
		format = parse_precision(format, p);
	}
	return (format);
}
