/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschoeff <bschoeff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 09:45:29 by bschoeff          #+#    #+#             */
/*   Updated: 2022/06/12 15:42:34 by anclarma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/connect4.h"
#include "game.h"

int	main(int ac, char **av)
{
	t_game	g;
	int		winer;

	if (ac != 3 || !compliance(av[1]) || !compliance(av[2]))
		return (ft_putstr_fd("Usage: ./connect4 <lines> <columns>\n", 2), 1);
	g.lines = ft_atoi(av[1]);
	g.columns = ft_atoi(av[2]);
	if (g.lines < 6 || g.columns < 7)
		return (ft_putstr_fd("Minimum 6 lines and 7 columns\n", 2), 1);
	if (g.lines > MAX_LINES || g.columns > MAX_COL)
		return (ft_putstr_fd("Maximum size of 1000 lines/columns exceeded\n",
				2), 1);
	if (!fill_grid(&g))
		return (1);
	init_grid(&g);
	winer = game(&g);
	print_winer(winer);
	free_grid(&g, g.lines);
	return (0);
}

int	compliance(char *str)
{
	int	i;

	i = 0;
	if (!str || !ft_strlen(str))
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (!ft_secure_atoi(str))
		return (0);
	return (1);
}
