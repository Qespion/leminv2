/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_grp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 12:58:48 by oespion           #+#    #+#             */
/*   Updated: 2019/03/25 16:21:37 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

int		ft_wroad_len(t_wroad *wroad)
{
	int nb;

	nb = 0;
	while (wroad)
	{
		wroad = wroad->next;
		nb++;
	}
	return nb;
}

int		*init_tab(int *tab, int len)
{
	int	r;

	r = 0;
	while (r < len)
	{
		tab[r] = 0;
		r++;
	}
	return (tab);
}

int		ft_check_conflict(t_conflict *current, int r)
{
	while (current)
	{
		if (current->conflict == r)
			return (0);
		current = current->next;
	}
	return (1);
}

int		ft_get_len(int	r, t_wroad *wroad)
{
	while (r != wroad->nb)
		wroad = wroad->next;
	return (wroad->len);
}

int		*ft_get_turn(t_wroad *wroad, t_wroad *current, t_map *map, int len)
{
	int	*tab;
	int	r;

	(void)map;
	if (!(tab = (int*)malloc(sizeof(int) * len)))
		exit (-1);
	tab = init_tab(tab, len);
	r = 0;
	while (r < len)
	{
		if (ft_check_conflict(current->conflict , r))
			tab[r] = ft_get_len(r, wroad);
		r++; 
	}
	return (tab);
}

int		**ft_create_tab(t_wroad *wroad, t_map *map, int len)
{
	int			**tab;
	int			err;
	t_wroad	*current;

	current = wroad;
	err = 0;
	if (!(tab = (int**)malloc(sizeof(int*) * (len + 1))))
		exit(-1);
	while (err < len)
	{
		tab[err] =ft_get_turn(wroad, current, map, len);
		err++; 
		current = current->next;
	}
	return (tab);
}

void	ft_print_tab(int **tab, int len)
{
	int	r;
	int	err;

	err = 0;
	r = 0;
	while (r < len - 1)
	{
		while (err < len)
		{
			ft_printf(" %d ", tab[r][err]);
			err++;
		}
		ft_putchar('\n');
		err = 0;
		r++;
	}
	// ft_printf("-> %d\n", tab[len - 1][len -1]);
}

void	tab_free(int **tab)
{
	int	r;

	r = 0;
	if (!tab)
		return ;
	while (tab[r])
	{
		free(tab[r]);
		r++;
	}
	free(tab);
}

void    ft_create_group(t_wroad *wroad, t_map *map, int max_roads)
{
	int						len;
	int						**tab;
	int						*line;

	len = ft_wroad_len(wroad);
	// ft_printf("len = %d\n", len);
	tab =  ft_create_tab(wroad, map, len);
	// ft_print_tab(tab, len);
	// ft_print_line(tab[0], len - 1);
	line = bt_grp(tab,len, map->nb);
	get_best_road(line, map->nb, max_roads, wroad);
	free(line);
	tab_free(tab);
}
