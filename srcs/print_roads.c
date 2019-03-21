/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_roads.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 16:30:34 by oespion           #+#    #+#             */
/*   Updated: 2019/03/21 17:04:17 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

int     *create_base(int *line, int len)
{
    int *tmp;
    int r;

    r = 0;
    if (!(tmp = (int*)malloc(sizeof(int) * (len + 1))))
        exit(1);
    while (r <= len)
    {
        tmp[r] = 0;
        r++;
    }
    return (tmp);
}

int     *transform_line(int *line, int ants, int max_roads, int len)
{
    int     *tmp;
    int     r;
    int     biggest;
    int     diff;

    tmp = create_base(line, len);
    r = 0;
    biggest = 0;
    diff = 0;
    while (r < len)
    {
        if (line[r] > biggest)
            biggest = line[r];
        r++;
    }
    ft_printf("biggest %d\n", biggest);
    r = 0;
    while (r < len)
    {
        if (line[r] != 0)
        {
            tmp[r] = biggest - line[r];
            diff += tmp[r]; 
        }
        r++;
    }
    r = 0;
    ants -= diff;
    ft_printf("diff %d\n", diff);
    ft_print_line(tmp, len);
    return (tmp);
}

void    get_best_road(int *line, int ants, int max_roads, t_wroad *wroad)
{
    int len;

    len = ft_wroad_len(wroad);
    line = transform_line(line, ants, max_roads, len);
    free(line);
}