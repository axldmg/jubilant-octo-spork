/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschoeff <bschoeff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 10:13:58 by bschoeff          #+#    #+#             */
/*   Updated: 2022/06/11 15:05:15 by bschoeff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/connect4.h"

int	fill_grid(t_game *game)
{
	int	i;

	i = 0;
	game->grid = malloc(game->lines * sizeof(int *));
	if (!game->grid)
		return (ft_putstr_fd("Malloc went wrong\n", 1), 0);
	while (i < game->lines)
	{
		game->grid[i] = malloc(game->columns * sizeof(int));
		if (!game->grid[i])
		{
			free_grid(game, i);
			return (ft_putstr_fd("Malloc went wrong\n", 1), 0);
		}
		i++;
	}
	return (1);
}

void	free_grid(t_game *game, int i)
{
	int	j;

	j = 0;
	while (j < i)
		free(game->grid[j++]);
	free(game->grid);
}

void	init_grid(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->lines)
	{
		j = 0;
		while (j < game->columns)
		{
			game->grid[i][j] = 0;
			j++;
		}
		i++;
	}
}
