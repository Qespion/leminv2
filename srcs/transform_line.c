/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 20:52:05 by oespion           #+#    #+#             */
/*   Updated: 2019/04/23 11:24:22 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

void	util_move(int *util, int *util_one, int **line, int len)
{
	*util = 0;
	while ((*line)[*util] == 0)
		(*util)++;
	*util_one = *util + 1;
	while (*util_one < len && (*line)[*util_one] == 0)
		(*util_one)++;
}

int		break_loop_line(int ****lists, int ***util, int **ants, int len)
{
	while ((**util)[1] < len && (**lists)[0][(**util)[1]] == 0)
		(**util)[1]++;
	if ((**util)[1] == len)
	{
		(**ants)--;
		(**lists)[0][(**util)[0]]++;
		(**lists)[1][(**util)[0]]++;
		return (1);
	}
	else if ((**lists)[0][(**util)[0]] < (**lists)[0][(**util)[1]])
	{
		(**ants)--;
		(**lists)[0][(**util)[0]]++;
		(**lists)[1][(**util)[0]]++;
		return (1);
	}
}

void	loop_transform_line(int ***lists, int **util, int *ants, int len)
{
	while ((*lists)[0][(*util)[0]] >= (*lists)[0][(*util)[1]])
	{
		(*util)[0]++;
		while ((*util)[0] < len && (*lists)[0][(*util)[0]] == 0)
			(*util)[0]++;
		if ((*util)[0] == len)
		{
			(*util)[0]--;
			while ((*lists)[0][(*util)[0]] == 0)
				(*util)[0]--;
			(*ants)--;
			(*lists)[0][(*util)[0]]++;
			(*lists)[1][(*util)[0]]++;
			return ;
		}
		(*util)[1] = (*util)[0] + 1;
		if (break_loop_line(&lists, &util, &ants, len))
			return ;
	}
}

int		add_first_ant(int ***lists, int **util, int *ants, int **tmp)
{
	(*ants)--;
	(*lists)[0][(*util)[0]]++;
	(*lists)[1][(*util)[0]]++;
	if (!(*ants))
	{
		*tmp = (*lists)[1];
		free(*util);
		free(*lists);
		return (1);
	}
	return (0);
}

int		*transform_line(int *line, int ants, int len)
{
	int	*tmp;
	int *util;
	int	**lists;

	if (!(util = (int*)malloc(sizeof(int) * 2)))
		exit(-1);
	if (!(lists = (int**)malloc(sizeof(int*) * 2)))
		exit(-1);
	lists[0] = line;
	lists[1] = create_base(len);
	while (ants)
	{
		util_move(&(util[0]), &(util[1]), &lists[0], len);
		if (util[1] == len || lists[0][util[0]] < lists[0][util[1]])
		{
			if (add_first_ant(&lists, &util, &ants, &tmp))
				return (tmp);
		}
		loop_transform_line(&lists, &util, &ants, len);
	}
	tmp = lists[1];
	free(util);
	free(lists);
	return (tmp);
}
