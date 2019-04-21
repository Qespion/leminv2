/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 20:55:03 by oespion           #+#    #+#             */
/*   Updated: 2019/04/21 21:06:33 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

void	print_pack(t_pack *player)
{
	while (player)
	{
		ft_printf("player => L%d\n", player->player->bib_nb);
		player = player->nxt;
	}
}

int		*create_base(int len)
{
	int	*tmp;
	int	r;

	r = 0;
	if (!(tmp = (int*)malloc(sizeof(int) * (len + 1))))
		exit(1);
	while (r <= len)
	{
		tmp[r] = 0;
		r++;
	}
	return (tmp);
}

void	send_player(t_pack **start, t_pack **np, t_pack **lt, t_journey **play)
{
	if (!(*start))
	{
		if (!(*start = (t_pack*)malloc(sizeof(t_pack))))
			exit(-1);
		(*start)->player = *play;
		(*start)->nxt = NULL;
	}
	else
	{
		if (!(*np = (t_pack*)malloc(sizeof(t_pack))))
			exit(-1);
		*lt = *start;
		while ((*lt)->nxt)
			*lt = (*lt)->nxt;
		(*lt)->nxt = *np;
		(*np)->nxt = NULL;
		(*np)->player = *play;
	}
}

int		check_end(t_pack *the_pack)
{
	while (the_pack)
	{
		if (the_pack->player->node != the_pack->player->wroad->path->current)
			return (1);
		the_pack = the_pack->nxt;
	}
	return (0);
}

t_pack	*remove_from_field(t_pack *start, t_pack *rm)
{
	t_pack	*tmp;

	if (start == rm)
		start = start->nxt;
	else
	{
		tmp = start;
		while (tmp->nxt != rm)
			tmp = tmp->nxt;
		tmp->nxt = tmp->nxt->nxt;
	}
	if (rm->player)
	{
		free(rm->player);
		rm->player = NULL;
	}
	if (rm)
	{
		free(rm);
		rm = NULL;
	}
	return (start);
}
