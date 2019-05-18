/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_get_result.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 19:09:09 by ratin             #+#    #+#             */
/*   Updated: 2019/05/19 01:09:50 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

void		parse(t_visu *visu, char *str, int *turn)
{
	if (visu->map_finished == 0)
	{
		if (*turn == 0 && str[0] == '#')
		{
			(*turn)--;
			return ;
		}
		if ((*turn) == 0)
			visu->nbr_of_ants = ft_atoi(str);
		else if (ft_strchr(str, '-') != NULL && str[0] != '#')
		{
			visu->map_finished = 1;
			get_link(visu, str);
		}
		else
			fill_map(visu, str);
	}
	else if (visu->tube_finished == 0)
	{
		if (ft_strcmp(str, "") == 0)
			visu->tube_finished = 1;
		else
			get_link(visu, str);
	}
	else if (str[0] == 'L' && visu->reponse_finished == 0)
	{
		if (ft_strcmp(str, "") == 0)
			visu->reponse_finished = 1;
		else
			add_reponse(visu, str);
	}
}

static char	*read_result(t_visu *visu)
{
	char	*str;
	char	*result;
	int		turn;

	turn = 0;
	if (!(result = (char *)malloc(sizeof(char))))
		exit (1);
	while (1)
	{
		if (get_next_line(0, &str) != 1)
		{
			free(result);
			exit (1);
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
	if (str)
		free(str);
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

void		print_reponse(t_visu *visu)
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

int			get_result(t_visu *visu)
{
	char 	*result;

	result = read_result(visu);
	visu->nbr_of_step = count_step(visu);
	ft_printf("%s", result);
	//print_reponse(visu);
	free(result);
	return (1);
}
