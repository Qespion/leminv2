/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_map_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 00:11:31 by ratin             #+#    #+#             */
/*   Updated: 2019/05/23 01:49:24 by ratin            ###   ########.fr       */
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

int			false_name(t_visu *visu, char **line, int y)
{
	int		i;
	int		len;
	char	*name;
	t_room	*room;

	i = 0;
	len = 0;
	while (line[y][i] != '-' && line[y][i])
		i++;
	if (!line[y][i])
		return (1);
	while (line[y][i + len] != ' ' && line[y][len])
		len++;
	name = ft_strsub(line[y], ++i, --len);
	if (!(room = get_room_by_name(visu, name)))
		return (1);
	free(name);
	return (0);
}

int			false_reponse(t_visu *visu, char *str)
{
	int		y;
	char	**line;

	y = 0;
	line = ft_strsplit(str, ' ');
	while (line[y])
	{
		if (false_name(visu, line, y))
			return (1);
		y++;
	}
	free_double(line);
	return (0);
}

void		check_mp_inpt(t_visu *visu, char *str)
{
	int		i;

	i = 0;
	if (str[0] == '#')
		return ;
	while (str[i] != ' ' && str[i])
		i++;
	if (!str[i])
		quit_parsing(visu->party);
	while (str[++i] != ' ' && str[i])
	{
		if (str[i] < 48 && str[i] > 57)
			quit_parsing(visu->party);
	}
	if (!str[i])
		quit_parsing(visu->party);
	while (str[++i] != ' ' && str[i])
	{
		if (str[i] < 48 && str[i] > 57)
			quit_parsing(visu->party);
	}
}
