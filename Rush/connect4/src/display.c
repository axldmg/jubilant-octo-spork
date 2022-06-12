/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschoeff <bschoeff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 11:40:53 by bschoeff          #+#    #+#             */
/*   Updated: 2022/06/12 15:27:37 by bschoeff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/connect4.h"

void	display_grid(t_game *game)
{
	int	i;
	int	j;

	display_numbers(game);
	i = 0;
	while (i < game->lines)
	{
		j = 0;
		while (j < game->columns)
		{
			if (game->grid[i][j] == 0)
				ft_putstr_fd("_", 1);
			if (game->grid[i][j] == 1)
				ft_putstr_fd(YELLOW "O", 1);
			if (game->grid[i][j] == 2)
				ft_putstr_fd(RED "X", 1);
			ft_putstr_fd(RESET, 1);
			write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	write(1, "\n", 1);
}

void	display_numbers(t_game *game)
{
	int		i;
	char	*s;
	int		len;
	int		j;
	char	*line;

	if (game->columns > 99)
	{
		line = ft_calloc(game->columns * 2 + 1, 1);
		if (!line)
			return ;
		i = 0;
		line[game->columns * 2] = '\0';
		while (i < 200)
		{
			line[i] = ' ';
			i++;
		}
		ft_putstr_fd(line, 1);
		free(line);
		j = 100;
		while (j < game->columns)
		{
			s = ft_itoa(j);
			if (!s)
				return ;
			len = ft_strlen(s);
			write(1, &s[len - 3], 1);
			write(1, " ", 1);
			free(s);
			j++;
		}
	}
	if (game->columns > 9)
	{
		write(1, "\n", 1);
		ft_putstr_fd("                    ", 1);
		j = 10;
		while (j < game->columns)
		{
			s = ft_itoa(j);
			if (!s)
				return ;
			len = ft_strlen(s);
			write(1, &s[len - 2], 1);
			write(1, " ", 1);
			free(s);
			j++;
		}
	}
	write(1, "\n", 1);
	i = 0;
	while (i < game->columns)
	{
		s = ft_itoa(i);
		if (!s)
			return ;
		len = ft_strlen(s);
		if (i > 9)
		{
			write(1, &s[len - 1], 1);
			write(1, " ", 1);
		}
		else
		{
			ft_putstr_fd(s, 1);
			write(1, " ", 1);
		}
		i++;
		free(s);
	}
	write(1, "\n", 1);
}
