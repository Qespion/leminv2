/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comb_grp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avo <avo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 14:10:06 by avo               #+#    #+#             */
/*   Updated: 2019/03/11 18:24:56 by avo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

void	ft_print_line(int *line, int len)
{
	int r = 0;
	while (r <= len)
	{
		ft_printf("%d - ", line[r++]);
	}
	ft_printf("\n");
}

int     *set_zero(int *roads, int len)
{
	int r;

	r = 0;
	while (r <= len)
	{
		roads[r] = 0;
		r++;
	}
	return (roads);
}

int		*copy_tmp_line(int *tmp_line, int len)
{
	int	*try_line;
	int	r;

	r = 0;
	while (r <= len)
		try_line[r] = tmp_line[r++];
	return (try_line);
}

int		ft_interfere(int **tab, int index, int i, int *try_line, int len)
{
	int	r;
	int	j;
	r = 0;
	while (r < len)
	{
		if (tab[index][r] != 0 && tab[i][r] == 0)
			return (0);
		r++;
	}
	return (1);
}

int		find_lowest(int *try_line, int len)
{
	int		lowest;
	int		solution;
	int		r;

	r = 0;
	lowest = 0;
	while (r < len)
	{
		if (lowest == 0 && try_line[r] != 0)
		{
			solution = r;
			lowest = try_line[r];
		}
		else if (try_line[r] != 0 && lowest > try_line[r])
		{
			solution = r;
			lowest = try_line[r];
		}
		r++;
	}
	return (solution);
}

int		ft_turn_solution(int *try_line, int len, int max_roads, int ants)
{
	int	road_nb;
	int	r;
	int	turn;
	int	lowest;

	turn = 0;
	r = 0;
	road_nb = 0;
	while (r < len)
	{
		if (try_line[r] != 0)
			road_nb++;
		r++;
	}
	while (ants > 0)
	{
		lowest = find_lowest(try_line, len);
		try_line[lowest]++;
		ants--;
	}
	// ft_print_line(try_line, len);
	return (try_line[find_lowest(try_line,len)]);
}

int		*ft_try_nb(int len, int r, int index, int **tab, int max_roads, int ants)
{
	int	*try_line;
	int	i;

	i = 0;
	if (!(try_line = (int*)malloc(sizeof(int) * (len + 1))))
		exit(-1);
	try_line = set_zero(try_line, len);
	// ft_printf("index %d\n", index);
	// ft_printf("r %d\n", r);
	try_line[index] = tab[index][index];
	try_line[r] = tab[index][r];
	while (i <  len)
	{
		if (tab[index][i] != 0 && ft_interfere(tab, index, i, try_line, len))
			try_line[i] = tab[index][i];
		i++;
	}
	try_line[i] = ft_turn_solution(try_line, len, max_roads, ants);
	// ft_print_line(try_line, len);
	return (try_line);
}

int		*try_line(int **tab, int len, int *line, int index, int max_roads, int ants)
{
	int	r;
	r = 0;
	int	*best;

	best = line;
	while (r < len)
	{
		if (r == index)
		{
			r++;
			continue;
		}
		if (tab[index][r] != 0)
			line = ft_try_nb(len, r, index, tab, max_roads, ants);
		if (!best || line[len] < best[len])
			best = line;
		r++;
	}
	// ft_print_line(best, len);
	return (best);
}

int    *bt_grp(int **tab, int len, int max_roads, int ants)
{
	int *line;
	int r;

	r = 0;
	line = NULL;
	while (r < len)
	{
		line = try_line(tab, len, line, r, max_roads, ants);
		r++;
	}
	ft_printf("number of turn == %d\n", line[len]);
	return (line);
}
