/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschoeff <bschoeff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 07:52:33 by bschoeff          #+#    #+#             */
/*   Updated: 2022/06/16 08:33:03 by bschoeff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	destroy_all(t_mlx *mlx)
{
	mlx_destroy_window(mlx->ptr, mlx->win);
	mlx->win = NULL;
	destroy_img(mlx, 7);
	mlx_destroy_display(mlx->ptr);
	free(mlx->ptr);
	return (0);
}

void	destroy_img(t_mlx *mlx, int n)
{
	if (n > 6)
		mlx_destroy_image(mlx->ptr, mlx->wall);
	if (n > 5)
		mlx_destroy_image(mlx->ptr, mlx->pl_d);
	if (n > 4)
		mlx_destroy_image(mlx->ptr, mlx->pl_a);
	if (n > 3)
		mlx_destroy_image(mlx->ptr, mlx->pl_s);
	if (n > 2)
		mlx_destroy_image(mlx->ptr, mlx->pl_w);
	if (n > 1)
		mlx_destroy_image(mlx->ptr, mlx->exit);
	if (n > 0)
		mlx_destroy_image(mlx->ptr, mlx->coll);
	mlx_destroy_image(mlx->ptr, mlx->bckg);
}

void	image_error(t_mlx *mlx, int n)
{
	destroy_img(mlx, n);
	mlx_destroy_display(mlx->ptr);
}
