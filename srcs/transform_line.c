/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 20:52:05 by oespion           #+#    #+#             */
/*   Updated: 2019/04/21 21:13:51 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

void	add_ants_line(int **line, int **tmp, int *ants, int r)
{
	(*ants)--;
	(*line)[r]++;
	(*tmp)[r]++;
}

// FACKING FUNCTION TO NORMALIEZ
//FUYCK

int		*transform_line(int *line, int ants, int len)
{
	int	*tmp;
	int util[2];

	tmp = create_base(len);
	while (ants)
	{
		util[0] = 0;
		while (line[util[0]] == 0)
			util[0]++;
		util[1] = util[0] + 1;
		while (util[1] < len && line[util[1]] == 0)
			util[1]++;
		if (util[1] == len || line[util[0]] < line[util[1]])
		{
			add_ants_line(&line, &tmp, &ants, util[0]);
			if (!ants)
				return (tmp);
		}
		while (line[util[0]] >= line[util[1]])
		{
			util[0]++;
			while (util[0] < len && line[util[0]] == 0)
				util[0]++;
			if (util[0] == len)
			{
				util[0]--;
				while (line[util[0]] == 0)
					util[0]--;
				add_ants_line(&line, &tmp, &ants, util[0]);
				break ;
			}
			util[1] = util[0] + 1;
			while (util[1] < len && line[util[1]] == 0)
				util[1]++;
			if (util[1] == len)
			{
				add_ants_line(&line, &tmp, &ants, util[0]);
				break ;
			}
			else if (line[util[0]] < line[util[1]])
			{
				add_ants_line(&line, &tmp, &ants, util[0]);
				break ;
			}
		}
	}
	return (tmp);
}
