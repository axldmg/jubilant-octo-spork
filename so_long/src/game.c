/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschoeff <bschoeff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 12:10:53 by bschoeff          #+#    #+#             */
/*   Updated: 2022/06/15 11:57:01 by bschoeff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	render(void *mlx)
{
	(void)mlx;
	return (0);
}

int	keyboard_hook(int key, t_mlx *mlx)
{
	if (key == esc)
	{
		mlx_loop_end(mlx->ptr);
		return (1);
	}
	if (key == w || key == a || key == s || key == d)
		update_game(mlx, key);
	return (1);
}

int	ft_game(t_mlx *mlx)
{
	if (!initialize_board(mlx))
		return (ft_printf("Error\nSomething went wrong during board init\n"), 0);
	if (!initialize_image(mlx))
		return (ft_printf("Error\nSomething went wrong during image init\n"), 0);
	if (!initialize_window(mlx))
		return (ft_printf("Error\nSomething went wrong during window init\n"), 0);
	initialize_game(mlx);
	ft_printf("0\n");
	if (!ft_play(mlx))
		destroy_all(mlx);
	return (1);
}

int	ft_play(t_mlx *mlx)
{
	mlx_hook(mlx->win, 2, 1L << 0, &keyboard_hook, mlx);
	mlx_hook(mlx->win, 33, 0, &end_loop, mlx);
	mlx_loop_hook(mlx->ptr, &render, mlx);
	mlx_loop(mlx->ptr);
	return (0);
}

int	end_loop(t_mlx *mlx)
{
	mlx_loop_end(mlx->ptr);
	return (0);
}
