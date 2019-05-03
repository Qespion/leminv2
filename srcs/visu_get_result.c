/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_get_result.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 19:09:09 by ratin             #+#    #+#             */
/*   Updated: 2019/05/03 02:08:52 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

void		parse(t_visu *visu, char *str, int turn)
{
	if (visu->map_finished == 0)
	{
		if (turn == 0)
			visu->ant_nbr = ft_atoi(str);
		else if (ft_strchr(str, '-') != NULL)
			visu->map_finished = 1;
		else
			fill_map(visu, str);
	}
}

static char	*read_result(t_visu *visu)
{
	char	*str;
	char	*result;
	int		turn;

	turn = 0;
	if (!(result = (char *)malloc(sizeof(char))))
		return (0);
	while (1)
	{
		if (get_next_line(0, &str) == -1)
		{
			free(result);
			return (0);
		}
		result = ft_strfjoin(result, str);
		result = ft_strfjoin(result, "\n");
		//ft_printf("strstr donne %d pour |%s|\n", ft_strchr(str, '-'), str);
		parse(visu, str, turn);
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

int			get_result(t_visu *visu)
{
	char 	*result;

	result = read_result(visu);
	ft_printf("%s", result);
	print_rooms(visu);
	visu->result = result;
	return (1);
}
