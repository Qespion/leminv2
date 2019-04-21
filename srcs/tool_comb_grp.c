/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_comb_grp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 13:11:30 by oespion           #+#    #+#             */
/*   Updated: 2019/04/21 13:12:28 by oespion          ###   ########.fr       */
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
