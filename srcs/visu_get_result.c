/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_get_result.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 19:09:09 by ratin             #+#    #+#             */
/*   Updated: 2019/05/22 22:53:46 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

void		free_double(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void			read_result(t_visu *visu)
{
	char		*str;
	int			turn;

	turn = 0;
	while (get_next_line(0, &str) == 1)
	{
		parse(visu, str, &turn);
		if (str)
			free(str);
		turn++;
	}
	str ? free(str) : 0;
}

int				count_step(t_visu *visu)
{
	t_reponse	*last;
	int			i;

	last = visu->reponse;
	i = 0;
	while (last)
	{
		i++;
		last = last->next;
	}
	return (i);
}

void			quit_parsing(t_party *party)
{
	free_prog(party->visu, party);
	ft_printf("Error on visu's parsing\n");
	exit(1);
}

int				get_result(t_visu *visu)
{
	read_result(visu);
	visu->nbr_of_step = count_step(visu);
	return (1);
}
