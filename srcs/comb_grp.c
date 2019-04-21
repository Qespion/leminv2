/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comb_grp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 13:17:46 by oespion           #+#    #+#             */
/*   Updated: 2019/04/21 15:59:52 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

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
