/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschoeff <bschoeff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 08:26:49 by bschoeff          #+#    #+#             */
/*   Updated: 2022/06/16 09:32:38 by bschoeff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_mlx	mlx;

	initialize(&mlx);
	if (ac != 2)
		return (ft_printf("Usage: ./so_long <path_to_map>\n"), 1);
	if (!parsing(&mlx, av[1]))
		return (ft_printf("Error\nUnable to parse the given map\n"), 2);
	if (!compliances(&mlx))
		return (free_array(&mlx, mlx.to_free), 3);
	ft_game(&mlx);
	return (free_array(&mlx, mlx.to_free), 0);
}

void	initialize(t_mlx *mlx)
{
	mlx->to_free = 0;
	mlx->collect = 0;
	mlx->counter = 0;
	mlx->player = 0;
	mlx->door = 0;
	mlx->width = 0;
	mlx->height = 0;
	mlx->x = 0;
	mlx->y = 0;
	mlx->len = 0;
	mlx->lines = 0;
	mlx->i = 0;
	mlx->j = 0;
	mlx->n = 50;
	mlx->c = 'P';
}
