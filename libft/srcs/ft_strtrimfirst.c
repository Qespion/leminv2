/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimfirst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 19:12:07 by oespion           #+#    #+#             */
/*   Updated: 2018/08/28 19:34:36 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strtrimfirst(char const *s)
{
    char    *str;
    int     len;
    int     r;

    r = 0;
    len = 0;
    while (s[len] != ' ' && s[len] != '\0')
        len++;
    if(!(str = (char*)malloc(sizeof(char) * (len))))
        exit(-1);
    while (r < len)
    {
        str[r] = s[r];
        r++;
    }
    str[r] = '\0';
    return (str);
}