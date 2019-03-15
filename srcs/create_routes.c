/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_routes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avo <avo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 19:28:15 by oespion           #+#    #+#             */
/*   Updated: 2019/03/15 13:35:09 by avo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "lem_in.h"

void		read_current(t_solve *solution)
{
	ft_printf("--current state\n");
	while (solution)
	{
		ft_printf("%s\n", solution->path->current->name);
		solution = solution->next;
	}
	ft_printf("------\n");
}

int         ft_check(t_solve *routes, char *end_name)
{
	t_solve *tmp;

	tmp = routes;
	while (tmp)
	{
		if (tmp->path->current->name == end_name)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int				more_one(t_road *road)
{
	if (road->current->link->next)
		return (1);
	return (0);
}

void			free_solve(t_solve *path)
{
	t_road *tmp;
	t_road	*road;

	road = path->path;
	tmp = road;
	// while (tmp)
	// {
	// 	tmp = road->prev;
	// 	if (road)
	// 		free(road);
	// 	road = tmp;
	// }
	free(path);
}

t_solve		*ft_del_tmp(t_solve *solution, t_solve *tmp)
{
	t_solve *base;
	t_solve	*next_solve;

	base = solution;
	if (base == tmp)
	{
		base = base->next;
		free_solve(solution);
	}
	else
	{
		while (solution->next != tmp)
			solution = solution->next;
		next_solve = solution->next->next;
		free_solve(solution->next);
		solution->next = next_solve;
	}
	return (base);
}

int				ft_check_loop(t_road *road, t_link *link)
{
	while (road)
	{
		if (road->current == link->node)
			return (1);
		road = road->prev;
	}
	return (0);
}

void			ft_create_new_solve(t_solve *solution, t_road *tmp, t_link *link)
{
	t_solve	*new_node;
	t_road	*road;
	t_road	*cpy;
	t_road	*lroad;
	
	while (solution->next)
		solution = solution->next;
	if (!(new_node = (t_solve*)malloc(sizeof(t_solve))))
		exit(-1);
	if (!(road = (t_road*)malloc(sizeof(t_road))))
		exit(-1);
	new_node->path = road;
	road->current = link->node;
	lroad = road;
	while (tmp)
	{
		if (!(cpy = (t_road*)malloc(sizeof(t_road))))
			exit(-1);
		cpy->current = tmp->current;
		lroad->prev = cpy;
		lroad = tmp;
		tmp = tmp->prev;
	}
	cpy->prev = NULL;
	solution->next = new_node;
	new_node->next = NULL;
}

t_solve		*ft_add_solve(t_solve *solution, t_solve *tmp, t_map *map)
{
	t_link	*link;

	link = tmp->path->current->link;
	while (link)
	{
		if (link->node == tmp->path->prev->current)
		{
			link = link->next;
			continue ;
		}
		if (link->node == map->start)
		{
			link = link->next;
			continue ;
		}
		if (ft_check_loop(tmp->path, link))
		{
			link = link->next;
			continue ;
		}
		ft_create_new_solve(solution, tmp->path, link);
		link = link->next;
	}
	// read_current(solution);
	solution = ft_del_tmp(solution, tmp);
	// ft_printf("after\n");
	// read_current(solution);	
	// if (!solution)
	// 	exit(-1);
	return (solution);
}

t_solve		*new_turn(t_solve *solution, t_map *map, t_wroad *wroad, int max_roads)
{
	int		turn;
	t_solve	*tmp;
	t_solve	*end;
	t_solve *tmp_next;

	turn = 0;
	end = solution;
	wroad = found_finish_line(solution, map, wroad);
	if (wroad)
	{
		ft_printf("easy map to configure\n");
		exit(1);
	}
	while (!enough_wroad(wroad, map, solution, max_roads))
	{
		while (end->next)
			end = end->next;
		tmp = solution;
		turn += 1;
		ft_printf("turn : %d\n\n", turn);
		// read_current(solution);	
		if (!solution)
			exit(-1);
		while (tmp != end)
		{
			tmp_next = tmp->next;
			solution = ft_add_solve(solution, tmp, map);
			tmp = tmp_next;
		}
		if (!solution)
			break ;
		solution = ft_add_solve(solution, tmp, map);
		read_current(solution);	
		wroad = found_finish_line(solution, map, wroad);
	}
	print_working_roads(wroad, map);
	wroad = ft_find_conflict(wroad, map);
	ft_create_group(wroad, map, max_roads);
	ft_printf("found solution\n");
	return (solution);
}

t_solve     *create_routes(t_map *map, int max_roads, t_solve * routes)
{
	t_wroad	*wroad;
	wroad = NULL;

	routes = new_turn(routes, map, wroad, max_roads);
	return (routes);
}
