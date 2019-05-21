/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_get_result.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 19:09:09 by ratin             #+#    #+#             */
/*   Updated: 2019/05/21 17:44:38 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

static char		*read_result(t_visu *visu)
{
	char		*str;
	char		*result;
	int			turn;

	turn = 0;
	if (!(result = (char *)malloc(sizeof(char))))
		exit(1);
	while (1)
	{
		if (get_next_line(0, &str) != 1)
		{
			free(result);
			exit(1);
		}
		result = ft_strfjoin(result, str);
		result = ft_strfjoin(result, "\n");
		parse(visu, str, &turn);
		if (ft_strstr(str, "FINISHED") != NULL)
			break ;
		if (str)
			free(str);
		turn++;
	}
	str ? free(str) : 0;
	return (result);
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

void			print_reponse(t_visu *visu)
{
	t_reponse	*reponse;
	int			i;

	reponse = visu->reponse;
	while (reponse)
	{
		i = 0;
		printf("\nrep:	");
		while (reponse->step[i])
		{
			printf("%s ", reponse->step[i]);
			i++;
		}
		reponse = reponse->next;
	}
}

void			quit_parsing(t_party *party)
{
	free_prog(party->visu, party);
	exit(1);
}

int				get_result(t_visu *visu)
{
	char		*result;

	result = read_result(visu);
	visu->nbr_of_step = count_step(visu);
	ft_printf("%s", result);
	free(result);
	return (1);
}
