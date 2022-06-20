/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschoeff <bschoeff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 19:59:11 by bschoeff          #+#    #+#             */
/*   Updated: 2022/06/15 14:54:57 by bschoeff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	direction_w(t_mlx *mlx)
{
	if (mlx->map[mlx->i - 1][mlx->j] == '0'
		|| mlx->map[mlx->i - 1][mlx->j] == 'C'
		|| mlx->map[mlx->i - 1][mlx->j] == 'E')
	{
		if (mlx->c == 'E')
		{
			mlx->map[mlx->i][mlx->j] = 'E';
			mlx->c = '0';
		}
		else
			mlx->map[mlx->i][mlx->j] = '0';
		mlx->i--;
		if (mlx->map[mlx->i][mlx->j] == 'E' && !mlx->collect)
			mlx_loop_end(mlx->ptr);
		if (mlx->map[mlx->i][mlx->j] == 'C')
			mlx->collect--;
		if (mlx->map[mlx->i][mlx->j] == 'E')
			mlx->c = 'E';
		mlx->map[mlx->i][mlx->j] = 'W';
		mlx->counter++;
		ft_printf("%i\n", mlx->counter);
	}
}

void	direction_a(t_mlx *mlx)
{
	if (mlx->map[mlx->i][mlx->j - 1] == '0'
		|| mlx->map[mlx->i][mlx->j - 1] == 'C'
		|| mlx->map[mlx->i][mlx->j - 1] == 'E')
	{
		if (mlx->c == 'E')
		{
			mlx->map[mlx->i][mlx->j] = 'E';
			mlx->c = '0';
		}
		else
			mlx->map[mlx->i][mlx->j] = '0';
		mlx->j--;
		if (mlx->map[mlx->i][mlx->j] == 'E' && !mlx->collect)
			mlx_loop_end(mlx->ptr);
		if (mlx->map[mlx->i][mlx->j] == 'C')
			mlx->collect--;
		if (mlx->map[mlx->i][mlx->j] == 'E')
			mlx->c = 'E';
		mlx->map[mlx->i][mlx->j] = 'A';
		mlx->counter++;
		ft_printf("%i\n", mlx->counter);
	}
}

void	direction_s(t_mlx *mlx)
{
	if (mlx->map[mlx->i + 1][mlx->j] == '0'
		|| mlx->map[mlx->i + 1][mlx->j] == 'C'
		|| mlx->map[mlx->i + 1][mlx->j] == 'E')
	{
		if (mlx->c == 'E')
		{
			mlx->map[mlx->i][mlx->j] = 'E';
			mlx->c = '0';
		}
		else
			mlx->map[mlx->i][mlx->j] = '0';
		mlx->i++;
		if (mlx->map[mlx->i][mlx->j] == 'E' && !mlx->collect)
			mlx_loop_end(mlx->ptr);
		if (mlx->map[mlx->i][mlx->j] == 'C')
			mlx->collect--;
		if (mlx->map[mlx->i][mlx->j] == 'E')
			mlx->c = 'E';
		mlx->map[mlx->i][mlx->j] = 'S';
		mlx->counter++;
		ft_printf("%i\n", mlx->counter);
	}
}

void	direction_d(t_mlx *mlx)
{
	if (mlx->map[mlx->i][mlx->j + 1] == '0'
		|| mlx->map[mlx->i][mlx->j + 1] == 'C'
		|| mlx->map[mlx->i][mlx->j + 1] == 'E')
	{
		if (mlx->c == 'E')
		{
			mlx->map[mlx->i][mlx->j] = 'E';
			mlx->c = '0';
		}
		else
			mlx->map[mlx->i][mlx->j] = '0';
		mlx->j++;
		if (mlx->map[mlx->i][mlx->j] == 'E' && !mlx->collect)
			mlx_loop_end(mlx->ptr);
		if (mlx->map[mlx->i][mlx->j] == 'C')
			mlx->collect--;
		if (mlx->map[mlx->i][mlx->j] == 'E')
			mlx->c = 'E';
		mlx->map[mlx->i][mlx->j] = 'P';
		mlx->counter++;
		ft_printf("%i\n", mlx->counter);
	}
}
