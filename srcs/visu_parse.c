/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 18:55:52 by oespion           #+#    #+#             */
/*   Updated: 2019/05/20 18:56:22 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

void		parse_reponse_finished(t_visu **visu, char **str)
{
	if ((*visu)->tube_finished == 0)
	{
		if (ft_strcmp(*str, "") == 0)
			(*visu)->tube_finished = 1;
		else
			get_link(*visu, *str);
	}
	else if ((*str)[0] == 'L' && (*visu)->reponse_finished == 0)
	{
		if (ft_strcmp(*str, "") == 0)
			(*visu)->reponse_finished = 1;
		else
			add_reponse(*visu, *str);
	}
}

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
	else
		parse_reponse_finished(&visu, &str);
}