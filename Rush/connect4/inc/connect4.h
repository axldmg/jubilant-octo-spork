/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect4.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschoeff <bschoeff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 09:45:50 by bschoeff          #+#    #+#             */
/*   Updated: 2022/06/12 14:00:27 by bschoeff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONNECT4_H
# define CONNECT4_H

# include <stdlib.h>
# include <time.h>
# include <stdio.h>
# include "libft.h"

# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;33m"
# define RESET		"\033[0m"
# define MAX_LINES	1000
# define MAX_COL	1000

typedef struct s_game
{
	int		**grid;
	int		lines;
	int		columns;
}			t_game;

int		fill_grid(t_game *game);
void	free_grid(t_game *game, int i);
void	init_grid(t_game *game);
void	display_grid(t_game *game);
int		compliance(char *str);
void	display_numbers(t_game *game);

#endif
