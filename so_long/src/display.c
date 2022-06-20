/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschoeff <bschoeff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:49:14 by bschoeff          #+#    #+#             */
/*   Updated: 2022/06/15 15:08:20 by bschoeff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_game(t_mlx *mlx)
{
	int	i;
	int	j;

	i = -1;
	while (++i < mlx->lines)
	{
		j = -1;
		while (++j < mlx->len)
		{
			if (mlx->map[i][j] == '0')
				push_map(mlx);
			if (mlx->map[i][j] == '1')
				push_wall(mlx);
			if (mlx->map[i][j] == 'C')
				push_coll(mlx);
			initialize_exit(mlx, i, j);
			initialize_player(mlx, i, j);
			mlx->x += 50;
		}
		mlx->x = 0;
		mlx->y += 50;
	}
	mlx->y = 0;
}

void	update_game(t_mlx *mlx, char c)
{
	if (c == 'w')
		direction_w(mlx);
	if (c == 'a')
		direction_a(mlx);
	if (c == 's')
		direction_s(mlx);
	if (c == 'd')
		direction_d(mlx);
	initialize_game(mlx);
}

void	initialize_player(t_mlx *mlx, int i, int j)
{
	int	index;

	index = 0;
	while (index < 4 && "PWAS"[index] != mlx->map[i][j])
		index++;
	if (index == 4)
		return ;
	mlx->i = i;
	mlx->j = j;
	if (mlx->map[i][j] == 'P')
		push_player(mlx, 'd');
	if (mlx->map[i][j] == 'W')
		push_player(mlx, 'w');
	if (mlx->map[i][j] == 'A')
		push_player(mlx, 'a');
	if (mlx->map[i][j] == 'S')
		push_player(mlx, 's');
}

void	initialize_exit(t_mlx *mlx, int i, int j)
{
	if (mlx->map[i][j] == 'E' && !mlx->collect)
		push_exit(mlx);
	if (mlx->map[i][j] == 'E' && mlx->collect)
		push_map(mlx);
}
