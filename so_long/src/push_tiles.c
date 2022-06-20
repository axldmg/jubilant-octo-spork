/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_tiles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschoeff <bschoeff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 16:14:05 by bschoeff          #+#    #+#             */
/*   Updated: 2022/06/15 10:59:50 by bschoeff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	push_map(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->bckg, mlx->x, mlx->y);
}

void	push_wall(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->wall, mlx->x, mlx->y);
}

void	push_exit(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->exit, mlx->x, mlx->y);
}

void	push_coll(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->coll, mlx->x, mlx->y);
}

void	push_player(t_mlx *mlx, char c)
{
	if (c == 'd')
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->pl_d, mlx->x, mlx->y);
	if (c == 'w')
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->pl_w, mlx->x, mlx->y);
	if (c == 'a')
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->pl_a, mlx->x, mlx->y);
	if (c == 's')
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->pl_s, mlx->x, mlx->y);
}
