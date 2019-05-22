/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_get_reponse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 09:52:14 by ratin             #+#    #+#             */
/*   Updated: 2019/05/22 20:28:36 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

void			ft_print_words_tables(char **tab)
{
	int			i;
	int			y;

	i = 0;
	y = 0;
	while (tab[i] != '\0')
	{
		while (tab[i][y] != '\0')
		{
			ft_putchar(tab[i][y]);
			y++;
		}
		y = 0;
		i++;
		ft_putchar('\n');
	}
}

t_reponse		*create_reponse(char *str)
{
	t_reponse	*new_reponse;

	if (!(new_reponse = malloc(sizeof(*new_reponse))))
		return (0);
	new_reponse->step = ft_strsplit(str, ' ');
	new_reponse->next = NULL;
	return (new_reponse);
}

int				add_reponse(t_visu *visu, char *str)
{
	t_reponse	*last;
	t_reponse	*new_reponse;

	last = visu->reponse;
	if (!(new_reponse = create_reponse(str)))
		quit_visu(visu->party);
	if (visu->reponse == NULL)
		visu->reponse = new_reponse;
	else
	{
		while (last->next)
			last = last->next;
		last->next = new_reponse;
	}
	return (1);
}
