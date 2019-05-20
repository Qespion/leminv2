/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_handle_key.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 18:26:40 by ratin             #+#    #+#             */
/*   Updated: 2019/05/20 18:34:01 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

void	handle_key_2(int key, t_party *party)
{
	if (key == 123)
		party->translate_x -= 10;
	if (key == 125)
		party->translate_y += 10;
	if (key == 126)
		party->translate_y -= 10;
	if (key == 124)
		party->translate_x += 10;
	if (key == 116 && party->g_step < party->nbr_of_step + 1)
	{
		party->mouv = 0;
		party->g_step++;
	}
	if (key == 121 && party->g_step > 1)
	{
		party->mouv = 0;
		party->g_step--;
	}
}

int		handle_key(int key, t_party *party)
{
	if (key == 53)
		quit_visu(party);
	if (key == 49)
	{
		if (party->pause == 0)
			party->pause = 1;
		else
			party->pause = 0;
	}
	if (key == 78 && party->zoom > -42 && party->is_bigmap == 0)
		party->zoom -= 2;
	if (key == 69 && party->is_bigmap == 0)
		party->zoom += 2;
	if (key == 69 && party->is_bigmap == 1 && party->zoom > -59)
		party->zoom--;
	if (key == 78 && party->is_bigmap == 1 && party->zoom < 0)
		party->zoom++;
	handle_key_2(key, party);
	return (1);
}
