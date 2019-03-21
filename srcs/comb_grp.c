/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comb_grp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 13:17:46 by oespion           #+#    #+#             */
/*   Updated: 2019/03/21 10:17:38 by oespion          ###   ########.fr       */
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

int     *set_zero(int *roads, int len, int **tab, int r)
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

int     *ft_solution(int *try, int len, int **tab, int r)
{
    int *solution;

	if (!(solution = (int*)malloc(sizeof(int) * (len + 1))))
        exit(-1);
    solution = set_zero(solution, len, tab, r);
    ft_print_line(solution, len);
	return (solution);
}

int     *try_line(int r, int max_roads, int len, int ants, int **tab)
{
    int *try;
    int *best;
	int	*solution;

    if (!(try = (int*)malloc(sizeof(int) * (len + 1))))
        exit(-1);
    try = copy_tmp_line(try, tab[r], len);
	solution = ft_solution(try, len, tab, r);
	free(try);
    return (solution);
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

void    bt_grp(int **tab, int len, int max_roads, int ants)
{
	int r;
    int *line;
	int	*sol;
    line = NULL;
    r = 0;
    // if (max_roads == 1)
    // {
    //     // print first elem of tab
    //     exit(1);
    // }
    while (r < len)
    {
		sol = try_line(r, max_roads, len, ants,  tab);
        if (!line)
            line = sol;
        else if (line[len] > sol[len])
        {
			free(line);
			line = create_malloc_line(sol, len);
			free(sol);
		}
		else
			free(sol);
		ft_print_line(line, len);
        r++;
    }
	if (line)
		free(line);
}
