/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 18:55:52 by oespion           #+#    #+#             */
/*   Updated: 2019/05/23 01:52:48 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

void		parse_reponse_finished(t_visu **visu, char **str)
{
	if ((*visu)->tube_finished == 0)
	{
		if ((*str)[0] != '#' && ft_strstr(*str, "-") == NULL
				&& ft_strcmp(*str, "") != 0)
			quit_parsing((*visu)->party);
		if (ft_strcmp(*str, "") == 0)
			(*visu)->tube_finished = 1;
		else
		{
			if ((*str)[0] != '#' && false_room(*visu, *str))
				quit_parsing((*visu)->party);
			get_link(*visu, *str);
		}
	}
	else if ((*str)[0] == 'L' && (*visu)->reponse_finished == 0)
	{
		if (ft_strcmp(*str, "") == 0)
			(*visu)->reponse_finished = 1;
		else
		{
			if ((*str)[0] != '#' && false_reponse(*visu, *str))
				quit_parsing((*visu)->party);
			add_reponse(*visu, *str);
		}
	}
}

void		get_nbr_ant(t_visu *visu, char *str)
{
	visu->nbr_of_ants = ft_atoi(str);
	if (visu->nbr_of_ants <= 0)
		quit_parsing(visu->party);
	if (ft_strlen(str) > 13 || ft_atoi(str) > 2147483647
		|| ft_atoi(str) < -2147483648
		|| ((ft_atoi(str) == 0 && str[0] != '0')))
		quit_parsing(visu->party);
}

void		parse(t_visu *visu, char *str, int *turn)
{
	if (ft_strstr(str, "ERROR") != NULL || ft_strstr(str, "error") != NULL)
		quit_parsing(visu->party);
	if (visu->map_finished == 0)
	{
		if (*turn == 0 && str[0] == '#')
		{
			(*turn)--;
			return ;
		}
		if ((*turn) == 0)
			get_nbr_ant(visu, str);
		else if (ft_strchr(str, '-') != NULL && str[0] != '#')
		{
			visu->map_finished = 1;
			if (false_room(visu, str))
				quit_parsing(visu->party);
			get_link(visu, str);
		}
		else
			fill_map(visu, str);
	}
	else
		parse_reponse_finished(&visu, &str);
}
