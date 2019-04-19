/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_grp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 12:58:48 by oespion           #+#    #+#             */
/*   Updated: 2019/04/19 18:40:51 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

int		**ft_create_tab(t_wroad *wroad, t_map *map, int len)
{
	int			**tab;
	int			err;
	t_wroad		*current;

	current = wroad;
	err = 0;
	if (!(tab = (int**)malloc(sizeof(int*) * (len + 1))))
		exit(-1);
	while (err < len)
	{
		tab[err] = ft_get_turn(wroad, current, map, len);
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
	ft_printf("\n\e[32;40mGRAPH:\033[0m\n");
	while (r < len - 1)
	{
		while (err < len - 1)
		{
			ft_printf("%4d ", tab[r][err]);
			err++;
		}
		ft_putchar('\n');
		err = 0;
		r++;
	}
}

void	tab_free(int **tab, int len)
{
	int	r;

	r = 0;
	if (!tab)
		return ;
	while (r < len)
	{
		free(tab[r]);
		r++;
	}
	free(tab);
}

void	ft_create_group(t_wroad *wroad, t_map *map, int max_roads)
{
	int	len;
	int	**tab;
	int	*line;

	len = ft_wroad_len(wroad);
	tab = ft_create_tab(wroad, map, len);
	if (g_flags & GRAPH)
		ft_print_tab(tab, len);
	if (g_flags & ROADGESTION)
		ft_printf("\n\e[32;40mPOSSIBLE COMBINAISONS OF ROADS:\033[0m\n");
	line = bt_grp(tab, len, map->nb);
	get_best_road(line, map->nb, max_roads, wroad);
	free(line);
	tab_free(tab, len);
}
