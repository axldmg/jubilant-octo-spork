/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anclarma <anclarma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:58:01 by anclarma          #+#    #+#             */
/*   Updated: 2022/06/12 15:45:19 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	eval_horizontal(t_game *g, t_pos *p)
{
	if ((0 < p->y && p->y < g->columns - 3
				&& g->grid[p->x][p->y - 1] == 0
				&& g->grid[p->x][p->y + 1] == p->player_id
				&& g->grid[p->x][p->y + 2] == p->player_id
				&& g->grid[p->x][p->y + 3] == 0)
			|| (1 < p->y && p->y < g->columns - 2                                       
				&& g->grid[p->x][p->y - 2] == 0                                     
				&& g->grid[p->x][p->y - 1] == p->player_id                          
				&& g->grid[p->x][p->y + 1] == p->player_id                          
				&& g->grid[p->x][p->y + 2] == 0)
			|| (2 < p->y && p->y < g->columns - 1                                       
				&& g->grid[p->x][p->y - 3] == 0                                     
				&& g->grid[p->x][p->y - 2] == p->player_id                          
				&& g->grid[p->x][p->y - 1] == p->player_id                          
				&& g->grid[p->x][p->y + 1] == 0))
		return (1);
	return (0);
}

int	eval_attempt(t_game *g, int col, int id)
{
	int		line;
	int		res;
	t_pos	p;

	line = 0;
	res = 0;
	if (col >= g->columns || g->grid[0][col] != 0)
		return (0);
	while (line < g->lines - 1 && g->grid[line + 1][col] == 0)
		line++;
	g->grid[line][col] = id;
	if (eval_all(g))
		res = 100;
	g->grid[line][col] = !(id - 1) + 1;
	if (res == 0 && eval_all(g))
		res = 50;
	g->grid[line][col] = 0;
	p.x = line;
	p.y = col;
	p.player_id = id;
	if (res == 0 && eval_horizontal(g, &p))
		res = 30;
	p.player_id = !(id - 1) + 1;
	if (res == 0 && eval_horizontal(g, &p))
		res = 20;
	return (res);
}

int	ai_turn(t_game *g)
#if LEVEL_AI == 0
{
	while (attempt(g, rand() % g->columns, 2) == -1)
		;
	return (0);
}
#elif LEVEL_AI >= 1
{
	int	col;
	int score;
	int best_col;
	int best_score;

	col = 0;
	best_col = -1;
	best_score = -1;
	while (col < g->columns)
	{
		score = eval_attempt(g, col, 2);
		if (score > best_score)
		{
			best_score = score;
			best_col = col;
		}
		col++;
	}
	if (best_score > 0)
		attempt(g, best_col, 2);
	else
	{
		while (attempt(g, rand() % g->columns, 2) == -1)
			;
	}
	return (0);
}
#endif
