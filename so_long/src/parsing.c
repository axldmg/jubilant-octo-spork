/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschoeff <bschoeff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:26:22 by bschoeff          #+#    #+#             */
/*   Updated: 2022/06/16 12:02:00 by bschoeff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	parsing(t_mlx *mlx, char *str)
{
	int		fd;

	mlx->lines = counting_lines(str);
	if (mlx->lines == 0)
		return (0);
	mlx->map = malloc((mlx->lines + 1) * sizeof(char *));
	if (!mlx->map)
		return (0);
	mlx->map[mlx->lines] = 0;
	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (free(mlx->map), 0);
	if (!populate_map(mlx, fd))
		return (0);
	return (1);
}

int	populate_map(t_mlx *mlx, int fd)
{
	size_t	len;

	while (mlx->to_free < mlx->lines)
	{
		mlx->map[mlx->to_free] = get_next_line(fd);
		if (!mlx->map[mlx->to_free])
			return (free_array(mlx, mlx->to_free), 0);
		len = ft_strlen(mlx->map[mlx->to_free]);
		mlx->map[mlx->to_free][len - 1] = '\0';
		mlx->to_free++;
	}
	return (1);
}

int	counting_lines(char *str)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(str, O_RDONLY);
	line = NULL;
	if (fd < 0)
		return (0);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		i++;
	}
	return (close(fd), free(line), i);
}

void	free_array(t_mlx *mlx, int i)
{
	while (i)
	{
		free(mlx->map[i]);
		i--;
	}
	free(mlx->map[0]);
	free(mlx->map);
}
