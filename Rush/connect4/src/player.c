/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschoeff <bschoeff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:58:01 by anclarma          #+#    #+#             */
/*   Updated: 2022/06/12 11:56:48 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	player_turn(t_game *g)
{
	int		valid_attempt;
	int		ret_gnl;
	char	*line;

	valid_attempt = -1;
	line = NULL;
	while (valid_attempt == -1)
	{
		ft_putstr_fd("Enter a column: ", 1);
		ret_gnl = get_next_line(0, &line);
		if (ret_gnl == -1)
		{
			ft_putstr_fd("Gnl error\n", 2);
			return (1);
		}
		if (ret_gnl == 0)
			ft_putstr_fd("\n", 1);
		if (compliance(line) && ft_atoi(line) <= g->columns)
			valid_attempt = attempt(g, ft_atoi(line), 1);
		free(line);
		line = NULL;
	}
	return (0);
}
