/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_roads.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oespion <oespion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 16:30:34 by oespion           #+#    #+#             */
/*   Updated: 2019/04/17 14:07:00 by oespion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

int g_turn = 0;
int g_ants = 1;

void    print_pack(t_pack *player)
{
    while (player)
    {
        ft_printf("player => L%d\n", player->player->bib_nb);
        player = player->nxt;
    }
}

int     *create_base(int len)
{
    int *tmp;
    int r;

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

int		find_r_increase(int *line, int len)
{
	int	r;
	int	after;

	r = 0;
	while (r < len)
	{
		while (line[r] == 0)
			r++;
		after = r + 1;
		while (line[after] == 0 && after < len)
			after++;
		if (line[r] < line[after])
			return (r);
		else
			r++;
	}
	return (r - 1);
}

int     *transform_line(int *line, int ants, int len)
{
	int	r;
	int	*new_line;

	new_line = create_base(len);
	while (ants)
	{
		r = find_r_increase(line, len);
		ants--;
		new_line[r]++;
		line[r]++;
	}
	return (new_line);
}

t_pack  *new_player_in_field(t_pack *start, t_wroad *wroad, int r)
{
    t_pack  *last_teammember;
    t_pack  *new_player;
    t_journey   *player;
    t_road      *road;

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
    if (!start)
    {
        if(!(start = (t_pack*)malloc(sizeof(t_pack))))
            exit(-1);
        start->player = player;
        start->nxt = NULL;
    }
    else
    {
        if (!(new_player = (t_pack*)malloc(sizeof(t_pack))))
            exit(-1);
        last_teammember = start;
        while (last_teammember->nxt)
            last_teammember = last_teammember->nxt;
        last_teammember->nxt = new_player;
        new_player->nxt = NULL;
        new_player->player = player;
    }
    player->bib_nb = g_ants;
    g_ants++;
    return (start);
}

t_pack     *remove_from_field(t_pack *start, t_pack *rm)
{
    t_pack  *tmp;

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

t_pack    *print_player(t_pack *pack, t_wroad *wroad)
{
    t_road  *tmp;
    t_pack  *start;
    t_pack  *next;
    int         nb_print = 0;

    start = pack;
    (void)wroad;
    while (pack)
    {
        nb_print++;
        next = pack->nxt;
        ft_printf("L%d-%s", pack->player->bib_nb, pack->player->node->name);
        if (pack->nxt)
            ft_putchar(' ');
        tmp = pack->player->wroad->path;
        if (tmp->current == pack->player->node)
            start = remove_from_field(start, pack);
        else
        {
            while (tmp->prev->current != pack->player->node)
                tmp = tmp->prev;
            pack->player->node = tmp->current;
        }
        pack = next;
    }
    ft_putchar('\n');
    // ft_printf("nb_print = %d\n", nb_print);
    g_turn++;
    // if (g_turn == 17)
    //     exit(1);
    return (start);
}

int     check_end(t_pack *the_pack)
{
    while (the_pack)
    {
        if (the_pack->player->node != the_pack->player->wroad->path->current)
            return (1);
        the_pack = the_pack->nxt;
    }
    return (0);
}

void    push_ants(t_wroad *wroad, int *line, int len)
{
    t_pack  *the_pack;
    int         trap_inside;
    int         r;

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
                // ft_printf("line[r] = %d\n", line[r]);
                the_pack = new_player_in_field(the_pack, wroad, r);
                // ft_printf("line[r] = %d\n", line[r]);
                trap_inside = 1;
            }
            r++;
        }
        // ft_print_line(line, len);
        the_pack = print_player(the_pack, wroad);
    }
    while (the_pack)
        the_pack = print_player(the_pack, wroad);
}

void    get_best_road(int *line, int ants, int max_roads, t_wroad *wroad)
{
    int len;

    (void)max_roads;
    // ft_printf("wroad %s\n", wroad->path->current->name);
    // exit(34);
    len = ft_wroad_len(wroad);
    // ft_printf("len %d\n", len);
    // ft_print_line(line, len);i plus est, c'est un algorithme maison dont je ne citerai pas le nom ici. J'adore les élève qui se démène pour faire des tests unitaires. ./push_s    
    // ft_printf("test -> %d\n", line[len - 1]);
	line = transform_line(line, ants, len);
    // exit(1);
    push_ants(wroad, line, len);
    // ft_printf("# printed line -> %d\n", g_turn);
    free(line);
    if (g_flags & LINENB)
        ft_printf("\n\e[32;40mNUMBER OF LINES:\033[0m\n%d\n", g_turn);
}