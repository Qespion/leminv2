/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_comb_grp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 13:13:20 by oespion           #+#    #+#             */
/*   Updated: 2019/04/21 15:53:55 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

int		check_lines(int *l_one, int *l_two, int len)
{
	int	r;

	r = 0;
	while (r < len)
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
	while (r < len)
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
	while (r < len)
	{
		if (line[r] > find_biggest)
			find_biggest = line[r];
		r++;
	}
	r = 0;
	while (r < len)
	{
		if (line[r] != 0)
			diff += find_biggest - line[r];
		r++;
	}
	ants -= diff;
	return ((ants / calc_nb_road(line, len)) + find_biggest);
}
