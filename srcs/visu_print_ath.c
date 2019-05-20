/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_print_ath.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 20:11:48 by ratin             #+#    #+#             */
/*   Updated: 2019/05/20 20:55:19 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

void	print_info_2(t_party *party)
{
	mlx_string_put(party->mlx.mlx_ptr, party->mlx.win_ptr, 5, 65, NAME
		, "PREV STEP:");
	mlx_string_put(party->mlx.mlx_ptr, party->mlx.win_ptr, 110, 65, NAME
		, "PAGE DOWN");
	mlx_string_put(party->mlx.mlx_ptr, party->mlx.win_ptr, 5, 85, NAME
		, "SPEED UP:");
	mlx_string_put(party->mlx.mlx_ptr, party->mlx.win_ptr, 100, 85, NAME
		, "W");
	mlx_string_put(party->mlx.mlx_ptr, party->mlx.win_ptr, 5, 105, NAME
		, "SPEED DOWN:");
	mlx_string_put(party->mlx.mlx_ptr, party->mlx.win_ptr, 120, 105, NAME
		, "S");
	mlx_string_put(party->mlx.mlx_ptr, party->mlx.win_ptr, 5, 125, NAME
		, "TRANSLATION:");
	mlx_string_put(party->mlx.mlx_ptr, party->mlx.win_ptr, 130, 125, NAME
		, "ARROW");
	mlx_string_put(party->mlx.mlx_ptr, party->mlx.win_ptr, 5, 145, NAME
		, "ZOOM +:");
	mlx_string_put(party->mlx.mlx_ptr, party->mlx.win_ptr, 80, 145, NAME
		, "NUM +");
	mlx_string_put(party->mlx.mlx_ptr, party->mlx.win_ptr, 5, 165, NAME
		, "ZOOM -:");
	mlx_string_put(party->mlx.mlx_ptr, party->mlx.win_ptr, 80, 165, NAME
		, "NUM -");
}

void	print_info(t_party *party)
{
	char	*step;
	char	*t_step;
	char	*speed;

	step = ft_itoa(party->g_step);
	t_step = ft_itoa(party->nbr_of_step);
	speed = ft_itoa(party->speed);
	mlx_string_put(party->mlx.mlx_ptr, party->mlx.win_ptr, 5, 5, NAME, "STEP:");
	mlx_string_put(party->mlx.mlx_ptr, party->mlx.win_ptr, 60, 5, START, step);
	mlx_string_put(party->mlx.mlx_ptr, party->mlx.win_ptr, 72, 5, NAME, "/");
	mlx_string_put(party->mlx.mlx_ptr, party->mlx.win_ptr, 83, 5, START
		, t_step);
	mlx_string_put(party->mlx.mlx_ptr, party->mlx.win_ptr, 100, 5, NAME
		, "SPEED:");
	mlx_string_put(party->mlx.mlx_ptr, party->mlx.win_ptr, 165, 5, START
		, speed);
	mlx_string_put(party->mlx.mlx_ptr, party->mlx.win_ptr, 5, 45, NAME
		, "NEXT STEP:");
	mlx_string_put(party->mlx.mlx_ptr, party->mlx.win_ptr, 110, 45, NAME
		, "PAGE UP");
	print_info_2(party);
	free(step);
	free(t_step);
	free(speed);
}

void	print_ath(t_visu *visu, t_party *party)
{
	add_ant_name(visu, party);
	add_name(visu, party);
	print_info(party);
}
