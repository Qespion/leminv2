/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_roads.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 16:30:34 by oespion           #+#    #+#             */
/*   Updated: 2019/04/23 10:33:04 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

int g_turn = 0;
int g_ants = 1;

void	print_line_lemin(t_road **tmp, t_pack **pack, t_pack **start)
{
	ft_printf("L%d-%s", (*pack)->player->bib_nb, (*pack)->player->node->name);
	if ((*pack)->nxt)
		ft_putchar(' ');
	*tmp = (*pack)->player->wroad->path;
	if ((*tmp)->current == (*pack)->player->node)
		*start = remove_from_field(*start, *pack);
	else
	{
		while ((*tmp)->prev->current != (*pack)->player->node)
			*tmp = (*tmp)->prev;
		(*pack)->player->node = (*tmp)->current;
	}
}

t_pack	*print_player(t_pack *pack)
{
	int		nb_print;
	t_road	*tmp;
	t_pack	*start;
	t_pack	*next;

	nb_print = 0;
	start = pack;
	while (pack)
	{
		nb_print++;
		next = pack->nxt;
		print_line_lemin(&tmp, &pack, &start);
		pack = next;
	}
	ft_putchar('\n');
	g_turn++;
	return (start);
}

t_pack	*new_player_in_field(t_pack *start, t_wroad *wroad, int r)
{
	t_pack		*last_teammember;
	t_pack		*new_player;
	t_journey	*player;
	t_road		*road;

	if (!(player = (t_journey*)malloc(sizeof(t_journey))))
		exit(-1);
	while (wroad->nb != r)
		wroad = wroad->next;
	road = wroad->path;
	if (!road->prev->prev)
		road = road->prev;
	else
	{
		while (road->prev->prev)
			road = road->prev;
	}
	player->node = road->current;
	player->wroad = wroad;
	send_player(&start, &new_player, &last_teammember, &player);
	player->bib_nb = g_ants;
	g_ants++;
	return (start);
}

void	push_ants(t_wroad *wroad, int *line, int len)
{
	t_pack	*the_pack;
	int		trap_inside;
	int		r;

	the_pack = NULL;
	trap_inside = 1;
	while (trap_inside)
	{
		r = 0;
		trap_inside = 0;
		while (r < len)
		{
			if (line[r] > 0)
			{
				line[r]--;
				the_pack = new_player_in_field(the_pack, wroad, r);
				trap_inside = 1;
			}
			r++;
		}
		the_pack = print_player(the_pack);
	}
	while (the_pack)
		the_pack = print_player(the_pack);
}

void	get_best_road(int *line, int ants, t_wroad *wroad)
{
	int	len;

	len = ft_wroad_len(wroad);
	line = transform_line(line, ants, len);
	push_ants(wroad, line, len);
	free(line);
	if (g_flags & LINENB)
		ft_printf("\n\e[32;40mNUMBER OF LINES:\033[0m\n%d\n", g_turn);
}
