/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compliance.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschoeff <bschoeff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 08:08:31 by bschoeff          #+#    #+#             */
/*   Updated: 2022/06/16 14:03:14 by bschoeff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	compliances(t_mlx *mlx)
{
	if (!shape_compliance(mlx))
		return (ft_printf("Error\nThe map is not rectangular\n"), 0);
	if (!wall_compliance(mlx))
		return (ft_printf("Error\nThe map is not surrounded by walls\n"), 0);
	if (!items_compliance(mlx))
		return (ft_printf("Error\nNot the right amount of E or C or P\n"), 0);
	if (!content_compliance(mlx))
		return (ft_printf("Error\nForbidden element in the map\n"), 0);
	return (1);
}

int	shape_compliance(t_mlx *mlx)
{
	int		i;
	size_t	len;

	len = ft_strlen(mlx->map[0]);
	i = 1;
	while (mlx->map[i])
	{
		if (ft_strlen(mlx->map[i]) != len)
			return (0);
		i++;
	}
	return (1);
}

int	wall_compliance(t_mlx *mlx)
{
	int		i;
	int		j;
	size_t	len;

	i = 1;
	len = ft_strlen(mlx->map[0]);
	while (mlx->map[i + 1])
	{
		if (mlx->map[i][0] != '1' || mlx->map[i][len - 1] != '1')
			return (0);
		i++;
	}
	j = 0;
	while (mlx->map[0][j])
	{
		if (mlx->map[0][j] != '1' || mlx->map[i][j] != '1')
			return (0);
		j++;
	}
	mlx->len = (int)len;
	return (1);
}

int	items_compliance(t_mlx *mlx)
{
	int		i;
	int		j;

	i = 0;
	while (mlx->map[i])
	{
		j = 0;
		while (mlx->map[i][j])
		{
			if (mlx->map[i][j] == 'C')
				mlx->collect++;
			if (mlx->map[i][j] == 'E')
				mlx->door++;
			if (mlx->map[i][j] == 'P')
				mlx->player++;
			if (mlx->map[i][j] != '0' || mlx->map[i][j] != '1')
			j++;
		}
		i++;
	}
	if (mlx->collect < 1 || mlx->door < 1 || mlx->player != 1)
		return (0);
	return (1);
}

int	content_compliance(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (mlx->map[i])
	{
		j = 0;
		while (mlx->map[i][j])
		{
			if (mlx->map[i][j] != '0' && mlx->map[i][j] != '1'
			&& mlx->map[i][j] != 'P' && mlx->map[i][j] != 'E'
			&& mlx->map[i][j] != 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
