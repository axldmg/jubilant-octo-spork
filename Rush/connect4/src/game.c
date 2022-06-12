/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschoeff <bschoeff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 12:14:19 by anclarma          #+#    #+#             */
/*   Updated: 2022/06/12 15:43:01 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	eval_all(t_game *grid)
{
	int		i;
	int		j;
	int		res;
	t_pos	p;

	i = 0;
	while (i < grid->lines)
	{
		j = 0;
		while (j < grid->columns)
		{
			p.x = i;
			p.y = j;
			p.player_id = 0;
			res = eval(grid, &p);
			if (res != 0)
				return (res);
			j++;
		}
		i++;
	}
	return (0);
}

static int	grid_full(t_game *grid)
{
	int	i;

	i = 0;
	while (i < grid->columns)
	{
		if (grid->grid[0][i] == 0)
			return (0);
		i++;
	}
	return (1);
}

int	attempt(t_game *g, int columns, int id)
{
	int	i;

	if (columns < g->columns && g->grid[0][columns] == 0)
	{
		i = 0;
		while (i < g->lines - 1 && g->grid[i + 1][columns] == 0)
			i++;
		g->grid[i][columns] = id;
		return (0);
	}
	return (-1);
}

int	game(t_game *g)
{
	int	win;
	int	play_turn;
	int	error;

	srand(time(NULL));
	play_turn = rand() % 2;
	win = 0;
	display_grid(g);
	while (!win && !grid_full(g))
	{
		if (play_turn)
			error = ai_turn(g);
		else
			error = player_turn(g);
		if (error != 0)
			return (-1);
		win = eval_all(g);
		play_turn = !play_turn;
		display_grid(g);
	}
	return (win);
}

void	print_winer(int id)
{
	if (id == 1)
	{
		ft_putstr_fd(GREEN, 1);
		ft_putstr_fd("well done you won\n", 1);
		ft_putstr_fd(RESET, 1);
	}
	else if (id == 2)
	{
		ft_putstr_fd(RED, 1);
		ft_putstr_fd("cheh, the ai has won\n", 1);
		ft_putstr_fd(RESET, 1);
	}
	else if (id == 0)
	{
		ft_putstr_fd(YELLOW, 1);
		ft_putstr_fd("draw\n", 1);
		ft_putstr_fd(RESET, 1);
	}
	else
	{
		ft_putstr_fd(RED, 1);
		ft_putstr_fd("internal error\n", 1);
		ft_putstr_fd(RESET, 1);
	}
}
