/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschoeff <bschoeff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 11:01:15 by bschoeff          #+#    #+#             */
/*   Updated: 2022/06/15 11:14:54 by bschoeff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	initialize_board(t_mlx *mlx)
{
	mlx->ptr = mlx_init();
	if (!mlx->ptr)
		return (free(mlx->ptr), 0);
	return (1);
}

int	initialize_image(t_mlx *mlx)
{
	mlx->bckg = img(mlx->ptr, "./img/bckg.xpm", &mlx->n, &mlx->n);
	if (!mlx->bckg)
		return (mlx_destroy_display(mlx->ptr), free(mlx->ptr), 0);
	mlx->coll = img(mlx->ptr, "./img/coll.xpm", &mlx->n, &mlx->n);
	if (!mlx->coll)
		return (image_error(mlx, 0), free(mlx->ptr), 0);
	mlx->exit = img(mlx->ptr, "./img/exit.xpm", &mlx->n, &mlx->n);
	if (!mlx->exit)
		return (image_error(mlx, 1), free(mlx->ptr), 0);
	mlx->pl_w = img(mlx->ptr, "./img/pl_w.xpm", &mlx->n, &mlx->n);
	if (!mlx->pl_w)
		return (image_error(mlx, 2), free(mlx->ptr), 0);
	mlx->pl_s = img(mlx->ptr, "./img/pl_s.xpm", &mlx->n, &mlx->n);
	if (!mlx->pl_s)
		return (image_error(mlx, 3), free(mlx->ptr), 0);
	mlx->pl_a = img(mlx->ptr, "./img/pl_a.xpm", &mlx->n, &mlx->n);
	if (!mlx->pl_a)
		return (image_error(mlx, 4), free(mlx->ptr), 0);
	mlx->pl_d = img(mlx->ptr, "./img/pl_d.xpm", &mlx->n, &mlx->n);
	if (!mlx->pl_d)
		return (image_error(mlx, 5), free(mlx->ptr), 0);
	mlx->wall = img(mlx->ptr, "./img/wall.xpm", &mlx->n, &mlx->n);
	if (!mlx->wall)
		return (image_error(mlx, 6), free(mlx->ptr), 0);
	return (1);
}

int	initialize_window(t_mlx *mlx)
{
	mlx->win = mlx_new_window(mlx->ptr, mlx->len * 50, mlx->lines * 50, "Game");
	if (!mlx->win)
		return (destroy_img(mlx, 6), mlx_destroy_display(mlx->ptr),
			free(mlx->ptr), 0);
	return (1);
}

void	*img(void *mlx_ptr, char *filename, int *width, int *height)
{
	return (mlx_xpm_file_to_image(mlx_ptr, filename, width, height));
}
