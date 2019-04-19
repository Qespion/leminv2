/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comb_grp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 13:17:46 by oespion           #+#    #+#             */
/*   Updated: 2019/04/19 14:32:29 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

void	ft_print_line(int *line, int len)
{
	int r;

	r = 0;
	while (r <= len - 1)
	{
		ft_printf("%d - ", line[r++]);
	}
	ft_printf("turn: %d\n", line[r]);
}

int		*set_zero(int *roads, int len, int **tab, int r)
{
	int rr;

	rr = 0;
	while (rr <= len)
	{
		roads[rr] = rr == r ? tab[r][r] : 0;
		rr++;
	}
	return (roads);
}

int		*create_malloc_line(int *line, int len)
{
	int	*sol;
	int	r;

	r = 0;
	if (!(sol = (int*)malloc((len + 1) * sizeof(int))))
		exit(-1);
	while (r <= len)
	{
		sol[r] = line[r];
		r++;
	}
	return (sol);
}

int		*copy_tmp_line(int *try_line, int *tmp_line, int len)
{
	int	r;

	r = 0;
	while (r < len)
	{
		try_line[r] = tmp_line[r];
		r++;
	}
	return (try_line);
}

int		*ft_solution(int *try, int len, int **tab, int r)
{
	int *solution;

	(void)try;
	if (!(solution = (int*)malloc(sizeof(int) * (len + 1))))
		exit(-1);
	solution = set_zero(solution, len, tab, r);
	return (solution);
}

int		check_lines(int *l_one, int *l_two, int len)
{
	int	r;

	r = 0;
	while (r < len - 1)
	{
		if (l_one[r] != 0 && l_two[r] == 0)
			return (0);
		r++;
	}
	return (1);
}

int		calc_nb_road(int *line, int len)
{
	int nb;
	int	r;

	r = 0;
	nb = 0;
	while (r < len - 1)
	{
		if (line[r] != 0)
			nb++;
		r++;
	}
	return (nb);
}

int		calc_nb_turn(int *line, int ants, int len)
{
	int	find_biggest;
	int	r;
	int diff;

	diff = 0;
	r = 0;
	find_biggest = 0;
	while (r < len - 1)
	{
		if (line[r] > find_biggest)
			find_biggest = line[r];
		r++;
	}
	r = 0;
	while (r < len - 1)
	{
		if (line[r] != 0)
			diff += find_biggest - line[r];
		r++;
	}
	ants -= diff;
	return ((ants / calc_nb_road(line, len)) + find_biggest);
}

int		*try_option(int **tab, int len, int *cpy_line, int *util)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (tab[util[1]][i] != 0)
		{
			if (check_lines(cpy_line, tab[i], len))
				cpy_line[i] = tab[util[1]][i];
		}
		i++;
	}
	cpy_line[len] = calc_nb_turn(cpy_line, util[0], len);
	if (g_flags & ROADGESTION)
		ft_print_line(cpy_line, len);
	return (cpy_line);
}

void	group_check_line(int **sol, int len, int **tmp)
{
	if ((*sol)[len] == 0 || ((*sol)[len] != 0 && (*tmp)[len] < (*sol)[len]))
	{
		free((*sol));
		(*sol) = (*tmp);
	}
	else
		free((*tmp));
}

int		*find_group(int *solution, int len, int **tab, int *util)
{
	int	i;
	int	*cpy_line;
	int	*tmp;

	i = 0;
	cpy_line = create_malloc_line(solution, len);
	while (i < len - 1)
	{
		if (tab[util[1]][i] != 0 && check_lines(cpy_line, tab[i], len))
		{
			tmp = create_malloc_line(cpy_line, len);
			tmp[i] = tab[i][i];
			tmp = try_option(tab, len, tmp, util);
			cpy_line[i] = 0;
			group_check_line(&solution, len, &tmp);
		}
		i++;
	}
	free(cpy_line);
	return (solution);
}

int		*try_line(int r, int len, int ants, int **tab)
{
	int *try;
	int	*solution;
	int util[2];

	if (!(try = (int*)malloc(sizeof(int) * (len + 1))))
		exit(-1);
	try = copy_tmp_line(try, tab[r], len);
	solution = ft_solution(try, len, tab, r);
	util[0] = ants;
	util[1] = r;
	solution = find_group(solution, len, tab, util);
	free(try);
	return (solution);
}

int		*bt_grp(int **tab, int len, int ants)
{
	int r;
	int *line;
	int	*sol;

	line = NULL;
	r = 0;
	if (len == 1)
		return (create_malloc_line(tab[0], len - 1));
	while (r < len)
	{
		sol = try_line(r, len, ants, tab);
		if (!line)
			line = sol;
		else if (line[len] > sol[len] && sol[len] != 0)
		{
			free(line);
			line = create_malloc_line(sol, len);
			free(sol);
		}
		else
			free(sol);
		r++;
	}
	return (line);
}
