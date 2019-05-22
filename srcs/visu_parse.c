/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 18:55:52 by oespion           #+#    #+#             */
/*   Updated: 2019/05/22 19:26:38 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

int			false_room(t_visu *visu, char *str)
{
	int		i;
	int		len;
	char	*name;
	t_room	*room;

	i = 0;
	len = 0;
	while (str[i] != '-' && str[i])
		i++;
	name = ft_strsub(str, 0, i);
	if (!(room = get_room_by_name(visu, name)))
		return (1);
	free(name);
	while (str[i + len] != ' ' && str[len])
		len++;
	name = ft_strsub(str, ++i, --len);
	if (!(room = get_room_by_name(visu, name)))
		return (1);
	free(name);
	return (0);
}

void		parse_reponse_finished(t_visu **visu, char **str)
{
	if ((*visu)->tube_finished == 0)
	{
		if (ft_strstr(*str, "road not found") != NULL)
			quit_parsing((*visu)->party);
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
			visu->nbr_of_ants = ft_atoi(str);
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
