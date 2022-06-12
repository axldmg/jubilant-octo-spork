/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschoeff <bschoeff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 12:14:19 by anclarma          #+#    #+#             */
/*   Updated: 2022/06/12 15:42:14 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int	check1(t_game *grid, t_pos *p, int id)
{
	return (p->x < grid->lines - 3
		&& grid->grid[p->x + 1][p->y] == id
		&& grid->grid[p->x + 2][p->y] == id
		&& grid->grid[p->x + 3][p->y] == id);
}

static int	check2(t_game *grid, t_pos *p, int id)
{
	return (p->y < grid->columns - 3
		&& grid->grid[p->x][p->y + 1] == id
		&& grid->grid[p->x][p->y + 2] == id
		&& grid->grid[p->x][p->y + 3] == id);
}

static int	check3(t_game *grid, t_pos *p, int id)
{
	return (p->y < grid->columns - 3
		&& p->x < grid->lines - 3
		&& grid->grid[p->x + 1][p->y + 1] == id
		&& grid->grid[p->x + 2][p->y + 2] == id
		&& grid->grid[p->x + 3][p->y + 3] == id);
}

static int	check4(t_game *grid, t_pos *p, int id)
{
	return (p->y >= 3
		&& p->x < grid->lines - 3
		&& grid->grid[p->x + 1][p->y - 1] == id
		&& grid->grid[p->x + 2][p->y - 2] == id
		&& grid->grid[p->x + 3][p->y - 3] == id);
}

int	eval(t_game *grid, t_pos *p)
{
	int	id;

	id = grid->grid[p->x][p->y];
	if (id == 0)
		id = p->player_id;
	if (id && (check1(grid, p, id) || check2(grid, p, id)
			|| check3(grid, p, id) || check4(grid, p, id)))
		return (id);
	return (0);
}
