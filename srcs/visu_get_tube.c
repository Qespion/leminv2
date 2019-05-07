/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_get_tube.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 16:58:31 by ratin             #+#    #+#             */
/*   Updated: 2019/05/07 04:37:50 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

char		**get_both_name(char *str)
{
	char	**name;
	int		len1;
	int		len2;

	len1 = 0;
	len2 = 0;
	if (!(name = (char **)malloc(sizeof(char *) * 2)))
		return (0);
	while (str[len1] && str[len1] != '-')
		len1++;
	if (!(name[0] = ft_strsub(str, 0, len1)))
		return (0);
	len1++;
	while (str[len2])
		len2++;
	if (!(name[1] = ft_strsub(str, len1, len2)))
		return (NULL);
	return (name);
}

void		get_link(t_visu *visu, char *str)
{
	char	**name;
	t_room	*room;

	if (str[0] == '#')
		return ;
	name = get_both_name(str);
	room = get_room_by_name(visu, name[0]);
	add_link(visu, room, name[1]);
	room = get_room_by_name(visu, name[1]);
	add_link(visu, room, name[0]);
	free(name[0]);
	free(name[1]);
	free(name);
}
